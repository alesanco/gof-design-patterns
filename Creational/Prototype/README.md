# Prototype Pattern

## 📌 What is the Prototype Pattern?
The **Prototype pattern** is a **creational design pattern** used to **clone objects** instead of creating new instances from scratch. This is useful when object creation is expensive or when we need multiple instances with minor modifications.

## 📌 When to Use Prototype
Use the **Prototype pattern** when:

- Object creation is **costly** (e.g., deep object initialization).
- You need **copies of an existing object with modifications**.
- You want to **avoid creating subclasses for variations**.

## 📌 Example: Shape Cloning
Imagine we are designing a **Shape Cloning System** where we can create copies of existing **Circles** and **Squares** instead of manually constructing them.

## 📌 Implementation in Different Languages
Each language implements the **Prototype pattern** differently based on its capabilities.

### **Java Implementation**
```java
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
```
```java
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
```
```java
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
```
```java
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
```

### **C# Implementation**
```csharp
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
```
```csharp
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
```
```csharp
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
```
```csharp
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
```

### **C++ Implementation**
```cpp
// Shape.h

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
protected:
  std::string color;

public:
  Shape(const std::string& color);
  virtual ~Shape() = default;

  void setColor(const std::string& newColor);
  std::string getColor() const;

  virtual Shape* clone() const = 0;
  virtual void draw() const = 0;
};

#endif // SHAPE_H
```
```cpp
// Shape.cpp

#include "Shape.h"

Shape::Shape(const std::string& color) : color(color) {}

void Shape::setColor(const std::string& newColor) {
  color = newColor;
}

std::string Shape::getColor() const {
  return color;
}
```
```cpp
// Circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
  int radius;

public:
  Circle(const std::string& color, int radius);
  void setRadius(int newRadius);
  int getRadius() const;
  void draw() const override;
  Circle* clone() const override;
};

#endif // CIRCLE_H
```
```cpp
// Circle.cpp

#include "Circle.h"
#include <iostream>

Circle::Circle(const std::string& color, int radius) : Shape(color), radius(radius) {}

void Circle::setRadius(int newRadius) {
  radius = newRadius;
}

int Circle::getRadius() const {
  return radius;
}

void Circle::draw() const {
  std::cout << "Drawing a " << getColor() << " Circle with radius " << radius << std::endl;
}

Circle* Circle::clone() const {
  return new Circle(*this);
}
```
```cpp
// Square.h

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
  int sideLength;

public:
  Square(const std::string& color, int sideLength);
  void setSideLength(int newSideLength);
  int getSideLength() const;
  void draw() const override;
  Square* clone() const override;
};

#endif // SQUARE_H
```
```cpp
// Square.cpp

#include "Square.h"
#include <iostream>

Square::Square(const std::string& color, int sideLength) : Shape(color), sideLength(sideLength) {}

void Square::setSideLength(int newSideLength) {
  sideLength = newSideLength;
}

int Square::getSideLength() const {
  return sideLength;
}

void Square::draw() const {
  std::cout << "Drawing a " << getColor() << " Square with side length " << sideLength << std::endl;
}

Square* Square::clone() const {
  return new Square(*this);
}
```
```cpp
// Main.cpp

#include <iostream>
#include "Circle.h"
#include "Square.h"

int main() {
  // Create an original Circle and Square
  Circle* originalCircle = new Circle("Red", 10);
  Square* originalSquare = new Square("Blue", 5);

  // Clone the objects
  Circle* clonedCircle = originalCircle->clone();
  Square* clonedSquare = originalSquare->clone();

  // Modify cloned objects
  clonedCircle->setColor("Green");
  clonedCircle->setRadius(20);

  clonedSquare->setColor("Yellow");
  clonedSquare->setSideLength(10);

  // Display original and cloned objects
  std::cout << "Original Objects:" << std::endl;
  originalCircle->draw();
  originalSquare->draw();

  std::cout << "\nCloned Objects:" << std::endl;
  clonedCircle->draw();
  clonedSquare->draw();

  // Clean up memory
  delete originalCircle;
  delete originalSquare;
  delete clonedCircle;
  delete clonedSquare;

  return 0;
}
```

### **Python Implementation**
```python
# shape.py

import copy

class Shape:
  def __init__(self, color):
    self.color = color

  def set_color(self, new_color):
    self.color = new_color

  def get_color(self):
    return self.color

  def clone(self):
    return copy.deepcopy(self)

  def draw(self):
    raise NotImplementedError("Subclass must implement abstract method")
```
```python
# circle.py

from shape import Shape

class Circle(Shape):
  def __init__(self, color, radius):
    super().__init__(color)
    self.radius = radius

  def set_radius(self, new_radius):
    self.radius = new_radius

  def get_radius(self):
    return self.radius

  def draw(self):
    print(f"Drawing a {self.get_color()} Circle with radius {self.radius}")
```
```python
# square.py

from shape import Shape

class Square(Shape):
  def __init__(self, color, side_length):
    super().__init__(color)
    self.side_length = side_length

  def set_side_length(self, new_side_length):
    self.side_length = new_side_length

  def get_side_length(self):
    return self.side_length

  def draw(self):
    print(f"Drawing a {self.get_color()} Square with side length {self.side_length}")
```
```python
# main.py

from circle import Circle
from square import Square

if __name__ == "__main__":
  # Create an original Circle and Square
  original_circle = Circle("Red", 10)
  original_square = Square("Blue", 5)

  # Clone the objects
  cloned_circle = original_circle.clone()
  cloned_square = original_square.clone()

  # Modify cloned objects
  cloned_circle.set_color("Green")
  cloned_circle.set_radius(20)

  cloned_square.set_color("Yellow")
  cloned_square.set_side_length(10)

  # Display original and cloned objects
  print("Original Objects:")
  original_circle.draw()
  original_square.draw()

  print("\nCloned Objects:")
  cloned_circle.draw()
  cloned_square.draw()
```

### **JavaScript Implementation**
```javascript
// shape.js

class Shape {
  constructor(color) {
    this.color = color;
  }

  setColor(newColor) {
    this.color = newColor;
  }

  getColor() {
    return this.color;
  }

  clone() {
    return Object.assign(Object.create(Object.getPrototypeOf(this)), this);
  }

  draw() {
    throw new Error("Subclass must implement abstract method");
  }
}

module.exports = Shape;
```
```javascript
// circle.js

const Shape = require("./shape");

class Circle extends Shape {
  constructor(color, radius) {
    super(color);
    this.radius = radius;
  }

  setRadius(newRadius) {
    this.radius = newRadius;
  }

  getRadius() {
    return this.radius;
  }

  draw() {
    console.log(`Drawing a ${this.getColor()} Circle with radius ${this.radius}`);
  }
}

module.exports = Circle;
```
```javascript
// square.js

const Shape = require("./shape");

class Square extends Shape {
  constructor(color, sideLength) {
    super(color);
    this.sideLength = sideLength;
  }

  setSideLength(newSideLength) {
    this.sideLength = newSideLength;
  }

  getSideLength() {
    return this.sideLength;
  }

  draw() {
    console.log(`Drawing a ${this.getColor()} Square with side length ${this.sideLength}`);
  }
}

module.exports = Square;
```
```javascript
// main.js

const Circle = require("./circle");
const Square = require("./square");

const originalCircle = new Circle("Red", 10);
const originalSquare = new Square("Blue", 5);

// Clone the objects
const clonedCircle = originalCircle.clone();
const clonedSquare = originalSquare.clone();

// Modify cloned objects
clonedCircle.setColor("Green");
clonedCircle.setRadius(20);

clonedSquare.setColor("Yellow");
clonedSquare.setSideLength(10);

// Display original and cloned objects
console.log("Original Objects:");
originalCircle.draw();
originalSquare.draw();

console.log("\nCloned Objects:");
clonedCircle.draw();
clonedSquare.draw();
```

## 📌 Running the Code
To test the **Prototype pattern**, run the following commands:

### **Java**
```sh
cd Creational/Prototype/Java
javac *.java
java Main
```

### **C#**
```sh
cd Creational/Prototype/CSharp
dotnet build
dotnet run
```

### **C++**
```sh
cd Creational/Prototype/Cpp
g++ *.cpp -o prototype
./prototype
```

### **Python**
```sh
cd Creational/Prototype/Python
python3 main.py
```

### **JavaScript**
```sh
cd Creational/Prototype/JavaScript
node main.js
```

## 📌 Expected Output
```
Original Objects:
Drawing a Red Circle with radius 10
Drawing a Blue Square with side length 5

Cloned Objects:
Drawing a Green Circle with radius 20
Drawing a Yellow Square with side length 10
```

## 📌 Summary
- Prototype pattern enables object cloning without creating new instances from scratch.
- Efficient when object creation is costly.
- Allows modification of cloned objects without affecting the original.