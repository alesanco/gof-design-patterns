// Circle.java

public class Circle extends Shape {
  private int radius;

  public Circle(String color, int radius) {
    super(color);
    this.radius = radius;
  }

  public int getRadius() {
    return radius;
  }

  public void setRadius(int radius) {
    this.radius = radius;
  }

  @Override
  public void draw() {
    System.out.println("Drawing a " + getColor() + " Circle with radius " + radius);
  }

  @Override
  public Circle clone() {
    Circle cloned = (Circle) super.clone();
    cloned.setRadius(this.radius);
    return cloned;
  }
}
