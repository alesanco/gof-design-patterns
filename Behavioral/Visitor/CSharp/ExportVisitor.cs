// ExportVisitor.cs

using System;

public class ExportVisitor : IShapeVisitor {
  public void Visit(Circle circle) {
    Console.WriteLine("Exporting a Circle to file.");
  }

  public void Visit(Square square) {
    Console.WriteLine("Exporting a Square to file.");
  }
}
