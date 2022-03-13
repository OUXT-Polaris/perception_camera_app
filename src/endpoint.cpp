#include <endpoint.hpp>
#include <stdexcept>

namespace perception_camera_app {
std::string resolve(Transport transport, const std::string &address,
                    std::uint32_t port) {
  std::string endpoint;
  switch (transport) {
  case Transport::kInproc:
    throw std::runtime_error("inproc can be used in only localhost.");
    break;
  case Transport::kTcp:
    endpoint = "tcp:";
    break;
  case Transport::kUdp:
    endpoint = "udp:";
    break;
  }
  endpoint = endpoint + address + std::to_string(port);
  return endpoint;
} // namespace perception_camera_app

std::string resolve(const std::string &socket_name) {
  return "inproc://" + socket_name;
}
} // namespace perception_camera_app