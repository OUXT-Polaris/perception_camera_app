#ifndef _PERCEPTION_CAMERA_APP__SUBSCRIBER_HPP_
#define _PERCEPTION_CAMERA_APP__SUBSCRIBER_HPP_

#include <memory>
#include <perception_camera_app.pb.h>
#include <zmqpp/zmqpp.hpp>

namespace perception_camera_app {
class Subscriber {
public:
  explicit Subscriber(const zmqpp::context &context, const std::string &topic);

private:
  zmqpp::socket socket_;
};
} // namespace perception_camera_app

#endif // _PERCEPTION_CAMERA_APP__SUBSCRIBER_HPP_
