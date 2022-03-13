#ifndef _PERCEPTION_CAMERA_APP__CONVERSION_HPP_
#define _PERCEPTION_CAMERA_APP__CONVERSION_HPP_

#include <opencv2/opencv.hpp>
#include <perception_camera_app.pb.h>

namespace perception_camera_app {
cv::Mat convert(const perception_camera_app::Image &image);
perception_camera_app::Image convert(const cv::Mat &image);
} // namespace perception_camera_app

#endif // _PERCEPTION_CAMERA_APP__CONVERSION_HPP_