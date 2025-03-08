# user.py

from abc import ABC, abstractmethod

class User(ABC):
  def __init__(self, mediator, name):
    self._mediator = mediator
    self._name = name

  @abstractmethod
  def send_message(self, message):
    pass

  @abstractmethod
  def receive_message(self, message):
    pass
