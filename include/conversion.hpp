#ifndef _PERCEPTION_CAMERA_APP__CONVERSION_HPP_
#define _PERCEPTION_CAMERA_APP__CONVERSION_HPP_

#include <opencv2/opencv.hpp>
#include <perception_camera_app.pb.h>

namespace perception_camera_app {
cv::Mat convert(const perception_camera_app::Image &image) {
  if (image.format() == perception_camera_app::ImageFormat::CV8U) {
    std::vector<char> bytes(image.data().begin(), image.data().end());
    return cv::Mat(image.height(), image.width(), CV_8U, &bytes[0]);
  }
  if (image.format() == perception_camera_app::ImageFormat::CV8UC1) {
    std::vector<char> bytes(image.data().begin(), image.data().end());
    return cv::Mat(image.height(), image.width(), CV_8UC1, &bytes[0]);
  }
  if (image.format() == perception_camera_app::ImageFormat::CV8UC2) {
    std::vector<char> bytes(image.data().begin(), image.data().end());
    return cv::Mat(image.height(), image.width(), CV_8UC2, &bytes[0]);
  }
  if (image.format() == perception_camera_app::ImageFormat::CV8UC3) {
    std::vector<char> bytes(image.data().begin(), image.data().end());
    return cv::Mat(image.height(), image.width(), CV_8UC3, &bytes[0]);
  }
  if (image.format() == perception_camera_app::ImageFormat::CV8UC4) {
    std::vector<char> bytes(image.data().begin(), image.data().end());
    return cv::Mat(image.height(), image.width(), CV_8UC4, &bytes[0]);
  }
  throw std::runtime_error("unsupported image format!!");
}
} // namespace perception_camera_app

#endif // _PERCEPTION_CAMERA_APP__CONVERSION_HPP_