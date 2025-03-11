// Square.java

public class Square implements Shape {
  @Override
  public void accept(ShapeVisitor visitor) {
    visitor.visit(this);
  }
}
