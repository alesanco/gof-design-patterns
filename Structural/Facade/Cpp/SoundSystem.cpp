// SoundSystem.cpp

#include "SoundSystem.h"

void SoundSystem::turnOn() {
  std::cout << "Sound System is ON." << std::endl;
}

void SoundSystem::turnOff() {
  std::cout << "Sound System is OFF." << std::endl;
}

void SoundSystem::setVolume(int level) {
  std::cout << "Sound System volume set to: " << level << std::endl;
}
