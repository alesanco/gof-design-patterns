# main.py

from render_mode import RenderMode
from shape_type import ShapeType
from two_d_shape_factory import TwoDShapeFactory
from three_d_shape_factory import ThreeDShapeFactory

if __name__ == "__main__":
  for mode in RenderMode:
    match mode:
      case RenderMode.TWO_D:
        factory = TwoDShapeFactory()
      case RenderMode.THREE_D:
        factory = ThreeDShapeFactory()
      case _:
        raise ValueError(f"Unknown render mode: {mode}")

    for shape_type in ShapeType:
      print(f"\n=== Mode: {mode.value}, Shape: {shape_type.value} ===")

      shape = factory.create_shape(shape_type)
      renderer = factory.create_renderer()

      shape.draw()
      renderer.render()
