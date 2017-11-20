#include <astra_camera/astra_device_manager.h>
#include <astra_camera/astra_device.h>
#include <boost/shared_ptr.hpp>

using namespace astra_wrapper;

typedef boost::shared_ptr<AstraDeviceManager> AstraDeviceManagerPtr;
typedef boost::shared_ptr<AstraDevice> AstraDevicePtr;

int
main(int argc, char** argv)
{
  AstraDeviceManagerPtr dev_manager = AstraDeviceManager::getSingelton();
  auto devs = dev_manager->getConnectedDeviceInfos();
  auto uris = dev_manager->getConnectedDeviceURIs();

  std::cout << "Found devices:" << std::endl;
  for (auto& d : *devs) {
    std::cout << " " << d << std::endl;
  }
  std::cout << "Found uris:" << std::endl;
  for (auto& u : *uris) {
    std::cout << " " << u << std::endl;
  }

  AstraDevicePtr dev = dev_manager->getDevice((*uris)[0]);
  std::cout << "hasColorSensor(): " << dev->hasColorSensor() << std::endl;
  std::cout << "isImageRegistrationModeSupported(): " <<
    dev->isImageRegistrationModeSupported() << std::endl;
  try {
    dev->setDepthColorSync(true);
  } catch (AstraException& e) {
    std::cout << "Exception setting depthColorSync: " << e.what() << std::endl;
  }

  
  
  return 0;
}
