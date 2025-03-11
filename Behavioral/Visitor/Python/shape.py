# shape.py

from abc import ABC, abstractmethod

class Shape(ABC):
  @abstractmethod
  def accept(self, visitor):
    pass
