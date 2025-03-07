// DVDPlayer.cpp

#include "DVDPlayer.h"

void DVDPlayer::turnOn() {
  std::cout << "DVD Player is ON." << std::endl;
}

void DVDPlayer::turnOff() {
  std::cout << "DVD Player is OFF." << std::endl;
}

void DVDPlayer::play(const std::string& movie) {
  std::cout << "Playing movie: " << movie << std::endl;
}
