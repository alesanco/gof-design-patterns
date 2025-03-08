// ChatUser.cpp

#include "ChatUser.h"
#include <iostream>

ChatUser::ChatUser(Mediator* mediator, std::string name) : User(mediator, std::move(name)) {}

void ChatUser::sendMessage(const std::string& message) {
  std::cout << name << " sends: " << message << std::endl;
  mediator->sendMessage(message, this);
}

void ChatUser::receiveMessage(const std::string& message) {
  std::cout << name << " receives: " << message << std::endl;
}
