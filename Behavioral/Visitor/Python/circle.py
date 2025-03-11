# circle.py

from shape import Shape

class Circle(Shape):
  def accept(self, visitor):
    visitor.visit_circle(self)
