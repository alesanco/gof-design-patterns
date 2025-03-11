// RenderVisitor.java

public class RenderVisitor implements ShapeVisitor {
  @Override
  public void visit(Circle circle) {
    System.out.println("Rendering a Circle.");
  }

  @Override
  public void visit(Square square) {
    System.out.println("Rendering a Square.");
  }
}
