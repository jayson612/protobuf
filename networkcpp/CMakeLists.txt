cmake_minimum_required(VERSION 3.10)
project(networkcpp CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(PROTOBUF_DIR ${CMAKE_SOURCE_DIR}/protobuf)

# TCP Client 
add_executable(tcp_client
  src/tcp_client.cpp
)

# TCP Client with Protobuf
add_executable(tcp_client_protobuf
  src/tcp_client_protobuf.cpp
  ${PROTOBUF_DIR}/awesomedata.pb.cc
)
target_include_directories(tcp_client_protobuf
  PUBLIC
    ${PROTOBUF_DIR}
)
target_link_libraries(tcp_client_protobuf
  PUBLIC
    protobuf
    pthread
)

# TCP Client with Protobuf
add_executable(tcp_client_multi_protobuf
  src/tcp_client_multi_protobuf.cpp
  ${PROTOBUF_DIR}/awesomedata.pb.cc
)
target_include_directories(tcp_client_multi_protobuf
  PUBLIC
    ${PROTOBUF_DIR}
)
target_link_libraries(tcp_client_multi_protobuf
  PUBLIC
    protobuf
    pthread
)


# TCP Server
add_executable(tcp_server
  src/tcp_server.cpp
)

# TCP Server with Protobuf
add_executable(tcp_server_protobuf
  src/tcp_server_protobuf.cpp
  ${PROTOBUF_DIR}/awesomedata.pb.cc
)
target_include_directories(tcp_server_protobuf
  PUBLIC
    ${PROTOBUF_DIR}
)
target_link_libraries(tcp_server_protobuf
  PUBLIC
    protobuf
    pthread
)


# UDP Client
add_executable(udp_client
  src/udp_client.cpp
)

# # UDP Client with Protobuf 창준 추가
# add_executable(udp_client_protobuf
#   src/udp_client_protobuf.cpp
#   ${PROTOBUF_DIR}/awesomedata.pb.cc
# )
# target_include_directories(udp_client_protobuf
#   PUBLIC
#     ${PROTOBUF_DIR}
# )
# target_link_libraries(udp_client_protobuf
#   PUBLIC
#     protobuf
#     pthread
# )

# UDP Server
add_executable(udp_server
  src/udp_server.cpp
)

# # UDP Server with Protobuf 창준 추가
# add_executable(udp_server_protobuf
#   src/udp_server_protobuf.cpp
#   ${PROTOBUF_DIR}/awesomedata.pb.cc
# )
# target_include_directories(udp_server_protobuf
#   PUBLIC
#     ${PROTOBUF_DIR}
# )
# target_link_libraries(udp_server_protobuf
#   PUBLIC
#     protobuf
#     pthread
# )