/*
 *  TCP Client
 */

#include <cstring>
#include <iostream>
#include <system_error>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>
#include <awesomedata.pb.h>
#include <thread>
#include <chrono>

#define BUFFER_SIZE 1024

#define TCP_PORT 10000
#define UDP_PORT 20000
#define OPT_TRAJECTORY 96

std::mutex cout_mutex;

void tcp_communication(const char* server_ip, uint16_t port) {
  int sockfd {};
  const char *SERVER_IP { "127.0.0.1" };
  uint16_t PORT { TCP_PORT };
  sockaddr_in server_addr {};
  timespec TS_SEC_1 { .tv_sec = 0, .tv_nsec = 1850000 };
  protobuf::AwesomeData vision_foothold;
  protobuf::AwesomeData sw_flag_cur_foot_pd;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    std::cerr << "Socket error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return ;
  }
  std::memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
  server_addr.sin_port = htons(PORT);

  if (connect(sockfd, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    std::cerr << "Connect error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return ;
  }


  /*
  
  opt_trajectory[96] -> vision_foothold 넣기
  
  */

 vision_foothold.set_somestring("vision_foothold");

  for (uint8_t i = 0; i < OPT_TRAJECTORY; i++) {
   vision_foothold.add_somearray(i);
  }

  /*
  
  
  
  */

  std::string string_buffer {};
  vision_foothold.SerializeToString(&string_buffer);

  uint8_t *char_buffer = new uint8_t[string_buffer.size() + 1];
  std::copy(string_buffer.begin(), string_buffer.end(), char_buffer);
  char_buffer[string_buffer.size()] = '\0';

  auto prev_end = std::chrono::high_resolution_clock::now();
  int tcp_ip_messsage_count = 0;

  int sent {};
  while (true) {
    tcp_ip_messsage_count++;
    auto start = std::chrono::high_resolution_clock::now();
    sent = write(sockfd, char_buffer, vision_foothold.ByteSizeLong());
    nanosleep(&TS_SEC_1, nullptr);

    // 서버로부터 protobuf 메시지 크기를 먼저 받기
    int message_size;
    // int len = read(sockfd, &message_size, 4);
    // if (len <= 0) {
    //   std::cerr << "Read error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    //   break;
    // }
    message_size = 108;
    // 메시지 크기만큼 데이터를 받기
    char* message_buffer = new char[message_size];
    int len = read(sockfd, message_buffer, message_size);
    if (len <= 0) {
      std::cerr << "Read error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
      delete[] message_buffer;
      break;
    }

    // sw_flag_cur_foot_pd의 기존 데이터를 지우기
    sw_flag_cur_foot_pd.Clear();

    // 받은 데이터를 protobuf 메시지로 파싱
    if (!sw_flag_cur_foot_pd.ParseFromArray(message_buffer, message_size)) {
      std::cerr << "Failed to parse protobuf message" << std::endl;
      delete[] message_buffer;
      continue;
    }

    // 받은 데이터를 처리
    // std::cout << "Received String: " << sw_flag_cur_foot_pd.somestring() << std::endl;
    // std::cout << "Received Array: ";
    // for (int i = 0; i < sw_flag_cur_foot_pd.somearray_size(); i++) {
    //   std::cout << sw_flag_cur_foot_pd.somearray(i) << " ";
    // }
    // std::cout << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> consumed_time = end - prev_end;
    // std::cout << consumed_time.count() << std::endl;
    if(consumed_time.count() > 1)
    {
      double message_freq = tcp_ip_messsage_count / (consumed_time.count());
      cout_mutex.lock();
      std::cout << "data from TCP/IP frequency : " << message_freq << "hz" << std::endl;
      std::cout << "========================" << std::endl;
      prev_end = end;
      tcp_ip_messsage_count = 0;
      cout_mutex.unlock();
    }
    // std::cout << "consumed_time : " << consumed_time.count()*1000 << "mili-second..." << std::endl;

    delete[] message_buffer;
  }

  delete[] char_buffer; //동적으로 할당된 메모리를 해제
  close(sockfd); //소켓 닫기
  
}

void udp_communication(const char* server_ip, uint16_t port) {
  int sockfd {}; 
  const char *SERVER_IP { "127.0.0.1" }; 
  uint16_t PORT { port }; 
  sockaddr_in server_addr {}; 
  timespec TS_SEC_1 { .tv_sec = 0, .tv_nsec = 1850000 }; 
  protobuf::AwesomeData awesomedata; 

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { 
    std::cerr << "Socket error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return; 
  }

  std::memset(&server_addr, 0, sizeof(server_addr)); 
  server_addr.sin_family = AF_INET; 

  server_addr.sin_addr.s_addr = inet_addr(SERVER_IP); 
  server_addr.sin_port = htons(PORT);
  socklen_t server_addr_len = sizeof(server_addr); 

 awesomedata.set_somestring("UDP message");
  // 데이터 추가
  // ...

  std::string string_buffer {};
 awesomedata.SerializeToString(&string_buffer);
  uint8_t *char_buffer = reinterpret_cast<uint8_t*>(const_cast<char*>(string_buffer.data()));
  auto prev_end = std::chrono::high_resolution_clock::now();
  int udp_messsage_count = 0;
  while (true) {
    udp_messsage_count++;
    auto start = std::chrono::high_resolution_clock::now();

    // 서버로 데이터 전송
    if (sendto(sockfd, char_buffer, string_buffer.size(), 0, (sockaddr *)&server_addr, server_addr_len) < 0) {
      std::cerr << "Send error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
      break;
    }
    
    // nanosleep(&TS_SEC_1, nullptr);
   
  // 서버로 데이터 전송
    if (sendto(sockfd, char_buffer, string_buffer.size(), 0, (sockaddr *)&server_addr, server_addr_len) < 0) {
      std::cerr << "Send error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
      break;
    }

    nanosleep(&TS_SEC_1, nullptr);

    // 서버로부터 데이터 수신
    char recv_buffer[BUFFER_SIZE];
    std::memset(recv_buffer, 0, BUFFER_SIZE);
    int len = recvfrom(sockfd, recv_buffer, BUFFER_SIZE, 0, (sockaddr *)&server_addr, &server_addr_len);

    if (len > 0) {
        // 수신된 데이터를 protobuf 메시지로 파싱
        protobuf::AwesomeData pose_joint_norminal_pd;
        if (pose_joint_norminal_pd.ParseFromArray(recv_buffer, len)) {
            // // 수신된 데이터 처리
            // std::cout << "Received String: " << pose_joint_norminal_pd.somestring() << std::endl;
            // std::cout << "Received Array: ";
            // for (int i = 0; i < pose_joint_norminal_pd.somearray_size(); i++) {
            //     std::cout << pose_joint_norminal_pd.somearray(i) << " ";
            // }
            // std::cout << std::endl;
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> consumed_time = end - prev_end;
            if(consumed_time.count() > 1)
            {
              double message_freq = udp_messsage_count / (consumed_time.count());
              cout_mutex.lock();
              std::cout << "data from UDP frequency : " << message_freq << "hz" << std::endl;
              std::cout << "========================" << std::endl;
              prev_end = end;
              udp_messsage_count = 0;
              cout_mutex.unlock();
            }
            continue;
        } else {
            std::cerr << "Failed to parse protobuf message" << std::endl;
        }
    } else if (len < 0) {
        std::cerr << "Recv error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    }
  }
  close(sockfd); //소켓 닫기
}


int main()
{
  std::thread tcp_thread(tcp_communication, "127.0.0.1", TCP_PORT);
  std::thread udp_thread(udp_communication, "127.0.0.1", UDP_PORT);

  tcp_thread.join();
  udp_thread.join();

  return 0;
}