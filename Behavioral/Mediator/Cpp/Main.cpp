// Main.cpp

#include "ChatMediator.h"
#include "ChatUser.h"
#include <iostream>

int main() {
  ChatMediator chatMediator;

  ChatUser user1(&chatMediator, "Alice");
  ChatUser user2(&chatMediator, "Bob");
  ChatUser user3(&chatMediator, "Charlie");

  chatMediator.addUser(&user1);
  chatMediator.addUser(&user2);
  chatMediator.addUser(&user3);

  user1.sendMessage("Hello, everyone!");
  user2.sendMessage("Hey Alice!");

  return 0;
}
