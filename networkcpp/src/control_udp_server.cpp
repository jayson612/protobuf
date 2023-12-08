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
#include <awesomedata.pb.h> 

#define POSE 7
#define NOMINAL 12
#define JOINT 12
using namespace std;
int main()
{
  int client_sockfd {};
  int server_sockfd {};
  uint16_t PORT { 20000 }; 
  sockaddr_in client_addr {}; 
  sockaddr_in server_addr {};
  protobuf::AwesomeData pose_joint_nominal_pd; 

  if ((server_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    std::cerr << "Socket error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }


  std::memset(&server_addr, 0, sizeof(server_addr)); 
  server_addr.sin_family = AF_INET;  
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);
  
  if (bind(server_sockfd, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    std::cerr << "Bind error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  } 

  std::memset(&client_addr, 0, sizeof(client_addr)); 
  socklen_t client_addr_len = sizeof(client_addr);

  int recv {};
  char buffer[64] {};
  bool flag = true;
  while (true) { 
    int recv = recvfrom(server_sockfd, buffer, sizeof(buffer), 0, (sockaddr *)&client_addr, &client_addr_len);
    if (recv < 0) {
      std::cerr << "Receive error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
      continue;
    }

    // TODO: protocol buffer를 사용하도록 수정

    // pose_joint_nominal_pd 객체 초기화
    pose_joint_nominal_pd.Clear();

    // pose_joint_nominal_pd 객체에 데이터 채우기
    pose_joint_nominal_pd.set_somestring("pose = [:7], joint = [7:19], nominal = [19:]");  

    // set awesome data array
    for (uint8_t i = 0; i < (POSE + NOMINAL + JOINT); i++) {
      pose_joint_nominal_pd.add_somearray(i);
    }

    // pose_joint_nominal_pd 객체 직렬화
    std::string serialized_data = pose_joint_nominal_pd.SerializeAsString();

    if (flag)
    {
      cout << "Start to send data(robot pose, joint value, nominal foot position) using UDP in 500hz" << endl;
      flag = false;
    }

    // 직렬화된 데이터를 클라이언트에게 전송
    if (sendto(server_sockfd, serialized_data.data(), serialized_data.size(), 0, (sockaddr *)&client_addr, client_addr_len) < 0) {
      std::cerr << "Send error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    }

  }

  close(client_sockfd);
  close(server_sockfd);
  return 0;
}
