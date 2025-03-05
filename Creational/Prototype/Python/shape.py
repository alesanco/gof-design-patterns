# shape.py
import copy

class Shape:
  def __init__(self, color):
    self.color = color

  def set_color(self, new_color):
    self.color = new_color

  def get_color(self):
    return self.color

  def clone(self):
    return copy.deepcopy(self)

  def draw(self):
    raise NotImplementedError("Subclass must implement abstract method")
