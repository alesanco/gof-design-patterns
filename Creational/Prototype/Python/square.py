# square.py
from shape import Shape

class Square(Shape):
  def __init__(self, color, side_length):
    super().__init__(color)
    self.side_length = side_length

  def set_side_length(self, new_side_length):
    self.side_length = new_side_length

  def get_side_length(self):
    return self.side_length

  def draw(self):
    print(f"Drawing a {self.get_color()} Square with side length {self.side_length}")
