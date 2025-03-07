// FlyweightCharacter.cpp

#include "FlyweightCharacter.h"

FlyweightCharacter::FlyweightCharacter(char symbol) : symbol(symbol) {}

void FlyweightCharacter::display() const {
  std::cout << "Character: " << symbol << std::endl;
}
