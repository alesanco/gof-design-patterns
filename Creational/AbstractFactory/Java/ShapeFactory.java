// ShapeFactory.java

public interface ShapeFactory {
  Shape createShape(ShapeType type);
  Renderer createRenderer();
}
