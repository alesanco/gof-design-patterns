// Shape.cs

using System;

public abstract class Shape : ICloneable {
  public string Color { get; set; }

  public Shape(string color) {
    Color = color;
  }

  public abstract void Draw();

  public virtual object Clone() {
    return MemberwiseClone();
  }
}
