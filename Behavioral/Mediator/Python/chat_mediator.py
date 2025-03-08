# chat_mediator.py

from mediator import Mediator

class ChatMediator(Mediator):
  def __init__(self):
    self._users = []

  def add_user(self, user):
    self._users.append(user)

  def send_message(self, message, sender):
    for user in self._users:
      if user != sender:
        user.receive_message(message)
