// BasicRemote.cpp

#include "BasicRemote.h"
#include <iostream>

BasicRemote::BasicRemote(IDevice* device) : IRemote(device) {}

void BasicRemote::togglePower() {
  if (device->isOn()) {
    device->turnOff();
  } else {
    device->turnOn();
  }
}

void BasicRemote::volumeUp() {
  device->setVolume(device->getVolume() + 10);
}

void BasicRemote::volumeDown() {
  device->setVolume(device->getVolume() - 10);
}
