#ifndef _PERCEPTION_CAMERA_APP__IMAGE_ACQUISION__IMAGE_ACQUISION_HPP_
#define _PERCEPTION_CAMERA_APP__IMAGE_ACQUISION__IMAGE_ACQUISION_HPP_

// simple_camera.cpp
// MIT License
// Copyright (c) 2019-2022 JetsonHacks
// See LICENSE for OpenCV license and additional information
// Using a CSI camera (such as the Raspberry Pi Version 2) connected to a
// NVIDIA Jetson Nano Developer Kit using OpenCV
// Drivers for the camera and OpenCV are included in the base image

#include <chrono>
#include <memory>
#include <opencv2/opencv.hpp>
#include <publisher.hpp>
#include <thread>

namespace perception_camera_app {
class ImageAcquisition {
public:
  explicit ImageAcquisition(const zmqpp::context &context,
                            uint32_t width = 1280, uint32_t height = 720,
                            uint32_t frame_rate = 30);
  void capture();
  const uint32_t width;
  const uint32_t height;
  const uint32_t frame_rate;
  const double capture_duration;

private:
  std::string getGstreamerPipeline() const;
  void open();
  std::shared_ptr<cv::VideoCapture> capture_;
  perception_camera_app::Publisher<perception_camera_app::ImageStamped>
      publisher_;
};
} // namespace perception_camera_app

#endif // _PERCEPTION_CAMERA_APP__IMAGE_ACQUISION__IMAGE_ACQUISION_HPP_