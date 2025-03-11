// RenderVisitor.cs

using System;

public class RenderVisitor : IShapeVisitor {
  public void Visit(Circle circle) {
    Console.WriteLine("Rendering a Circle.");
  }

  public void Visit(Square square) {
    Console.WriteLine("Rendering a Square.");
  }
}
