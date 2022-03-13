#include <subscriber.hpp>

namespace perception_camera_app {
Subscriber::Subscriber(const zmqpp::context &context, const std::string &topic)
    : socket_(context, zmqpp::socket_type::sub) {
  socket_.subscribe(topic);
}
} // namespace perception_camera_app
