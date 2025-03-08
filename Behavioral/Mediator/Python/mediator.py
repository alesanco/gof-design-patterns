# mediator.py

from abc import ABC, abstractmethod

class Mediator(ABC):
  @abstractmethod
  def send_message(self, message, sender):
    pass
