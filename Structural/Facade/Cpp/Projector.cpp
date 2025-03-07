// Projector.cpp

#include "Projector.h"

void Projector::turnOn() {
  std::cout << "Projector is ON." << std::endl;
}

void Projector::turnOff() {
  std::cout << "Projector is OFF." << std::endl;
}

void Projector::setInput(const std::string& input) {
  std::cout << "Projector input set to: " << input << std::endl;
}
