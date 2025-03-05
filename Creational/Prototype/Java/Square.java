// Square.java
public class Square extends Shape {
  private int sideLength;

  public Square(String color, int sideLength) {
    super(color);
    this.sideLength = sideLength;
  }

  public int getSideLength() {
    return sideLength;
  }

  public void setSideLength(int sideLength) {
    this.sideLength = sideLength;
  }

  @Override
  public void draw() {
    System.out.println("Drawing a " + getColor() + " Square with side length " + sideLength);
  }

  @Override
  public Square clone() {
    Square cloned = (Square) super.clone();
    cloned.setSideLength(this.sideLength);
    return cloned;
  }
}
