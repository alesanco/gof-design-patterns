// Projector.h

#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <iostream>
#include <string>

class Projector {
public:
  void turnOn();
  void turnOff();
  void setInput(const std::string& input);
};

#endif // PROJECTOR_H
