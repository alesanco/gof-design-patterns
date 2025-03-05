// TwoDShapeFactory.cs
using System;

public class TwoDShapeFactory : IShapeFactory {
  public IShape CreateShape(ShapeType type) {
    return type switch {
      ShapeType.CIRCLE => new Circle(),
      ShapeType.SQUARE => new Square(),
      _ => throw new ArgumentException($"Unknown shape type: {type}")
    };
  }

  public IRenderer CreateRenderer() {
    return new TwoDRenderer();
  }
}
