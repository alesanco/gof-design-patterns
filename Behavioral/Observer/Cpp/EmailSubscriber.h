// EmailSubscriber.h

#ifndef EMAILSUBSCRIBER_H
#define EMAILSUBSCRIBER_H

#include "Subscriber.h"

class EmailSubscriber : public Subscriber {
public:
  explicit EmailSubscriber(const std::string& name);
  void update(const std::string& news) override;
};

#endif // EMAILSUBSCRIBER_H
