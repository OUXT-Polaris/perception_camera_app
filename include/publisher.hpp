#ifndef _PERCEPTION_CAMERA_APP__PUBLISHER_HPP_
#define _PERCEPTION_CAMERA_APP__PUBLISHER_HPP_

#include <chrono>
#include <conversion.hpp>
#include <endpoint.hpp>
#include <iostream>
#include <memory>
#include <perception_camera_app.pb.h>
#include <zmqpp/zmqpp.hpp>

namespace perception_camera_app {
template <typename T> class Publisher {
public:
  explicit Publisher(
      const zmqpp::context &context,
      const std::string &endpoint = perception_camera_app::resolve(
          perception_camera_app::Transport::kTcp, "*", 8000))
      : socket_(context, zmqpp::socket_type::publish) {
    std::cout << "Publisher connecting to : " << endpoint << std::endl;
    socket_.bind(endpoint);
  }

  void publish(const T &data) {
    zmqpp::message message;
    toZMQ(data, message);
    socket_.send(message);
  }

private:
  zmqpp::socket socket_;
};
} // namespace perception_camera_app

#endif // _PERCEPTION_CAMERA_APP__PUBLISHER_HPP_
