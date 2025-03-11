// Program.cs

using System;
using System.Collections.Generic;

class Program {
  static void Main() {
    List<IShape> shapes = new List<IShape> { new Circle(), new Square() };

    IShapeVisitor renderVisitor = new RenderVisitor();
    IShapeVisitor exportVisitor = new ExportVisitor();

    Console.WriteLine("Applying Render Visitor:");
    foreach (var shape in shapes) {
      shape.Accept(renderVisitor);
    }

    Console.WriteLine("\nApplying Export Visitor:");
    foreach (var shape in shapes) {
      shape.Accept(exportVisitor);
    }
  }
}
