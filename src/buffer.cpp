#include <buffer.hpp>

namespace perception_camera_app {
Buffer::Buffer(const std::chrono::milliseconds &duration)
    : duration(duration) {}

void Buffer::emplace(const cv::Mat &image) {
  queue_.emplace(image, std::chrono::system_clock::now());
  popOld();
}

Data<cv::Mat> Buffer::front() {
  popOld();
  return queue_.front();
}

void Buffer::popOld() {
  auto check_stamp = [this]() {
    if (queue_.size() == 0) {
      return false;
    }
    std::chrono::system_clock::time_point now =
        std::chrono::system_clock::now();
    if (now - queue_.front().stamp > duration) {
      queue_.pop();
      return true;
    } else if (now < queue_.front().stamp) {
      queue_.pop();
      return true;
    }
    return false;
  };
  while (check_stamp()) {
  }
}
} // namespace perception_camera_app