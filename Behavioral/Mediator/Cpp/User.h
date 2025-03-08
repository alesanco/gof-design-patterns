// User.h

#ifndef USER_H
#define USER_H

#include "Mediator.h"
#include <string>

class User {
protected:
  Mediator* mediator;
  std::string name;

public:
  User(Mediator* mediator, std::string name);
  virtual ~User() = default;
  virtual void sendMessage(const std::string& message) = 0;
  virtual void receiveMessage(const std::string& message) = 0;
};

#endif // USER_H
