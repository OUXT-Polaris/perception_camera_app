cmake_minimum_required(VERSION 3.5)
project(perception_camera_app)

find_package(OpenCV REQUIRED)
include(FindProtobuf REQUIRED)

set(PROTO_FILES
  "proto/perception_camera_app.proto"
)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

add_executable(perception_camera_app
  src/publisher.cpp
  src/subscriber.cpp
  src/conversion.cpp
  src/main.cpp
  ${PROTO_SRCS}
)

target_include_directories(perception_camera_app PUBLIC ${CMAKE_BINARY_DIR} ${OpenCV_INCLUDE_DIRS} include)
target_link_libraries(perception_camera_app ${OpenCV_LIBS} ${PROTOBUF_LIBRARY} zmq zmqpp)
