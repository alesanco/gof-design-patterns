// EmailSubscriber.cpp

#include "EmailSubscriber.h"

EmailSubscriber::EmailSubscriber(const std::string& name) : Subscriber(name) {}

void EmailSubscriber::update(const std::string& news) {
  std::cout << name << " (Email) received: " << news << std::endl;
}
