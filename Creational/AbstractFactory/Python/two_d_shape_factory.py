# two_d_shape_factory.py
from shape_factory import ShapeFactory
from shape_type import ShapeType
from circle import Circle
from square import Square
from two_d_renderer import TwoDRenderer

class TwoDShapeFactory(ShapeFactory):
  def create_shape(self, shape_type: ShapeType):
    match shape_type:
      case ShapeType.CIRCLE:
        return Circle()
      case ShapeType.SQUARE:
        return Square()
      case _:
        raise ValueError(f"Unknown shape type: {shape_type}")

  def create_renderer(self):
    return TwoDRenderer()
