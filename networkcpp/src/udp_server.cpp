/*
 *  UDP Server
 */

#include <cstring>
#include <iostream>
#include <system_error>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
  
  int sockfd {};
  uint16_t PORT { 20000 };
  sockaddr_in client_addr {};
  sockaddr_in server_addr {};

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    std::cerr << "Socket error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }
  std::memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  if (bind(sockfd, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    std::cerr << "Bind error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }
  
  std::memset(&client_addr, 0, sizeof(client_addr));
  socklen_t client_addr_len = sizeof(client_addr);

  int recv {};
  char buffer[64] {};
  while (true) {
    recv = recvfrom(sockfd, buffer, sizeof(buffer), 0, (sockaddr *)&client_addr, &client_addr_len);
    if (recv < 0) {
      std::cout << "recv end" << std::endl;
      break;
    }

    buffer[recv] = '\0';
    std::cout << buffer << std::endl;
  }

  close(sockfd);
  return 0;
}
