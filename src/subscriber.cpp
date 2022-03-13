#include <subscriber.hpp>

namespace perception_camera_app {
Subscriber::Subscriber(const zmqpp::context &context)
    : socket_(context, zmqpp::socket_type::subscribe) {}
} // namespace perception_camera_app
