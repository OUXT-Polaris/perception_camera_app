#include <image_acquisition/image_acquisition.hpp>
#include <zmqpp/zmqpp.hpp>

int main() {
  zmqpp::context context;
  perception_camera_app::ImageAcquisition image_acquisition(context);
  while (true) {
    image_acquisition.capture();
  }
  return 0;
}