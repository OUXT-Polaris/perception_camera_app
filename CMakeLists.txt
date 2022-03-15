cmake_minimum_required(VERSION 3.5)
project(perception_camera_app)

find_package(OpenCV REQUIRED)
include(FindProtobuf REQUIRED)

set(PROTO_FILES
  "proto/perception_camera_app.proto"
)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

set(CMAKE_CXX_FLAGS "-O2 -std=c++17 -Wall")

add_library(perception_app_base SHARED
  src/subscriber.cpp
  src/conversion.cpp
  src/endpoint.cpp
  ${PROTO_SRCS}
)

target_include_directories(perception_app_base PUBLIC ${CMAKE_BINARY_DIR} ${OpenCV_INCLUDE_DIRS} include)
target_link_libraries(perception_app_base ${OpenCV_LIBS} ${PROTOBUF_LIBRARY} zmq zmqpp)

add_executable(image_acquisition
  src/image_acquisition/main.cpp
  src/image_acquisition/image_acquisition.cpp
)

target_include_directories(image_acquisition PUBLIC ${CMAKE_BINARY_DIR} ${OpenCV_INCLUDE_DIRS} include)
target_link_libraries(image_acquisition ${OpenCV_LIBS} ${PROTOBUF_LIBRARY} zmq zmqpp perception_app_base)