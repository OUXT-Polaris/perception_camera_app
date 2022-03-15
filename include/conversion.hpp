#ifndef _PERCEPTION_CAMERA_APP__CONVERSION_HPP_
#define _PERCEPTION_CAMERA_APP__CONVERSION_HPP_

#include <chrono>
#include <opencv2/opencv.hpp>
#include <perception_camera_app.pb.h>
#include <zmqpp/zmqpp.hpp>

namespace perception_camera_app {
cv::Mat convert(const perception_camera_app::Image &image);
perception_camera_app::Image convert(const cv::Mat &image);
perception_camera_app::ImageStamped convertAndStamp(const cv::Mat &image);
Time convert(const std::chrono::system_clock::time_point &time);
Time now();

template <typename Proto> zmqpp::message toZMQ(const Proto &proto) {
  zmqpp::message msg;
  std::string serialized_str = "";
  proto.SerializeToString(&serialized_str);
  msg << serialized_str;
  return msg;
}

template <typename Proto> Proto toProto(const zmqpp::message &msg) {
  std::string serialized_str = msg.get(0);
  Proto proto;
  proto.ParseFromString(serialized_str);
  return proto;
}
} // namespace perception_camera_app

#endif // _PERCEPTION_CAMERA_APP__CONVERSION_HPP_