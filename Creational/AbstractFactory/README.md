# Abstract Factory Pattern

## 📌 What is the Abstract Factory Pattern?
The **Abstract Factory pattern** is a creational design pattern that provides an interface for creating **families of related objects** **without specifying their concrete classes**. It is an extension of the Factory Method pattern but allows the creation of multiple related objects.

## 📌 When to Use Abstract Factory
Use the **Abstract Factory pattern** when:
- You need to create **families of related products** (e.g., different UI components for Windows and MacOS).
- Your code **should not depend on specific concrete classes**.
- You want to **ensure consistency** across product families.

## 📌 Implementation in Different Languages
Each language implements the **Abstract Factory pattern** differently based on its capabilities.

### **Java Implementation**
```java
// RenderMode.java
public enum RenderMode {
  TWO_D,
  THREE_D
}
```
```java
// ShapeType.java
public enum ShapeType {
  CIRCLE,
  SQUARE
}
```
```java
// Shape.java
public interface Shape {
  void draw();
}
```
```java
// Renderer.java
public interface Renderer {
  void render();
}
```
```java
// Circle.java
public class Circle implements Shape {
  @Override
  public void draw() {
    System.out.println("Drawing a Circle");
  }
}
```
```java
// Square.java
public class Square implements Shape {
  @Override
  public void draw() {
    System.out.println("Drawing a Square");
  }
}
```
```java
// TwoDRenderer.java
public class TwoDRenderer implements Renderer {
  @Override
  public void render() {
    System.out.println("Rendering in 2D mode");
  }
}
```
```java
// ThreeDRenderer.java
public class ThreeDRenderer implements Renderer {
  @Override
  public void render() {
    System.out.println("Rendering in 3D mode");
  }
}
```
```java
// ShapeFactory.java
public interface ShapeFactory {
  Shape createShape(ShapeType type);
  Renderer createRenderer();
}
```
```java
// TwoDShapeFactory.java
public class TwoDShapeFactory implements ShapeFactory {
  @Override
  public Shape createShape(ShapeType type) {
    switch (type) {
      case CIRCLE:
        return new Circle();
      case SQUARE:
        return new Square();
      default:
        throw new IllegalArgumentException("Unknown shape type: " + type);
    }
  }

  @Override
  public Renderer createRenderer() {
    return new TwoDRenderer();
  }
}
```
```java
// ThreeDShapeFactory.java
public class ThreeDShapeFactory implements ShapeFactory {
  @Override
  public Shape createShape(ShapeType type) {
    switch (type) {
      case CIRCLE:
        return new Circle();
      case SQUARE:
        return new Square();
      default:
        throw new IllegalArgumentException("Unknown shape type: " + type);
    }
  }

  @Override
  public Renderer createRenderer() {
    return new ThreeDRenderer();
  }
}
```
```java
// Main.java
public class Main {
  public static void main(String[] args) {
    // Loop through rendering modes
    for (RenderMode mode : RenderMode.values()) {
      ShapeFactory factory;

      // Select the factory based on mode
      switch (mode) {
        case TWO_D:
          factory = new TwoDShapeFactory();
          break;
        case THREE_D:
          factory = new ThreeDShapeFactory();
          break;
        default:
          throw new IllegalArgumentException("Unknown mode: " + mode);
      }

      // Loop through shape types
      for (ShapeType shapeType : ShapeType.values()) {
        System.out.println("\n=== Mode: " + mode + ", Shape: " + shapeType + " ===");
        
        // Create and use products
        Shape shape = factory.createShape(shapeType);
        Renderer renderer = factory.createRenderer();

        shape.draw();
        renderer.render();
      }
    }
  }
}
```

### **C# Implementation**
```csharp
// RenderMode.cs
public enum RenderMode {
  TWO_D,
  THREE_D
}
```
```csharp
// ShapeType.cs
public enum ShapeType {
  CIRCLE,
  SQUARE
}
```
```csharp
// IShape.cs
public interface IShape {
  void Draw();
}
```
```csharp
// IRenderer.cs
public interface IRenderer {
  void Render();
}
```
```csharp
// Circle.cs
using System;

public class Circle : IShape {
  public void Draw() {
    Console.WriteLine("Drawing a Circle");
  }
}
```
```csharp
// Square.cs
using System;

public class Square : IShape {
  public void Draw() {
    Console.WriteLine("Drawing a Square");
  }
}
```
```csharp
// TwoDRenderer.cs
using System;

public class TwoDRenderer : IRenderer {
  public void Render() {
    Console.WriteLine("Rendering in 2D mode");
  }
}
```
```csharp
// ThreeDRenderer.cs
using System;

public class ThreeDRenderer : IRenderer {
  public void Render() {
    Console.WriteLine("Rendering in 3D mode");
  }
}
```
```csharp
// IShapeFactory.cs
public interface IShapeFactory {
  IShape CreateShape(ShapeType type);
  IRenderer CreateRenderer();
}
```
```csharp
// TwoDShapeFactory.cs
using System;

public class TwoDShapeFactory : IShapeFactory {
  public IShape CreateShape(ShapeType type) {
    return type switch {
      ShapeType.CIRCLE => new Circle(),
      ShapeType.SQUARE => new Square(),
      _ => throw new ArgumentException($"Unknown shape type: {type}")
    };
  }

  public IRenderer CreateRenderer() {
    return new TwoDRenderer();
  }
}
```
```csharp
// ThreeDShapeFactory.cs
using System;

public class ThreeDShapeFactory : IShapeFactory {
  public IShape CreateShape(ShapeType type) {
    return type switch {
      ShapeType.CIRCLE => new Circle(),
      ShapeType.SQUARE => new Square(),
      _ => throw new ArgumentException($"Unknown shape type: {type}")
    };
  }

  public IRenderer CreateRenderer() {
    return new ThreeDRenderer();
  }
}
```
```csharp
// Program.cs
using System;

class Program {
  static void Main() {
    // Loop through both rendering modes
    foreach (RenderMode mode in Enum.GetValues(typeof(RenderMode))) {
      IShapeFactory factory = mode switch {
        RenderMode.TWO_D => new TwoDShapeFactory(),
        RenderMode.THREE_D => new ThreeDShapeFactory(),
        _ => throw new ArgumentException($"Unknown render mode: {mode}")
      };

      // Loop through both shape types
      foreach (ShapeType shapeType in Enum.GetValues(typeof(ShapeType))) {
        Console.WriteLine($"\n=== Mode: {mode}, Shape: {shapeType} ===");

        // Create and use products
        IShape shape = factory.CreateShape(shapeType);
        IRenderer renderer = factory.CreateRenderer();

        shape.Draw();
        renderer.Render();
      }
    }
  }
}
```

### **C++ Implementation**
```cpp
// RenderMode.h
#ifndef RENDER_MODE_H
#define RENDER_MODE_H

enum class RenderMode {
  TWO_D,
  THREE_D
};

#endif // RENDER_MODE_H
```
```cpp
// ShapeType.h
#ifndef SHAPE_TYPE_H
#define SHAPE_TYPE_H

enum class ShapeType {
  CIRCLE,
  SQUARE
};

#endif // SHAPE_TYPE_H
```
```cpp
// IShape.h
#ifndef I_SHAPE_H
#define I_SHAPE_H

class IShape {
public:
  virtual void draw() = 0;
  virtual ~IShape() = default;
};

#endif // I_SHAPE_H
```
```cpp
// IRenderer.h
#ifndef I_RENDERER_H
#define I_RENDERER_H

class IRenderer {
public:
  virtual void render() = 0;
  virtual ~IRenderer() = default;
};

#endif // I_RENDERER_H

```
```cpp
// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"

class Circle : public IShape {
public:
  void draw() override;
};

#endif // CIRCLE_H
```
```cpp
// Circle.cpp
#include "Circle.h"
#include <iostream>

void Circle::draw() {
  std::cout << "Drawing a Circle" << std::endl;
}
```
```cpp
// Square.h
#ifndef SQUARE_H
#define SQUARE_H

#include "IShape.h"

class Square : public IShape {
public:
  void draw() override;
};

#endif // SQUARE_H
```
```cpp
// Square.cpp
#include "Square.h"
#include <iostream>

void Square::draw() {
  std::cout << "Drawing a Square" << std::endl;
}
```
```cpp
// TwoDRenderer.h
#ifndef TWO_D_RENDERER_H
#define TWO_D_RENDERER_H

#include "IRenderer.h"

class TwoDRenderer : public IRenderer {
public:
  void render() override;
};

#endif // TWO_D_RENDERER_H
```
```cpp
// TwoDRenderer.cpp
#include "TwoDRenderer.h"
#include <iostream>

void TwoDRenderer::render() {
  std::cout << "Rendering in 2D mode" << std::endl;
}
```
```cpp
// ThreeDRenderer.h
#ifndef THREE_D_RENDERER_H
#define THREE_D_RENDERER_H

#include "IRenderer.h"

class ThreeDRenderer : public IRenderer {
public:
  void render() override;
};

#endif // THREE_D_RENDERER_H
```
```cpp
// ThreeDRenderer.cpp
#include "ThreeDRenderer.h"
#include <iostream>

void ThreeDRenderer::render() {
  std::cout << "Rendering in 3D mode" << std::endl;
}
```
```cpp
// IShapeFactory.h
#ifndef I_SHAPE_FACTORY_H
#define I_SHAPE_FACTORY_H

#include "IShape.h"
#include "IRenderer.h"
#include "ShapeType.h"

class IShapeFactory {
public:
  virtual IShape* createShape(ShapeType type) = 0;
  virtual IRenderer* createRenderer() = 0;
  virtual ~IShapeFactory() = default;
};

#endif // I_SHAPE_FACTORY_H
```
```cpp
// TwoDShapeFactory.h
#ifndef TWO_D_SHAPE_FACTORY_H
#define TWO_D_SHAPE_FACTORY_H

#include "IShapeFactory.h"

class TwoDShapeFactory : public IShapeFactory {
public:
  IShape* createShape(ShapeType type) override;
  IRenderer* createRenderer() override;
};

#endif // TWO_D_SHAPE_FACTORY_H
```
```cpp
// TwoDShapeFactory.cpp
#include "TwoDShapeFactory.h"
#include "Circle.h"
#include "Square.h"
#include "TwoDRenderer.h"
#include <stdexcept>

IShape* TwoDShapeFactory::createShape(ShapeType type) {
  switch (type) {
    case ShapeType::CIRCLE:
      return new Circle();
    case ShapeType::SQUARE:
      return new Square();
    default:
      throw std::invalid_argument("Unknown shape type");
  }
}

IRenderer* TwoDShapeFactory::createRenderer() {
  return new TwoDRenderer();
}
```
```cpp
// ThreeDShapeFactory.h
#ifndef THREE_D_SHAPE_FACTORY_H
#define THREE_D_SHAPE_FACTORY_H

#include "IShapeFactory.h"

class ThreeDShapeFactory : public IShapeFactory {
public:
  IShape* createShape(ShapeType type) override;
  IRenderer* createRenderer() override;
};

#endif // THREE_D_SHAPE_FACTORY_H
```
```cpp
// ThreeDShapeFactory.cpp
#include "ThreeDShapeFactory.h"
#include "Circle.h"
#include "Square.h"
#include "ThreeDRenderer.h"
#include <stdexcept>

IShape* ThreeDShapeFactory::createShape(ShapeType type) {
  switch (type) {
    case ShapeType::CIRCLE:
      return new Circle();
    case ShapeType::SQUARE:
      return new Square();
    default:
      throw std::invalid_argument("Unknown shape type");
  }
}

IRenderer* ThreeDShapeFactory::createRenderer() {
  return new ThreeDRenderer();
}
```
```cpp
#include <iostream>
#include "RenderMode.h"
#include "ShapeType.h"
#include "IShapeFactory.h"
#include "TwoDShapeFactory.h"
#include "ThreeDShapeFactory.h"

int main() {
  for (RenderMode mode : {RenderMode::TWO_D, RenderMode::THREE_D}) {
    IShapeFactory* factory;

    switch (mode) {
      case RenderMode::TWO_D:
        factory = new TwoDShapeFactory();
        break;
      case RenderMode::THREE_D:
        factory = new ThreeDShapeFactory();
        break;
      default:
        throw std::invalid_argument("Unknown render mode");
    }

    for (ShapeType shapeType : {ShapeType::CIRCLE, ShapeType::SQUARE}) {
      std::cout << "\n=== Mode: " << (mode == RenderMode::TWO_D ? "TWO_D" : "THREE_D") 
                << ", Shape: " << (shapeType == ShapeType::CIRCLE ? "CIRCLE" : "SQUARE") << " ===\n";

      IShape* shape = factory->createShape(shapeType);
      IRenderer* renderer = factory->createRenderer();

      shape->draw();
      renderer->render();

      delete shape;
      delete renderer;
    }

    delete factory;
  }

  return 0;
}
```

### **Python Implementation**
```python
# render_mode.py
from enum import Enum

class RenderMode(Enum):
  TWO_D = "TWO_D"
  THREE_D = "THREE_D"
```
```python
# shape_type.py
from enum import Enum

class ShapeType(Enum):
  CIRCLE = "CIRCLE"
  SQUARE = "SQUARE"
```
```python
# shape.py
from abc import ABC, abstractmethod

class Shape(ABC):
  @abstractmethod
  def draw(self):
    pass
```
```python
# renderer.py
from abc import ABC, abstractmethod

class Renderer(ABC):
  @abstractmethod
  def render(self):
    pass
```
```python
# circle.py
from shape import Shape

class Circle(Shape):
  def draw(self):
    print("Drawing a Circle")
```
```python
# square.py
from shape import Shape

class Square(Shape):
  def draw(self):
    print("Drawing a Square")
```
```python
# two_d_renderer.py
from renderer import Renderer

class TwoDRenderer(Renderer):
  def render(self):
    print("Rendering in 2D mode")
```
```python
# three_d_renderer.py
from renderer import Renderer

class ThreeDRenderer(Renderer):
  def render(self):
    print("Rendering in 3D mode")
```
```python
# shape_factory.py
from abc import ABC, abstractmethod
from shape_type import ShapeType
from shape import Shape
from renderer import Renderer

class ShapeFactory(ABC):
  @abstractmethod
  def create_shape(self, shape_type: ShapeType) -> Shape:
    pass

  @abstractmethod
  def create_renderer(self) -> Renderer:
    pass
```
```python
# two_d_shape_factory.py
from shape_factory import ShapeFactory
from shape_type import ShapeType
from circle import Circle
from square import Square
from two_d_renderer import TwoDRenderer

class TwoDShapeFactory(ShapeFactory):
  def create_shape(self, shape_type: ShapeType):
    match shape_type:
      case ShapeType.CIRCLE:
        return Circle()
      case ShapeType.SQUARE:
        return Square()
      case _:
        raise ValueError(f"Unknown shape type: {shape_type}")

  def create_renderer(self):
    return TwoDRenderer()
```
```python
# three_d_shape_factory.py
from shape_factory import ShapeFactory
from shape_type import ShapeType
from circle import Circle
from square import Square
from three_d_renderer import ThreeDRenderer

class ThreeDShapeFactory(ShapeFactory):
  def create_shape(self, shape_type: ShapeType):
    match shape_type:
      case ShapeType.CIRCLE:
        return Circle()
      case ShapeType.SQUARE:
        return Square()
      case _:
        raise ValueError(f"Unknown shape type: {shape_type}")

  def create_renderer(self):
    return ThreeDRenderer()
```
```python
# main.py
from render_mode import RenderMode
from shape_type import ShapeType
from two_d_shape_factory import TwoDShapeFactory
from three_d_shape_factory import ThreeDShapeFactory

if __name__ == "__main__":
  for mode in RenderMode:
    match mode:
      case RenderMode.TWO_D:
        factory = TwoDShapeFactory()
      case RenderMode.THREE_D:
        factory = ThreeDShapeFactory()
      case _:
        raise ValueError(f"Unknown render mode: {mode}")

    for shape_type in ShapeType:
      print(f"\n=== Mode: {mode.value}, Shape: {shape_type.value} ===")

      shape = factory.create_shape(shape_type)
      renderer = factory.create_renderer()

      shape.draw()
      renderer.render()
```

### **JavaScript Implementation**
```javascript
// renderMode.js
const RenderMode = Object.freeze({
  TWO_D: "TWO_D",
  THREE_D: "THREE_D"
});

module.exports = RenderMode;
```
```javascript
// shapeType.js
const ShapeType = Object.freeze({
  CIRCLE: "CIRCLE",
  SQUARE: "SQUARE"
});

module.exports = ShapeType;
```
```javascript
// shape.js
class Shape {
  draw() {
    throw new Error("Method 'draw()' must be implemented.");
  }
}

module.exports = Shape;
```
```javascript
// renderer.js
class Renderer {
  render() {
    throw new Error("Method 'render()' must be implemented.");
  }
}

module.exports = Renderer;
```
```javascript
// circle.js
const Shape = require("./shape");

class Circle extends Shape {
  draw() {
    console.log("Drawing a Circle");
  }
}

module.exports = Circle;
```
```javascript
// square.js
const Shape = require("./shape");

class Square extends Shape {
  draw() {
    console.log("Drawing a Square");
  }
}

module.exports = Square;
```
```javascript
// twoDRenderer.js
const Renderer = require("./renderer");

class TwoDRenderer extends Renderer {
  render() {
    console.log("Rendering in 2D mode");
  }
}

module.exports = TwoDRenderer;
```
```javascript
// threeDRenderer.js
const Renderer = require("./renderer");

class ThreeDRenderer extends Renderer {
  render() {
    console.log("Rendering in 3D mode");
  }
}

module.exports = ThreeDRenderer;
```
```javascript
// shapeFactory.js
class ShapeFactory {
  createShape(shapeType) {
    throw new Error("Method 'createShape()' must be implemented.");
  }

  createRenderer() {
    throw new Error("Method 'createRenderer()' must be implemented.");
  }
}

module.exports = ShapeFactory;
```
```javascript
// twoDShapeFactory.js
const ShapeFactory = require("./shapeFactory");
const ShapeType = require("./shapeType");
const Circle = require("./circle");
const Square = require("./square");
const TwoDRenderer = require("./twoDRenderer");

class TwoDShapeFactory extends ShapeFactory {
  createShape(shapeType) {
    switch (shapeType) {
      case ShapeType.CIRCLE:
        return new Circle();
      case ShapeType.SQUARE:
        return new Square();
      default:
        throw new Error(`Unknown shape type: ${shapeType}`);
    }
  }

  createRenderer() {
    return new TwoDRenderer();
  }
}

module.exports = TwoDShapeFactory;
```
```javascript
// threeDShapeFactory.js
const ShapeFactory = require("./shapeFactory");
const ShapeType = require("./shapeType");
const Circle = require("./circle");
const Square = require("./square");
const ThreeDRenderer = require("./threeDRenderer");

class ThreeDShapeFactory extends ShapeFactory {
  createShape(shapeType) {
    switch (shapeType) {
      case ShapeType.CIRCLE:
        return new Circle();
      case ShapeType.SQUARE:
        return new Square();
      default:
        throw new Error(`Unknown shape type: ${shapeType}`);
    }
  }

  createRenderer() {
    return new ThreeDRenderer();
  }
}

module.exports = ThreeDShapeFactory;
```
```javascript
// main.js
const RenderMode = require("./renderMode");
const ShapeType = require("./shapeType");
const TwoDShapeFactory = require("./twoDShapeFactory");
const ThreeDShapeFactory = require("./threeDShapeFactory");

for (const mode of Object.values(RenderMode)) {
  let factory;
  
  switch (mode) {
    case RenderMode.TWO_D:
      factory = new TwoDShapeFactory();
      break;
    case RenderMode.THREE_D:
      factory = new ThreeDShapeFactory();
      break;
    default:
      throw new Error(`Unknown render mode: ${mode}`);
  }

  for (const shapeType of Object.values(ShapeType)) {
    console.log(`\n=== Mode: ${mode}, Shape: ${shapeType} ===`);
    
    const shape = factory.createShape(shapeType);
    const renderer = factory.createRenderer();

    shape.draw();
    renderer.render();
  }
}
```

## 📌 Running the Code
To test the **Abstract Factory pattern**, run the following commands:

### **Java**
```sh
cd Creational/AbstractFactory/Java
javac *.java
java Main
```

### **C#**
```sh
cd Creational/AbstractFactory/CSharp
dotnet build
dotnet run
```

### **C++**
```sh
cd Creational/AbstractFactory/Cpp
g++ *.cpp -o abstract_factory
./abstract_factory
```

### **Python**
```sh
cd Creational/AbstractFactory/Python
python3 main.py
```

### **JavaScript**
```sh
cd Creational/AbstractFactory/JavaScript
node main.js
```

## 📌 Expected Output
```
=== Mode: TWO_D, Shape: CIRCLE ===
Drawing a Circle
Rendering in 2D mode

=== Mode: TWO_D, Shape: SQUARE ===
Drawing a Square
Rendering in 2D mode

=== Mode: THREE_D, Shape: CIRCLE ===
Drawing a Circle
Rendering in 3D mode

=== Mode: THREE_D, Shape: SQUARE ===
Drawing a Square
Rendering in 3D mode
```

## 📌 Summary
- Abstract Factory allows the creation of families of related objects without specifying their concrete classes.
- Useful for frameworks and libraries that require extensibility.
- Ensures consistency across a group of objects.