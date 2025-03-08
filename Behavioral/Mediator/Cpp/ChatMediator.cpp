// ChatMediator.cpp

#include "ChatMediator.h"
#include <iostream>

void ChatMediator::addUser(User* user) {
  users.push_back(user);
}

void ChatMediator::sendMessage(const std::string& message, User* sender) {
  for (User* user : users) {
    if (user != sender) {
      user->receiveMessage(message);
    }
  }
}
