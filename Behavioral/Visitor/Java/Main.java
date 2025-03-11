// Main.java

import java.util.Arrays;
import java.util.List;

public class Main {
  public static void main(String[] args) {
    List<Shape> shapes = Arrays.asList(new Circle(), new Square());

    ShapeVisitor renderVisitor = new RenderVisitor();
    ShapeVisitor exportVisitor = new ExportVisitor();

    System.out.println("Applying Render Visitor:");
    for (Shape shape : shapes) {
      shape.accept(renderVisitor);
    }

    System.out.println("\nApplying Export Visitor:");
    for (Shape shape : shapes) {
      shape.accept(exportVisitor);
    }
  }
}
