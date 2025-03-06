// IShapeFactory.cs

public interface IShapeFactory {
  IShape CreateShape(ShapeType type);
  IRenderer CreateRenderer();
}
