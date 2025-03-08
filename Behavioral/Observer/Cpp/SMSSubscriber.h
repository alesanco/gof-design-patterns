// SMSSubscriber.h

#ifndef SMSSUBSCRIBER_H
#define SMSSUBSCRIBER_H

#include "Subscriber.h"

class SMSSubscriber : public Subscriber {
public:
  explicit SMSSubscriber(const std::string& name);
  void update(const std::string& news) override;
};

#endif // SMSSUBSCRIBER_H
