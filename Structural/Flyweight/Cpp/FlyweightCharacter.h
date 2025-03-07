// FlyweightCharacter.h

#ifndef FLYWEIGHT_CHARACTER_H
#define FLYWEIGHT_CHARACTER_H

#include <iostream>

class FlyweightCharacter {
private:
  char symbol;

public:
  explicit FlyweightCharacter(char symbol);
  void display() const;
};

#endif // FLYWEIGHT_CHARACTER_H
