#ifndef _PERCEPTION_CAMERA_APP__ENDPOINT_HPP_
#define _PERCEPTION_CAMERA_APP__ENDPOINT_HPP_

#include <string>

namespace perception_camera_app {
enum class Transport { kInproc = 0, kTcp = 1, kUdp = 2 };

std::string resolve(Transport transport, const std::string &address,
                    std::uint32_t port);
std::string resolve(const std::string &socket_name);
} // namespace perception_camera_app

#endif // _PERCEPTION_CAMERA_APP__ENDPOINT_HPP_