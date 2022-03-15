#ifndef _PERCEPTION_CAMERA_APP__PUBLISHER_HPP_
#define _PERCEPTION_CAMERA_APP__PUBLISHER_HPP_

#include <chrono>
#include <conversion.hpp>
#include <endpoint.hpp>
#include <memory>
#include <perception_camera_app.pb.h>
#include <zmqpp/zmqpp.hpp>

static const std::string PUBLISH_ENDPOINT = "tcp://*:4242";

namespace perception_camera_app {
template <typename T> class Publisher {
public:
  explicit Publisher(
      const zmqpp::context &context,
      const std::string &endpoint = perception_camera_app::resolve(
          perception_camera_app::Transport::kTcp, "*", 8000))
      : socket_(context, zmqpp::socket_type::publish) {
    // socket_.bind(endpoint);
  }

  void publish(const T &data) { zmqpp::message message = toZMQ(data); }

private:
  const zmqpp::socket socket_;
};
} // namespace perception_camera_app

#endif // _PERCEPTION_CAMERA_APP__PUBLISHER_HPP_
