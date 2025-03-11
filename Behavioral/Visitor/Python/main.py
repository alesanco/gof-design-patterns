# main.py

from circle import Circle
from square import Square
from render_visitor import RenderVisitor
from export_visitor import ExportVisitor

if __name__ == "__main__":
  shapes = [Circle(), Square()]

  render_visitor = RenderVisitor()
  export_visitor = ExportVisitor()

  print("Applying Render Visitor:")
  for shape in shapes:
    shape.accept(render_visitor)

  print("\nApplying Export Visitor:")
  for shape in shapes:
    shape.accept(export_visitor)
