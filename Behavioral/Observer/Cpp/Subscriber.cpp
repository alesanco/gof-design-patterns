// Subscriber.cpp

#include "Subscriber.h"

Subscriber::Subscriber(const std::string& name) : name(name) {}

void Subscriber::update(const std::string& news) {
  std::cout << name << " received news update: " << news << std::endl;
}
