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


int main()
{
  int sockfd {};
  const char *SERVER_IP { "127.0.0.1" };
  uint16_t PORT { 10000 };
  sockaddr_in server_addr {};
  timespec TS_SEC_1 { .tv_sec = 1, .tv_nsec = 0 };
  protobuf::AwesomeData awesomedata_pb;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    std::cerr << "Socket error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }
  std::memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
  server_addr.sin_port = htons(PORT);

  if (connect(sockfd, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    std::cerr << "Connect error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }

  awesomedata_pb.set_somestring("awesome string!");

  float arr[] { 1.1, 1.5, 2.3, 100.4 };
  for (uint8_t i = 0; i < 4; i++) {
    awesomedata_pb.add_somearray(arr[i]);
  }

  // std::string string_buffer = awesomedata_pb.SerializeAsString();
  std::string string_buffer {};
  awesomedata_pb.SerializeToString(&string_buffer);

  uint8_t *char_buffer = new uint8_t[string_buffer.size() + 1];
  std::copy(string_buffer.begin(), string_buffer.end(), char_buffer);
  char_buffer[string_buffer.size()] = '\0';

  int sent {};
  while (true) {
    sent = write(sockfd, char_buffer, awesomedata_pb.ByteSizeLong());
    nanosleep(&TS_SEC_1, nullptr);

    if (awesomedata_pb.ParseFromString(string_buffer) == false) {
      std::cout << "parse error" << std::endl;
    }
    std::string str = awesomedata_pb.somestring();
    std::cout << "string: " << str << std::endl;

    std::cout << "array: ";
    for (uint8_t i = 0; i < awesomedata_pb.somearray_size(); i++) {
      std::cout << awesomedata_pb.somearray(i) << " ";
    }
    std::cout << std::endl;
  }

  delete[] char_buffer;
  close(sockfd);
  return 0;
}
