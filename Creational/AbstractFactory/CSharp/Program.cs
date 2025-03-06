// Program.cs

using System;

class Program {
  static void Main() {
    // Loop through both rendering modes
    foreach (RenderMode mode in Enum.GetValues(typeof(RenderMode))) {
      IShapeFactory factory = mode switch {
        RenderMode.TWO_D => new TwoDShapeFactory(),
        RenderMode.THREE_D => new ThreeDShapeFactory(),
        _ => throw new ArgumentException($"Unknown render mode: {mode}")
      };

      // Loop through both shape types
      foreach (ShapeType shapeType in Enum.GetValues(typeof(ShapeType))) {
        Console.WriteLine($"\n=== Mode: {mode}, Shape: {shapeType} ===");

        // Create and use products
        IShape shape = factory.CreateShape(shapeType);
        IRenderer renderer = factory.CreateRenderer();

        shape.Draw();
        renderer.Render();
      }
    }
  }
}
