# circle.py
from shape import Shape

class Circle(Shape):
  def __init__(self, color, radius):
    super().__init__(color)
    self.radius = radius

  def set_radius(self, new_radius):
    self.radius = new_radius

  def get_radius(self):
    return self.radius

  def draw(self):
    print(f"Drawing a {self.get_color()} Circle with radius {self.radius}")
