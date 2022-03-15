#include <image_acquisition/image_acquisition.hpp>

int main() {
  perception_camera_app::ImageAcquisition image_acquisition(1280, 720, 30);
  while (true) {
    image_acquisition.capture();
  }
  return 0;
}