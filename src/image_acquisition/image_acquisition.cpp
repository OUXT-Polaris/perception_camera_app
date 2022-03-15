#include <image_acquisition/image_acquisition.hpp>

namespace perception_camera_app {
ImageAcquisition::ImageAcquisition(uint32_t width, uint32_t height,
                                   uint32_t frame_rate)
    : width(width), height(height), frame_rate(frame_rate),
      capture_duration(1.0 / static_cast<double>(frame_rate)) {}

void ImageAcquisition::open() {
  while (!capture_ || !capture_->isOpened()) {
    capture_ = std::make_shared<cv::VideoCapture>(getGstreamerPipeline(),
                                                  cv::CAP_GSTREAMER);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void ImageAcquisition::capture() {
  if (!capture_ || !capture_->isOpened()) {
    open();
  }
  while (true) {
    const auto next_capture_time =
        std::chrono::system_clock::now() +
        std::chrono::milliseconds(static_cast<int>(capture_duration));
    cv::Mat image;
    if (capture_->read(image)) {
      break;
    }
    const auto now = std::chrono::system_clock::now();
    if (next_capture_time >= now) {
      continue;
    } else {
      const auto sleep_duration = next_capture_time - now;
      std::this_thread::sleep_for(sleep_duration);
      continue;
    }
  }
}

std::string ImageAcquisition::getGstreamerPipeline() const {
  return "nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)" +
         std::to_string(width) + ", height=(int)" + std::to_string(height) +
         ", framerate=(fraction)" + std::to_string(frame_rate) +
         "/1 ! nvvidconv flip-method=" + std::to_string(0) +
         " ! video/x-raw, width=(int)" + std::to_string(width) +
         ", height=(int)" + std::to_string(height) +
         ", format=(string)BGRx ! videoconvert ! video/x-raw, "
         "format=(string)BGR ! appsink";
}
} // namespace perception_camera_app