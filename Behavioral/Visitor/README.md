# Visitor Pattern

## 📌 What is the Visitor Pattern?
The **Visitor Pattern** is a behavioral design pattern that allows **adding new behaviors** to existing class hierarchies **without modifying their structure**. It achieves this by defining a visitor class that implements the operations and an element class that accepts the visitor.

## 📌 When to Use the Visitor
Use the **Visitor pattern** when:

- You need to **add new operations** to an existing hierarchy without modifying its classes.
- You want to **separate business logic from data structure**, making the system more maintainable.
- An operation needs to be performed **on multiple object types** without altering their structures.

## 📌 Example: Shape Processing System
A **Shape Processing System** where different shapes (Circle, Square) need to be visited by different operations like **Rendering** and **Exporting**.

### 📌 Implementation in Different Languages
Each language implements the **Visitor pattern** differently based on its capabilities.

#### **Java Implementation**
```java
// ShapeVisitor.java

public interface ShapeVisitor {
  void visit(Circle circle);
  void visit(Square square);
}
```
```java
// RenderVisitor.java

public class RenderVisitor implements ShapeVisitor {
  @Override
  public void visit(Circle circle) {
    System.out.println("Rendering a Circle.");
  }

  @Override
  public void visit(Square square) {
    System.out.println("Rendering a Square.");
  }
}
```
```java
// ExportVisitor.java

public class ExportVisitor implements ShapeVisitor {
  @Override
  public void visit(Circle circle) {
    System.out.println("Exporting a Circle to file.");
  }

  @Override
  public void visit(Square square) {
    System.out.println("Exporting a Square to file.");
  }
}
```
```java
// Shape.java

public interface Shape {
  void accept(ShapeVisitor visitor);
}
```
```java
// Circle.java

public class Circle implements Shape {
  @Override
  public void accept(ShapeVisitor visitor) {
    visitor.visit(this);
  }
}
```
```java
// Square.java

public class Square implements Shape {
  @Override
  public void accept(ShapeVisitor visitor) {
    visitor.visit(this);
  }
}
```
```java
// Main.java

import java.util.Arrays;
import java.util.List;

public class Main {
  public static void main(String[] args) {
    List<Shape> shapes = Arrays.asList(new Circle(), new Square());

    ShapeVisitor renderVisitor = new RenderVisitor();
    ShapeVisitor exportVisitor = new ExportVisitor();

    System.out.println("Applying Render Visitor:");
    for (Shape shape : shapes) {
      shape.accept(renderVisitor);
    }

    System.out.println("\nApplying Export Visitor:");
    for (Shape shape : shapes) {
      shape.accept(exportVisitor);
    }
  }
}
```

#### **C# Implementation**
```csharp
// IShapeVisitor.cs

public interface IShapeVisitor {
  void Visit(Circle circle);
  void Visit(Square square);
}
```
```csharp
// RenderVisitor.cs

using System;

public class RenderVisitor : IShapeVisitor {
  public void Visit(Circle circle) {
    Console.WriteLine("Rendering a Circle.");
  }

  public void Visit(Square square) {
    Console.WriteLine("Rendering a Square.");
  }
}
```
```csharp
// ExportVisitor.cs

using System;

public class ExportVisitor : IShapeVisitor {
  public void Visit(Circle circle) {
    Console.WriteLine("Exporting a Circle to file.");
  }

  public void Visit(Square square) {
    Console.WriteLine("Exporting a Square to file.");
  }
}
```
```csharp
// IShape.cs

public interface IShape {
  void Accept(IShapeVisitor visitor);
}
```
```csharp
// Circle.cs

public class Circle : IShape {
  public void Accept(IShapeVisitor visitor) {
    visitor.Visit(this);
  }
}
```
```csharp
// Square.cs

public class Square : IShape {
  public void Accept(IShapeVisitor visitor) {
    visitor.Visit(this);
  }
}
```
```csharp
// Program.cs

using System;
using System.Collections.Generic;

class Program {
  static void Main() {
    List<IShape> shapes = new List<IShape> { new Circle(), new Square() };

    IShapeVisitor renderVisitor = new RenderVisitor();
    IShapeVisitor exportVisitor = new ExportVisitor();

    Console.WriteLine("Applying Render Visitor:");
    foreach (var shape in shapes) {
      shape.Accept(renderVisitor);
    }

    Console.WriteLine("\nApplying Export Visitor:");
    foreach (var shape in shapes) {
      shape.Accept(exportVisitor);
    }
  }
}
```

#### **C++ Implementation**
```cpp
// ShapeVisitor.h

#ifndef SHAPEVISITOR_H
#define SHAPEVISITOR_H

class Circle;
class Square;

class ShapeVisitor {
public:
  virtual void visit(Circle& circle) = 0;
  virtual void visit(Square& square) = 0;
  virtual ~ShapeVisitor() = default;
};

#endif // SHAPEVISITOR_H
```
```cpp
// RenderVisitor.h

#ifndef RENDERVISITOR_H
#define RENDERVISITOR_H

#include "ShapeVisitor.h"
#include <iostream>

class RenderVisitor : public ShapeVisitor {
public:
  void visit(Circle& circle) override;
  void visit(Square& square) override;
};

#endif // RENDERVISITOR_H
```
```cpp
// RenderVisitor.cpp

#include "RenderVisitor.h"
#include "Circle.h"
#include "Square.h"

void RenderVisitor::visit(Circle& circle) {
  std::cout << "Rendering a Circle." << std::endl;
}

void RenderVisitor::visit(Square& square) {
  std::cout << "Rendering a Square." << std::endl;
}
```
```cpp
// ExportVisitor.h

#ifndef EXPORTVISITOR_H
#define EXPORTVISITOR_H

#include "ShapeVisitor.h"
#include <iostream>

class ExportVisitor : public ShapeVisitor {
public:
  void visit(Circle& circle) override;
  void visit(Square& square) override;
};

#endif // EXPORTVISITOR_H
```
```cpp
// ExportVisitor.cpp

#include "ExportVisitor.h"
#include "Circle.h"
#include "Square.h"

void ExportVisitor::visit(Circle& circle) {
  std::cout << "Exporting a Circle to file." << std::endl;
}

void ExportVisitor::visit(Square& square) {
  std::cout << "Exporting a Square to file." << std::endl;
}
```
```cpp
// Shape.h

#ifndef SHAPE_H
#define SHAPE_H

#include "ShapeVisitor.h"

class Shape {
public:
  virtual void accept(ShapeVisitor& visitor) = 0;
  virtual ~Shape() = default;
};

#endif // SHAPE_H
```
```cpp
// Circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
  void accept(ShapeVisitor& visitor) override;
};

#endif // CIRCLE_H
```
```cpp
// Circle.cpp

#include "Circle.h"

void Circle::accept(ShapeVisitor& visitor) {
  visitor.visit(*this);
}
```
```cpp
// Square.h

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
public:
  void accept(ShapeVisitor& visitor) override;
};

#endif // SQUARE_H
```
```cpp
// Square.cpp

#include "Square.h"

void Square::accept(ShapeVisitor& visitor) {
  visitor.visit(*this);
}
```
```cpp
// Main.cpp

#include "Circle.h"
#include "Square.h"
#include "RenderVisitor.h"
#include "ExportVisitor.h"
#include <vector>
#include <memory>

int main() {
  std::vector<std::unique_ptr<Shape>> shapes;
  shapes.push_back(std::make_unique<Circle>());
  shapes.push_back(std::make_unique<Square>());

  RenderVisitor renderVisitor;
  ExportVisitor exportVisitor;

  std::cout << "Applying Render Visitor:" << std::endl;
  for (const auto& shape : shapes) {
    shape->accept(renderVisitor);
  }

  std::cout << "\nApplying Export Visitor:" << std::endl;
  for (const auto& shape : shapes) {
    shape->accept(exportVisitor);
  }

  return 0;
}
```

#### **Python Implementation**
```python
# shape_visitor.py

from abc import ABC, abstractmethod

class ShapeVisitor(ABC):
  @abstractmethod
  def visit_circle(self, circle):
    pass

  @abstractmethod
  def visit_square(self, square):
    pass
```
```python
# render_visitor.py

from shape_visitor import ShapeVisitor

class RenderVisitor(ShapeVisitor):
  def visit_circle(self, circle):
    print("Rendering a Circle.")

  def visit_square(self, square):
    print("Rendering a Square.")
```
```python
# export_visitor.py

from shape_visitor import ShapeVisitor

class ExportVisitor(ShapeVisitor):
  def visit_circle(self, circle):
    print("Exporting a Circle to file.")

  def visit_square(self, square):
    print("Exporting a Square to file.")
```
```python
# shape.py

from abc import ABC, abstractmethod

class Shape(ABC):
  @abstractmethod
  def accept(self, visitor):
    pass
```
```python
# circle.py

from shape import Shape

class Circle(Shape):
  def accept(self, visitor):
    visitor.visit_circle(self)
```
```python
# square.py

from shape import Shape

class Square(Shape):
  def accept(self, visitor):
    visitor.visit_square(self)
```
```python
# main.py

from circle import Circle
from square import Square
from render_visitor import RenderVisitor
from export_visitor import ExportVisitor

if __name__ == "__main__":
  shapes = [Circle(), Square()]

  render_visitor = RenderVisitor()
  export_visitor = ExportVisitor()

  print("Applying Render Visitor:")
  for shape in shapes:
    shape.accept(render_visitor)

  print("\nApplying Export Visitor:")
  for shape in shapes:
    shape.accept(export_visitor)
```

#### **JavaScript Implementation**
```javascript
// shapeVisitor.js

class ShapeVisitor {
  visitCircle(circle) {
    throw new Error("Method 'visitCircle()' must be implemented.");
  }

  visitSquare(square) {
    throw new Error("Method 'visitSquare()' must be implemented.");
  }
}

module.exports = ShapeVisitor;
```
```javascript
// renderVisitor.js

const ShapeVisitor = require("./shapeVisitor");

class RenderVisitor extends ShapeVisitor {
  visitCircle(circle) {
    console.log("Rendering a Circle.");
  }

  visitSquare(square) {
    console.log("Rendering a Square.");
  }
}

module.exports = RenderVisitor;
```
```javascript
// exportVisitor.js

const ShapeVisitor = require("./shapeVisitor");

class ExportVisitor extends ShapeVisitor {
  visitCircle(circle) {
    console.log("Exporting a Circle to file.");
  }

  visitSquare(square) {
    console.log("Exporting a Square to file.");
  }
}

module.exports = ExportVisitor;
```
```javascript
// shape.js

class Shape {
  accept(visitor) {
    throw new Error("Method 'accept()' must be implemented.");
  }
}

module.exports = Shape;
```
```javascript
// circle.js

const Shape = require("./shape");

class Circle extends Shape {
  accept(visitor) {
    visitor.visitCircle(this);
  }
}

module.exports = Circle;
```
```javascript
// square.js

const Shape = require("./shape");

class Square extends Shape {
  accept(visitor) {
    visitor.visitSquare(this);
  }
}

module.exports = Square;
```
```javascript
// main.js

const Circle = require("./circle");
const Square = require("./square");
const RenderVisitor = require("./renderVisitor");
const ExportVisitor = require("./exportVisitor");

const shapes = [new Circle(), new Square()];

const renderVisitor = new RenderVisitor();
const exportVisitor = new ExportVisitor();

console.log("Applying Render Visitor:");
shapes.forEach(shape => shape.accept(renderVisitor));

console.log("\nApplying Export Visitor:");
shapes.forEach(shape => shape.accept(exportVisitor));
```

### 📌 Running the Code
To test the **Visitor pattern**, run the following commands:

#### **Java**
```sh
cd Behavioral/Visitor/Java
javac *.java
java Main
```

#### **C#**
```sh
cd Behavioral/Visitor/CSharp
dotnet build
dotnet run
```

#### **C++**
```sh
cd Behavioral/Visitor/Cpp
g++ *.cpp -o visitor
./visitor
```

#### **Python**
```sh
cd Behavioral/Visitor/Python
python3 main.py
```

#### **JavaScript**
```sh
cd Behavioral/Visitor/JavaScript
node main.js
```

### 📌 Expected Output
```
Applying Render Visitor:
Rendering a Circle.
Rendering a Square.

Applying Export Visitor:
Exporting a Circle to file.
Exporting a Square to file.
```

## 📌 Summary
- Encapsulates behavior in separate visitor classes instead of modifying element classes.
- Allows adding new operations without altering shape classes.
- Follows the Open/Closed Principle, making the system more scalable and flexible.