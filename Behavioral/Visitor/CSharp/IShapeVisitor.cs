// IShapeVisitor.cs

public interface IShapeVisitor {
  void Visit(Circle circle);
  void Visit(Square square);
}
