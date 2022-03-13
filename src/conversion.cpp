#include <conversion.hpp>

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

perception_camera_app::Image convert(const cv::Mat &image) {
  if (image.type() == CV_8U) {
    perception_camera_app::Image proto;
    proto.set_height(image.size().height);
    proto.set_width(image.size().width);
    proto.set_format(perception_camera_app::ImageFormat::CV8U);
    int size = image.size().height * image.size().width;
    proto.set_data(reinterpret_cast<char const *>(image.data), size);
    return proto;
  }
  if (image.type() == CV_8UC1) {
    perception_camera_app::Image proto;
    proto.set_height(image.size().height);
    proto.set_width(image.size().width);
    proto.set_format(perception_camera_app::ImageFormat::CV8UC1);
    int size = image.size().height * image.size().width;
    proto.set_data(reinterpret_cast<char const *>(image.data), size);
    return proto;
  }
  if (image.type() == CV_8UC2) {
    perception_camera_app::Image proto;
    proto.set_height(image.size().height);
    proto.set_width(image.size().width);
    proto.set_format(perception_camera_app::ImageFormat::CV8UC2);
    int size = image.size().height * image.size().width * 2;
    proto.set_data(reinterpret_cast<char const *>(image.data), size);
    return proto;
  }
  if (image.type() == CV_8UC3) {
    perception_camera_app::Image proto;
    proto.set_height(image.size().height);
    proto.set_width(image.size().width);
    proto.set_format(perception_camera_app::ImageFormat::CV8UC3);
    int size = image.size().height * image.size().width * 3;
    proto.set_data(reinterpret_cast<char const *>(image.data), size);
    return proto;
  }
  if (image.type() == CV_8UC4) {
    perception_camera_app::Image proto;
    proto.set_height(image.size().height);
    proto.set_width(image.size().width);
    proto.set_format(perception_camera_app::ImageFormat::CV8UC4);
    int size = image.size().height * image.size().width * 4;
    proto.set_data(reinterpret_cast<char const *>(image.data), size);
    return proto;
  }
  throw std::runtime_error("unsupported image format!!");
}
} // namespace perception_camera_app