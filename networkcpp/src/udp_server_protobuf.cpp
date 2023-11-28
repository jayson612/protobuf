/*
 *  UDP Server
 */

#include <cstring>
#include <iostream>
#include <system_error>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h> //네트워크 프로그래밍과 관련된 헤더파일
#include <unistd.h>
#include <awesomedata.pb.h> /// 어썸데이터 헤더 파일을 불러온다

int main()
{
  int sockfd {}; //소켓 파일 디스크립터를 나타내는 변수 선언
  uint16_t PORT { 20000 }; // 클라이언트가 연결할 서버의 포트 번호
  sockaddr_in client_addr {}; //클라이언트의 주소 정보를 저장할 구조체 선언
  sockaddr_in server_addr {}; //서버의 주소 정보를 저장할 구조체 선언
  protobuf::AwesomeData awesomedata_pb; ///awesomedata_pb 변수 생성, Protocol Buffers 메시지를 생성하기 위한 용도

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    std::cerr << "Socket error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  }//에러날 시 종료. udp_client.cpp 파일과 같음


  std::memset(&server_addr, 0, sizeof(server_addr)); //구조체 0으로 초기화
  server_addr.sin_family = AF_INET; // 구조체 주소 패밀리를 AF_INET로 설정 
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  //INADDR_ANY를 사용하여 서버가 어떤 네트워크 인터페이스에서든 클라이언트의 연결을 수신할 수 있도록 설정
  // 근데 INADDR_ANY가 뭐지? 모든 네트워크 인터페이스에서 클라이언트의 연결을 수신할 수 있도록 해주는 IP 주소다.

  server_addr.sin_port = htons(PORT);
  //PORT 값을 네트워크 바이트 순서로 변환하여(우변) server_addr 구조체의 sin_port 필드에 저장
  //udp_client.cpp 파일과 같음

  if (bind(sockfd, (sockaddr *)&server_addr, sizeof(server_addr)) < 0) { //소켓을 지정된 포트에 바인딩
    std::cerr << "Bind error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1;
  } //바인딩 실패시 오류 메시지 출력 후 프로그램 종료
  

  std::memset(&client_addr, 0, sizeof(client_addr)); //clinet_addr 구조체를 0으로 초기화
  socklen_t client_addr_len = sizeof(client_addr); //구조체의 크기를 client_addr_len에 저장


  int recv {}; //recvfrom 함수를 통해 받은 바이트 수를 추적하는 데 사용할 변수 선언
  char buffer[64] {}; //클라이언트로부터 받은 메시지를 저장할 버퍼 선언
  while (true) { //클라이언트로부터 계속 메세지를 수신할 무한 루프
    recv = recvfrom(sockfd, buffer, sizeof(buffer), 0, (sockaddr *)&client_addr, &client_addr_len);
    //recvfrom 함수를 사용하여 클라이언트로부터 메시지를 수신
    //recvfrom(소켓 파일 디스크립터, 수신할 데이터를 저장할 버퍼, 버퍼의 크기, 플래그, 클라이언트의 주소 정보를 저장하는 구조체에 대한 포인터, 클라이언트 주소 정보 크기)
    if (recv < 0) { //수신 에러가 발생하면
      std::cout << "recv end" << std::endl;
      break; //에러 메시지 출력후 루프 종료
    }

    std::string str_buf {}; //str_buf라는 string 문자열 선언, 
    for (uint8_t i = 0; i < recv; i++) {
      str_buf += buffer[i]; //수신된 바이너리 데이터를 문자열 str_buf에 저장
    }

    if (awesomedata_pb.ParseFromString(str_buf) == false) {
      std::cout << "parse error" << std::endl;
      // continue;
    } /// 파싱 작업을 수행하고, 파싱 실패시 "parse error" 메시지를 출력

    std::string str = awesomedata_pb.somestring();
    std::cout << "string: " << str << std::endl; ///str을 출력하는 코드

    std::cout << "array: ";
    for (uint8_t i = 0; i < awesomedata_pb.somearray_size(); i++) {
      std::cout << awesomedata_pb.somearray(i) << " ";//array를 출력하는 코드
    }
    std::cout << std::endl; // 빈 줄 출력하는 코드

  }

  close(sockfd);
  return 0;
}
