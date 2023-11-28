/*
 *  UDP Client
 */

#include <cstring>      //문자열 라이브러리
#include <iostream>     //표준 입출력 라이브러리
#include <system_error> // 시스테 오류 및 에러 처리 라이브러리
#include <sys/socket.h> // 소켓 프로그래밍 라이브러리
#include <arpa/inet.h>  // 인터넷 주소(ip 주소)와 포트 번호를 다룰 때
#include <time.h>       // 시간 및 날짜 관련 라이브러리
#include <unistd.h>     // 유닉스 표준 라이브러리, 여기서는 close 함수를 쓰는 데 사용
#include <awesomedata.pb.h> ///어썸데이터 헤더 파일을 불러온다

int main()
{
  //통신에 사용할 변수 선언
  int sockfd {}; //소켓 파일 디스크립터를 나타내는 변수 선언
  const char *SERVER_IP { "127.0.0.1" }; //클라이언트가 연결할 서버의 ip 주소
  uint16_t PORT { 20000 }; // 클라이언트가 연결할 서버의 포트 번호, uint는 "부호 없는 정수"를 의미하며, 16은 비트 수
  sockaddr_in server_addr {}; // 서버의 주소 정보를 저장하는 데 사용할 구조체 선언
  timespec TS_SEC_1 { .tv_sec = 1, .tv_nsec = 0 }; //구조체인 TS_SEC_1을 선언하고 1초의 시간을 나타내도록 초기화
//소켓은 전송 계층과 응용 프로그램 사이의 인터페이스 역할을 하며 떨어져 있는 두 호스트를 연결해준다.
  protobuf::AwesomeData awesomedata_pb; ///awesomedata_pb 변수 생성, Protocol Buffers 메시지를 생성하기 위한 용도  

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { //: 소켓을 생성하고 생성된 소켓의 파일 디스크립터를 sockfd에 할당
    std::cerr << "Socket error: " << std::system_error(errno, std::generic_category()).what() << std::endl;
    return -1; //만약 소켓 생성 실패시 오류 메시지 출력후 프로그램 종료
  }
  std::memset(&server_addr, 0, sizeof(server_addr)); //server_addr 구조체를 0으로 초기화
  server_addr.sin_family = AF_INET; // server_addr구조체의 주소 패밀리를 AF_INET로 설정( IPv4 주소 체계를 사용하겠다)
  //AF_INET는 Address Family Internet"의 약어로, 인터넷 주소 체계를 가리키는 상수입니다. 이 상수는 주로 네트워크 프로그래밍에서 사용되며, IPv4 주소 체계를 나타내는데 사용됩니다.
  // IPv4 (Internet Protocol version 4)는 현재 널리 사용되고 있는 인터넷 프로토콜의 이전 버전 중 하나입니다. 

  server_addr.sin_addr.s_addr = inet_addr(SERVER_IP); 
  // SERVER_IP 값을 서버의 IP 주소로 변환한 것(우변)을 server_addr 구조체의 sin_addr.s_addr 필드에 저장
  server_addr.sin_port = htons(PORT);
  //htons 함수 : "Host to Network Short"의 약어로, 호스트 바이트 순서에서 네트워크 바이트 순서로 16비트 정수를 변환하는 함수
  //PORT 값을 네트워크 바이트 순서로 변환하여(우변) server_addr 구조체의 sin_port 필드에 저장
  socklen_t server_addr_len = sizeof(server_addr); //구조체의 크기를 server_addr_len에 저장

  awesomedata_pb.set_somestring("awesome string!");

  float arr[] { 1.1, 1.5, 2.3, 100.4 };
  for (uint8_t i = 0; i < 4; i++) {
    awesomedata_pb.add_somearray(arr[i]); //awesomedata에 array를 더한다?
  }

  // std::string string_buffer = awesomedata_pb.SerializeAsString();
  std::string string_buffer {}; //빈 문자열 string_buffer를 선언
  awesomedata_pb.SerializeToString(&string_buffer); //Protocol Buffers 메시지를 직렬화하여 string_buffer에 저장

  // std::cout << string_buffer << std::endl;

  uint8_t *char_buffer = new uint8_t[string_buffer.size() + 1];
  // char* char_buffer = new char[string_buffer.size() + 1];
  //문자열 버퍼를 생성하고, 직렬화된 문자열을 복사하기 위한 char_buffer를 할당
  std::copy(string_buffer.begin(), string_buffer.end(), char_buffer); //직렬화된 문자열을 char_buffer로 복사
  char_buffer[string_buffer.size()] = '\0'; //끝부분에 null 추가  
  
  int sent {}; //변수는 sendto 함수를 통해 보낸 바이트 수를 추적하는 데 사용할 변수 선언
  
  while (true) {//클라이언트가 계속해서 서버로 메시지를 전송하는 역할을 하는 무한루프 시작 
    sent = sendto(sockfd, char_buffer, awesomedata_pb.ByteSizeLong(), 0, (sockaddr *)&server_addr, sizeof(server_addr));
    //sendto 함수를 사용하여 서버에 메시지를 전송
    //sendto(소켓 파일 디스크립터, 전송할 데이터, 데이터의 길이, 플래그, 서버의 주소를 가릐는 포인터, 주소 정보의 크기)
    nanosleep(&TS_SEC_1, nullptr); // 1초 동안 프로그램을 일시 중단
    // 클라이언트가 일정한 간격으로 메시지를 전송하기 위한 딜레이 역할
  
    if (awesomedata_pb.ParseFromString(string_buffer) == false) {
      std::cout << "parse error" << std::endl; //파싱 실패시 오류 출력
    }
    std::string str = awesomedata_pb.somestring();
    std::cout << "string: " << str << std::endl; //str 표시

    std::cout << "array: ";
    for (uint8_t i = 0; i < awesomedata_pb.somearray_size(); i++) {
      std::cout << awesomedata_pb.somearray(i) << " "; //array 값 표시
    }
    std::cout << std::endl;
  }

  delete[] char_buffer; //동적으로 할당된 메모리를 해제
  close(sockfd); //소켓 닫기
  return 0;
}
