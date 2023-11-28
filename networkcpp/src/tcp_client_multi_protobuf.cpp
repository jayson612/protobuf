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

#define NUM_MESSAGE 2

using namespace std;

int main()
{
  int sockfd[NUM_MESSAGE] ={0, };
  const char *SERVER_IP { "192.168.0.71" };
  uint16_t PORT[NUM_MESSAGE] { 10000, 20000 };
  sockaddr_in server_addr[2] {0, };
  timespec TS_SEC_1 { .tv_sec = 1, .tv_nsec = 0 };
  protobuf::AwesomeData awesomedata_pb[2];
  for(int i = 0; i< NUM_MESSAGE; i++){
    if ((sockfd[i] = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      std::cerr << "Socket error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
      return -1;
    }
  }

  std::memset(server_addr, 0, sizeof(server_addr));
  
  for(int i = 0; i< NUM_MESSAGE; i++){
    server_addr[i].sin_family = AF_INET;
    server_addr[i].sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr[i].sin_port = htons(PORT[i]);
  }
  for(int i = 0; i< NUM_MESSAGE; i++){
    if (connect(sockfd[i], (sockaddr *)&server_addr[i], sizeof(server_addr[i])) < 0) {
      std::cerr << "Connect error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
      return -1;
    }
  }

  awesomedata_pb[0].set_somestring("awesome string!");
  awesomedata_pb[1].set_somestring("fuck you");

  float arr[] { 1.1, 1.5, 2.3, 100.4 };
  for (uint8_t i = 0; i < 4; i++) {
    awesomedata_pb[0].add_somearray(arr[i]);
    awesomedata_pb[1].add_somearray(arr[i]);
  }

  // std::string string_buffer = awesomedata_pb.SerializeAsString();
  std::string string_buffer1, string_buffer2;
  awesomedata_pb[0].SerializeToString(&string_buffer1);
  awesomedata_pb[1].SerializeToString(&string_buffer2);

  uint8_t *char_buffer1 = new uint8_t[string_buffer1.size() + 1], *char_buffer2 = new uint8_t[string_buffer2.size() + 1];
  std::copy(string_buffer1.begin(), string_buffer1.end(), char_buffer1);
  std::copy(string_buffer2.begin(), string_buffer2.end(), char_buffer2);
  char_buffer1[string_buffer1.size()] = '\0';
  char_buffer2[string_buffer2.size()] = '\0';

  int sent {};
  while (true) {
    sent = write(sockfd[0], char_buffer1, awesomedata_pb[0].ByteSizeLong());
    sent = write(sockfd[1], char_buffer2, awesomedata_pb[1].ByteSizeLong());

    
    nanosleep(&TS_SEC_1, nullptr);

    // if (awesomedata_pb.ParseFromString(string_buffer) == false) {
    //   std::cout << "parse error" << std::endl;
    // }
    // std::string str = awesomedata_pb.somestring();
    // std::cout << "string: " << str << std::endl;

    // std::cout << "array: ";
    // for (uint8_t i = 0; i < awesomedata_pb.somearray_size(); i++) {
    //   std::cout << awesomedata_pb.somearray(i) << " ";
    // }
    std::cout << std::endl;
  }

  delete[] char_buffer1, char_buffer2;
  close(sockfd[0]);
  close(sockfd[1]);
  return 0;
}
