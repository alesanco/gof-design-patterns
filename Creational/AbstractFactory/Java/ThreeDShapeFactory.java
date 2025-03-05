// ThreeDShapeFactory.java
public class ThreeDShapeFactory implements ShapeFactory {
  @Override
  public Shape createShape(ShapeType type) {
    switch (type) {
      case CIRCLE:
        return new Circle();
      case SQUARE:
        return new Square();
      default:
        throw new IllegalArgumentException("Unknown shape type: " + type);
    }
  }

  @Override
  public Renderer createRenderer() {
    return new ThreeDRenderer();
  }
}
