# export_visitor.py

from shape_visitor import ShapeVisitor

class ExportVisitor(ShapeVisitor):
  def visit_circle(self, circle):
    print("Exporting a Circle to file.")

  def visit_square(self, square):
    print("Exporting a Square to file.")
