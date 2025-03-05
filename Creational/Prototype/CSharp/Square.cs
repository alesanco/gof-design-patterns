// Square.cs
using System;

public class Square : Shape {
  public int SideLength { get; set; }

  public Square(string color, int sideLength) : base(color) {
    SideLength = sideLength;
  }

  public override void Draw() {
    Console.WriteLine($"Drawing a {Color} Square with side length {SideLength}");
  }

  public override object Clone() {
    return new Square(Color, SideLength);
  }
}
