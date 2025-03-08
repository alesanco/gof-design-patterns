// ChatMediator.h

#ifndef CHATMEDIATOR_H
#define CHATMEDIATOR_H

#include "Mediator.h"
#include "User.h"
#include <vector>

class ChatMediator : public Mediator {
private:
  std::vector<User*> users;

public:
  void addUser(User* user);
  void sendMessage(const std::string& message, User* sender) override;
};

#endif // CHATMEDIATOR_H
