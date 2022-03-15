#ifndef _PERCEPTION_CAMERA_APP__CONVERSION_HPP_
#define _PERCEPTION_CAMERA_APP__CONVERSION_HPP_

#include <chrono>
#include <opencv2/opencv.hpp>
#include <perception_camera_app.pb.h>
#include <zmqpp/zmqpp.hpp>

namespace perception_camera_app {
cv::Mat convert(const perception_camera_app::Image &image);
perception_camera_app::Image convert(const cv::Mat &image);
perception_camera_app::ImageStamped
convert(const cv::Mat &image,
        const std::chrono::system_clock::time_point &time);
Time convert(const std::chrono::system_clock::time_point &time);
Time now();

template <typename Proto> void toZMQ(const Proto &proto, zmqpp::message &msg) {
  std::string serialized_str = "";
  proto.SerializeToString(&serialized_str);
  msg << serialized_str;
}

template <typename Proto>
void toProto(const zmqpp::message &msg, Proto &proto) {
  std::string serialized_str = msg.get(0);
  proto.ParseFromString(serialized_str);
}
} // namespace perception_camera_app

#endif // _PERCEPTION_CAMERA_APP__CONVERSION_HPP_