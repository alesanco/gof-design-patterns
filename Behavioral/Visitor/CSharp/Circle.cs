// Circle.cs

public class Circle : IShape {
  public void Accept(IShapeVisitor visitor) {
    visitor.Visit(this);
  }
}
