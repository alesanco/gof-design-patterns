// ChatUser.h

#ifndef CHATUSER_H
#define CHATUSER_H

#include "User.h"

class ChatUser : public User {
public:
  ChatUser(Mediator* mediator, std::string name);
  void sendMessage(const std::string& message) override;
  void receiveMessage(const std::string& message) override;
};

#endif // CHATUSER_H
