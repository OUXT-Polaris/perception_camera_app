#include <buffer.hpp>

namespace perception_camera_app {
Buffer::Buffer(const std::chrono::milliseconds &duration)
    : duration(duration) {}

void Buffer::emplace(const std::string &key, const cv::Mat &image) {
  queue_.at(key).emplace(image, std::chrono::system_clock::now());
  popOld(key);
}

Data<cv::Mat> Buffer::front(const std::string &key) {
  popOld(key);
  return queue_.at(key).front();
}

void Buffer::popOld(const std::string &key) {
  auto check_stamp = [this, key]() {
    if (queue_.size() == 0) {
      return false;
    }
    std::chrono::system_clock::time_point now =
        std::chrono::system_clock::now();
    if (now - queue_.at(key).front().stamp > duration) {
      queue_.at(key).pop();
      return true;
    } else if (now < queue_.at(key).front().stamp) {
      queue_.at(key).pop();
      return true;
    }
    return false;
  };
  while (check_stamp()) {
  }
}
} // namespace perception_camera_app