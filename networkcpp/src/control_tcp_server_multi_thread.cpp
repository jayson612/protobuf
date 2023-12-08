#include <cstring>
#include <iostream>
#include <system_error>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <awesomedata.pb.h>

#define BUFFER_SIZE 1024
#define SW_FLAG 5
#define CUR_FOOT 12

using namespace std;

int main() {
  int server_sockfd, client_sockfd;
  uint16_t PORT = 10000;
  sockaddr_in server_addr, client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  protobuf::AwesomeData vision_foothold;
  protobuf::AwesomeData opt_trajectory_pd;
  protobuf::AwesomeData message_queue_pd;
  protobuf::AwesomeData sw_flag_cur_foot_pd;

  server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sockfd < 0) {
    std::cerr << "Socket error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    std::cerr << "Bind error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }

  if (listen(server_sockfd, 5) < 0) {
    std::cerr << "Listen error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }

  while (true) {
    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd < 0) {
      std::cerr << "Accept error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
      continue;
    }

    pid_t pid = fork();
    if (pid == -1) {
      std::cerr << "Fork error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
      close(client_sockfd);
      continue;
    }

    if (pid == 0) { // Child process
      close(server_sockfd); // Close listening socket in child process
      bool flag = true;
      auto prev_end = std::chrono::high_resolution_clock::now();
      int tcp_ip_messsage_count = 0;
      while (true) {
        tcp_ip_messsage_count++;
        auto start = std::chrono::high_resolution_clock::now();

        char buffer[BUFFER_SIZE] = {0};
        int recv_len = read(client_sockfd, buffer, BUFFER_SIZE);
        if (recv_len <= 0) {
          std::cerr << "Recv error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
          break;
        }

        std::string str_buf(buffer, buffer + recv_len);
        if (message_queue_pd.ParseFromString(str_buf)) {
        // if (vision_foothold.ParseFromString(str_buf)) {
          std::string topic_name = message_queue_pd.somestring();
          if (topic_name == "vision_foothold")
            vision_foothold = message_queue_pd;
          else if (topic_name == "opt_trajectory")
            opt_trajectory_pd = message_queue_pd;

          auto end = std::chrono::high_resolution_clock::now();
          std::chrono::duration<double> consumed_time = end - prev_end;
          if(consumed_time.count() > 1)
          {
            double message_freq = tcp_ip_messsage_count / (consumed_time.count());
            std::cout << "data(" << topic_name << ") from TCP/IP frequency : " << message_freq << "hz" << std::endl;
            std::cout << "========================" << std::endl;
            prev_end = end;
            tcp_ip_messsage_count = 0;
          }
          std::string str = vision_foothold.somestring();
          // std::cout << "String: " << str << std::endl;
          // std::cout << "Array: ";
          // for (int i = 0; i < vision_foothold.somearray_size(); i++) {
          //   std::cout << vision_foothold.somearray(i) << " ";
          // }
          // std::cout << std::endl;


          // TODO: protocol buffer를 사용하도록 수정

          // sw_flag_cur_foot_pd 객체 초기화
          sw_flag_cur_foot_pd.Clear();

          // sw_flag [5], current_foot [12]
          sw_flag_cur_foot_pd.set_somestring("sw_flag = [0:5], current_foot = [5:]");  

          // set awesome data array
          float arr[] { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0, 11.1, 12.2, 13, 14, 15, 16, 17};
          for (uint8_t i = 0; i < (SW_FLAG + CUR_FOOT); i++) {
            sw_flag_cur_foot_pd.add_somearray(arr[i]);
          }

          // sw_flag_cur_foot_pd 객체 직렬화
          std::string serialized_data = sw_flag_cur_foot_pd.SerializeAsString();

          // // 직렬화된 데이터의 크기를 전송
          // uint32_t message_size = serialized_data.size();
          // write(client_sockfd, &message_size, sizeof(message_size));

          if (flag)
          {
            cout << "Start to send data(swing flag, current foot position) using TCP/IP in 500hz" << endl;
            flag = false;
          }
          

          // 직렬화된 데이터를 클라이언트에게 전송
          write(client_sockfd, serialized_data.data(), serialized_data.size());

        
        } else {
          std::cout << "Parse error" << std::endl;
        }
      }

      close(client_sockfd); // Close client socket in child process
      exit(0); // Terminate child process
    } else {
      close(client_sockfd); // Parent process closes client socket
    }
  }

  close(server_sockfd); // Close server socket in parent process
  return 0;
}