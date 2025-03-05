# creator.py
from abc import ABC, abstractmethod
from product import Product

class Creator(ABC):
  @abstractmethod
  def create_product(self) -> Product:
    pass
