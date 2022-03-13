#ifndef _PERCEPTION_CAMERA_APP__PUBLISHER_HPP_
#define _PERCEPTION_CAMERA_APP__PUBLISHER_HPP_

#include <chrono>
#include <memory>
#include <perception_camera_app.pb.h>
#include <zmqpp/zmqpp.hpp>

namespace perception_camera_app {
class Publisher {
public:
  explicit Publisher(const zmqpp::context &context);

private:
  const zmqpp::socket socket_;
};
} // namespace perception_camera_app

#endif // _PERCEPTION_CAMERA_APP__PUBLISHER_HPP_
