/*
 *  UDP Client
 */

#include <cstring>
#include <iostream>
#include <system_error>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

int main()
{
  int sockfd {};
  const char *SERVER_IP { "127.0.0.1" };
  uint16_t PORT { 20000 };
  sockaddr_in server_addr {};
  timespec TS_SEC_1 { .tv_sec = 1, .tv_nsec = 0 };

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    std::cerr << "Socket error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }
  std::memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
  server_addr.sin_port = htons(PORT);
  socklen_t server_addr_len = sizeof(server_addr);

  char message[] {"awesome data!"};
  int sent {};
  while (true) {
    sent = sendto(sockfd, message, strlen(message), 0, (sockaddr *)&server_addr, sizeof(server_addr));
    nanosleep(&TS_SEC_1, nullptr);
  }

  close(sockfd);
  return 0;
}
