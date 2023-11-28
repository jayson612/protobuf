/*
 *  TCP Server
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
  int client_sockfd {};
  int server_sockfd {};
  uint16_t PORT { 10000 };
  sockaddr_in client_addr {};
  sockaddr_in server_addr {};

  if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    std::cerr << "Socket error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
  }
  std::memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  if (bind(server_sockfd, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    std::cerr << "Bind error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }

  if (listen(server_sockfd, 5) < 0) {
    std::cerr << "Listen error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }
  std::memset(&client_addr, 0, sizeof(client_addr));
  socklen_t client_addr_len = sizeof(client_addr);
  client_sockfd = accept(server_sockfd, (sockaddr *)&client_addr, &client_addr_len);
  if (client_sockfd == -1) {
    std::cerr << "Client socketfd error" << std::endl;
    return -1;
  }

  int recv {};
  char buffer[64] {};
  while (true) {
    recv = read(client_sockfd, buffer, sizeof(buffer));
    if (recv <= 0) {
      std::cerr << "Recv error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
      break;
    }

    buffer[recv] = '\0';
    std::cout << buffer << std::endl;
  }

  close(server_sockfd);
  return 0;
}
