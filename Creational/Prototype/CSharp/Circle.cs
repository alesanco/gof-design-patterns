// Circle.cs

using System;

public class Circle : Shape {
  public int Radius { get; set; }

  public Circle(string color, int radius) : base(color) {
    Radius = radius;
  }

  public override void Draw() {
    Console.WriteLine($"Drawing a {Color} Circle with radius {Radius}");
  }

  public override object Clone() {
    return new Circle(Color, Radius);
  }
}
