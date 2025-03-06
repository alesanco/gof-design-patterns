// TV.cpp

#include "TV.h"

void TV::turnOn() {
  on = true;
  std::cout << "TV is now ON." << std::endl;
}

void TV::turnOff() {
  on = false;
  std::cout << "TV is now OFF." << std::endl;
}

void TV::setVolume(int volume) {
  this->volume = volume;
  std::cout << "TV volume set to " << volume << std::endl;
}

int TV::getVolume() const {
  return volume;
}

bool TV::isOn() const {
  return on;
}
