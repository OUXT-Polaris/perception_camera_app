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
#include <thread>

namespace perception_camera_app {
class ImageAcquisition {
public:
  explicit ImageAcquisition(uint32_t width, uint32_t height,
                            uint32_t frame_rate);
  const uint32_t width;
  const uint32_t height;
  const uint32_t frame_rate;
  const double capture_duration;

private:
  std::string getGstreamerPipeline() const;
  void open();
  void capture();
  std::shared_ptr<cv::VideoCapture> capture_;
};
} // namespace perception_camera_app

#endif // _PERCEPTION_CAMERA_APP__IMAGE_ACQUISION__IMAGE_ACQUISION_HPP_