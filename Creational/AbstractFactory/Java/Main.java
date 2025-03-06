// Main.java

public class Main {
  public static void main(String[] args) {
    // Loop through rendering modes
    for (RenderMode mode : RenderMode.values()) {
      ShapeFactory factory;

      // Select the factory based on mode
      switch (mode) {
        case TWO_D:
          factory = new TwoDShapeFactory();
          break;
        case THREE_D:
          factory = new ThreeDShapeFactory();
          break;
        default:
          throw new IllegalArgumentException("Unknown mode: " + mode);
      }

      // Loop through shape types
      for (ShapeType shapeType : ShapeType.values()) {
        System.out.println("\n=== Mode: " + mode + ", Shape: " + shapeType + " ===");
        
        // Create and use products
        Shape shape = factory.createShape(shapeType);
        Renderer renderer = factory.createRenderer();

        shape.draw();
        renderer.render();
      }
    }
  }
}
