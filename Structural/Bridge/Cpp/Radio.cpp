// Radio.cpp

#include "Radio.h"

void Radio::turnOn() {
  on = true;
  std::cout << "Radio is now ON." << std::endl;
}

void Radio::turnOff() {
  on = false;
  std::cout << "Radio is now OFF." << std::endl;
}

void Radio::setVolume(int volume) {
  this->volume = volume;
  std::cout << "Radio volume set to " << volume << std::endl;
}

int Radio::getVolume() const {
  return volume;
}

bool Radio::isOn() const {
  return on;
}
