# chat_user.py

from user import User

class ChatUser(User):
  def __init__(self, mediator, name):
    super().__init__(mediator, name)

  def send_message(self, message):
    print(f"{self._name} sends: {message}")
    self._mediator.send_message(message, self)

  def receive_message(self, message):
    print(f"{self._name} receives: {message}")
