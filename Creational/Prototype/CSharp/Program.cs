// Program.cs
using System;

class Program {
  static void Main() {
    // Create an original Circle and Square
    Circle originalCircle = new Circle("Red", 10);
    Square originalSquare = new Square("Blue", 5);

    // Clone the objects
    Circle clonedCircle = (Circle)originalCircle.Clone();
    Square clonedSquare = (Square)originalSquare.Clone();

    // Modify cloned objects
    clonedCircle.Color = "Green";
    clonedCircle.Radius = 20;

    clonedSquare.Color = "Yellow";
    clonedSquare.SideLength = 10;

    // Display original and cloned objects
    Console.WriteLine("Original Objects:");
    originalCircle.Draw();
    originalSquare.Draw();

    Console.WriteLine("\nCloned Objects:");
    clonedCircle.Draw();
    clonedSquare.Draw();
  }
}
