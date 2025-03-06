# shape_factory.py

from abc import ABC, abstractmethod
from shape_type import ShapeType
from shape import Shape
from renderer import Renderer

class ShapeFactory(ABC):
  @abstractmethod
  def create_shape(self, shape_type: ShapeType) -> Shape:
    pass

  @abstractmethod
  def create_renderer(self) -> Renderer:
    pass
