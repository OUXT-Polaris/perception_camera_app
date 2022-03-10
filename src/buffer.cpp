#include <buffer.hpp>

namespace perception_camera_app {
Buffer::Buffer(const std::chrono::milliseconds &duration)
    : duration(duration) {}

void Buffer::popOld() {
  std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
  if (now - front().stamp > duration) {
    pop();
  } else if (now < front().stamp) {
    pop();
  }
}
} // namespace perception_camera_app