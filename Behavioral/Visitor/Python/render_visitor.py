# render_visitor.py

from shape_visitor import ShapeVisitor

class RenderVisitor(ShapeVisitor):
  def visit_circle(self, circle):
    print("Rendering a Circle.")

  def visit_square(self, square):
    print("Rendering a Square.")
