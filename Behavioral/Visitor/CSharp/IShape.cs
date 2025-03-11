// IShape.cs

public interface IShape {
  void Accept(IShapeVisitor visitor);
}
