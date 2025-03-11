# shape_visitor.py

from abc import ABC, abstractmethod

class ShapeVisitor(ABC):
  @abstractmethod
  def visit_circle(self, circle):
    pass

  @abstractmethod
  def visit_square(self, square):
    pass
