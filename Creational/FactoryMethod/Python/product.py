# product.py

from abc import ABC, abstractmethod

class Product(ABC):
  @abstractmethod
  def use(self):
    pass
