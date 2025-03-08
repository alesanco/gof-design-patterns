# main.py

from chat_mediator import ChatMediator
from chat_user import ChatUser

if __name__ == "__main__":
  chat_mediator = ChatMediator()

  user1 = ChatUser(chat_mediator, "Alice")
  user2 = ChatUser(chat_mediator, "Bob")
  user3 = ChatUser(chat_mediator, "Charlie")

  chat_mediator.add_user(user1)
  chat_mediator.add_user(user2)
  chat_mediator.add_user(user3)

  user1.send_message("Hello, everyone!")
  user2.send_message("Hey Alice!")
