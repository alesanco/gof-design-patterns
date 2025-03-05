// Main.java
public class Main {
  public static void main(String[] args) {
    // Create an original Circle and Square
    Circle originalCircle = new Circle("Red", 10);
    Square originalSquare = new Square("Blue", 5);

    // Clone the objects
    Circle clonedCircle = originalCircle.clone();
    Square clonedSquare = originalSquare.clone();

    // Modify cloned objects
    clonedCircle.setColor("Green");
    clonedCircle.setRadius(20);

    clonedSquare.setColor("Yellow");
    clonedSquare.setSideLength(10);

    // Display original and cloned objects
    System.out.println("Original Objects:");
    originalCircle.draw();
    originalSquare.draw();

    System.out.println("\nCloned Objects:");
    clonedCircle.draw();
    clonedSquare.draw();
  }
}
