#pragma once

#include <chrono>
#include <opencv2/opencv.hpp>
#include <queue>
#include <unordered_map>

namespace perception_camera_app {
template <typename T> class Data {
public:
  explicit Data(const T &data,
                const std::chrono::system_clock::time_point &stamp)
      : data(data), stamp(stamp) {}
  const T data;
  const std::chrono::system_clock::time_point stamp;
};

template <typename T> bool operator<(const Data<T> &t1, const Data<T> &t2) {
  return t1.stamp < t2.stamp;
}

class Buffer {
public:
  explicit Buffer(const std::chrono::milliseconds &duration);
  const std::chrono::milliseconds duration;
  void emplace(const std::string &key, const cv::Mat &image);
  Data<cv::Mat> front(const std::string &key);

private:
  void popOld(const std::string &key);
  std::unordered_map<std::string, std::queue<Data<cv::Mat>>> queue_;
};
} // namespace perception_camera_app
