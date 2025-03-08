// Subscriber.h

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Observer.h"
#include <iostream>

class Subscriber : public Observer {
protected:
  std::string name;

public:
  explicit Subscriber(const std::string& name);
  void update(const std::string& news) override;
};

#endif // SUBSCRIBER_H
