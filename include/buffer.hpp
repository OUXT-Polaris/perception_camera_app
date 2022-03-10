#include <chrono>
#include <opencv2/opencv.hpp>
#include <vector>

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
  explicit Buffer(
      const std::chrono::duration<std::chrono::milliseconds> &duration);

private:
  std::vector<Data<cv::Mat>> images_;
};
} // namespace perception_camera_app