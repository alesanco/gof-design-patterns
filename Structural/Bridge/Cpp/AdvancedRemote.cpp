// AdvancedRemote.cpp

#include "AdvancedRemote.h"
#include <iostream>

AdvancedRemote::AdvancedRemote(IDevice* device) : BasicRemote(device) {}

void AdvancedRemote::mute() {
  device->setVolume(0);
  std::cout << "Device is muted." << std::endl;
}
