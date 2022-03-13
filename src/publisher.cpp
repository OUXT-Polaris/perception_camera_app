#include <publisher.hpp>

namespace perception_camera_app {
Publisher::Publisher(const zmqpp::context &context)
    : socket_(context, zmqpp::socket_type::publish) {}
} // namespace perception_camera_app
