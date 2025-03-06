// Shape.java

public abstract class Shape implements Cloneable {
  private String color;

  public Shape(String color) {
    this.color = color;
  }

  public String getColor() {
    return color;
  }

  public void setColor(String color) {
    this.color = color;
  }

  @Override
  public Shape clone() {
    try {
      return (Shape) super.clone();
    } catch (CloneNotSupportedException e) {
      throw new RuntimeException("Cloning not supported", e);
    }
  }

  public abstract void draw();
}
