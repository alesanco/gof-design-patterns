// Mediator.h

#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>
class User;

class Mediator {
public:
  virtual ~Mediator() = default;
  virtual void sendMessage(const std::string& message, User* sender) = 0;
};

#endif // MEDIATOR_H
