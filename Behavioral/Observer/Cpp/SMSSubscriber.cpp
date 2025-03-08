// SMSSubscriber.cpp

#include "SMSSubscriber.h"

SMSSubscriber::SMSSubscriber(const std::string& name) : Subscriber(name) {}

void SMSSubscriber::update(const std::string& news) {
  std::cout << name << " (SMS) received: " << news << std::endl;
}
