cmake_minimum_required(VERSION 3.5)
project(perception_camera_app)

find_package(OpenCV REQUIRED)
add_executable(perception_camera_app
  src/buffer.cpp
  src/component.cpp
  src/main.cpp
)

target_include_directories(perception_camera_app PUBLIC ${OpenCV_INCLUDE_DIRS} include)
target_link_libraries(perception_camera_app ${OpenCV_LIBS})
