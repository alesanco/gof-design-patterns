# square.py

from shape import Shape

class Square(Shape):
  def accept(self, visitor):
    visitor.visit_square(self)
