// ExportVisitor.java

public class ExportVisitor implements ShapeVisitor {
  @Override
  public void visit(Circle circle) {
    System.out.println("Exporting a Circle to file.");
  }

  @Override
  public void visit(Square square) {
    System.out.println("Exporting a Square to file.");
  }
}
