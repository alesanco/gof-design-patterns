# payment_strategy.py

from abc import ABC, abstractmethod

class PaymentStrategy(ABC):
  @abstractmethod
  def pay(self, amount):
    pass
