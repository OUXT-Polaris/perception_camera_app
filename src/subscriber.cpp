#include <subscriber.hpp>

namespace perception_camera_app {
Subscriber::Subscriber(const zmqpp::context &context, const std::string &topic)
    : socket_(context, zmqpp::socket_type::sub) {
  zmqpp::socket sub(context, zmqpp::socket_type::sub);
  sub.connect("inproc://test");
  sub.subscribe("hello");
  socket_.subscribe("hello");
}
} // namespace perception_camera_app
