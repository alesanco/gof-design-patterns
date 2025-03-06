# Factory Method Pattern

## 📌 What is the Factory Method Pattern?
The **Factory Method pattern** provides an interface for creating objects in a **superclass**, but allows **subclasses** to alter the type of objects that will be created. Instead of calling a constructor directly, object creation is delegated to **factory methods**.

## 📌 When to Use Factory Method
Use the **Factory Method pattern** when:
- You want to delegate **object creation** to subclasses.
- You need to **extend the creation logic** without modifying existing code.
- A class **doesn’t know what specific subclass it should instantiate**.

## 📌 Example: Product and Creator
Imagine we are designing a **Product Creation System** where different types of products are created dynamically. Instead of instantiating products directly, we use a **Factory Method** to determine which product to create at runtime.

## 📌 Implementation in Different Languages
Each language implements the **Factory Method pattern** differently based on its capabilities.

### **Java Implementation**
```java
// Product.java
public interface Product {
  void use();
}
```
```java
// ConcreteProductA.java
public class ConcreteProductA implements Product {
  @Override
  public void use() {
    System.out.println("Using Product A");
  }
}
```
```java
// ConcreteProductB.java
public class ConcreteProductB implements Product {
  @Override
  public void use() {
    System.out.println("Using Product B");
  }
}

```
```java
// Creator.java
public abstract class Creator {
  public abstract Product createProduct();
}
```
```java
// ConcreteCreatorA.java
public class ConcreteCreatorA extends Creator {
  @Override
  public Product createProduct() {
    return new ConcreteProductA();
  }
}
```
```java
// ConcreteCreatorB.java
public class ConcreteCreatorB extends Creator {
  @Override
  public Product createProduct() {
    return new ConcreteProductB();
  }
}
```
```java
// Main.java
public class Main {
  public static void main(String[] args) {
    Creator creatorA = new ConcreteCreatorA();
    Product productA = creatorA.createProduct();
    productA.use();

    Creator creatorB = new ConcreteCreatorB();
    Product productB = creatorB.createProduct();
    productB.use();
  }
}
```

### **C# Implementation**
```csharp
// IProduct.cs
public interface IProduct {
  void Use();
}
```
```csharp
// ConcreteProductA.cs
using System;

public class ConcreteProductA : IProduct {
  public void Use() {
    Console.WriteLine("Using Product A");
  }
}
```
```csharp
// ConcreteProductB.cs
using System;

public class ConcreteProductB : IProduct {
  public void Use() {
    Console.WriteLine("Using Product B");
  }
}
```
```csharp
// Creator.cs
public abstract class Creator {
  public abstract IProduct CreateProduct();
}
```
```csharp
// ConcreteCreatorA.cs
public class ConcreteCreatorA : Creator {
  public override IProduct CreateProduct() {
    return new ConcreteProductA();
  }
}
```
```csharp
// ConcreteCreatorB.cs
public class ConcreteCreatorB : Creator {
  public override IProduct CreateProduct() {
    return new ConcreteProductB();
  }
}
```
```csharp
// Program.cs
using System;

class Program {
  static void Main() {
    Creator creatorA = new ConcreteCreatorA();
    IProduct productA = creatorA.CreateProduct();
    productA.Use();

    Creator creatorB = new ConcreteCreatorB();
    IProduct productB = creatorB.CreateProduct();
    productB.Use();
  }
}
```

### **C++ Implementation**
```cpp
// Product.h
#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
public:
  virtual void use() = 0;
  virtual ~Product() = default;
};

#endif // PRODUCT_H
```
```cpp
// ConcreteProductA.h
#ifndef CONCRETE_PRODUCT_A_H
#define CONCRETE_PRODUCT_A_H

#include "Product.h"

class ConcreteProductA : public Product {
public:
  void use() override;
};

#endif // CONCRETE_PRODUCT_A_H
```
```cpp
// ConcreteProductA.cpp
#include "ConcreteProductA.h"
#include <iostream>

void ConcreteProductA::use() {
  std::cout << "Using Product A" << std::endl;
}
```
```cpp
// ConcreteProductB.h
#ifndef CONCRETE_PRODUCT_B_H
#define CONCRETE_PRODUCT_B_H

#include "Product.h"

class ConcreteProductB : public Product {
public:
  void use() override;
};

#endif // CONCRETE_PRODUCT_B_H
```
```cpp
// ConcreteProductB.cpp
#include "ConcreteProductB.h"
#include <iostream>

void ConcreteProductB::use() {
  std::cout << "Using Product B" << std::endl;
}
```
```cpp
// Creator.h
#ifndef CREATOR_H
#define CREATOR_H

#include "Product.h"

class Creator {
public:
  virtual Product* createProduct() = 0;
  virtual ~Creator() = default;
};

#endif // CREATOR_H
```
```cpp
// ConcreteCreatorA.h
#ifndef CONCRETE_CREATOR_A_H
#define CONCRETE_CREATOR_A_H

#include "Creator.h"

class ConcreteCreatorA : public Creator {
public:
  Product* createProduct() override;
};

#endif // CONCRETE_CREATOR_A_H
```
```cpp
// ConcreteCreatorA.cpp
#include "ConcreteCreatorA.h"
#include "ConcreteProductA.h"

Product* ConcreteCreatorA::createProduct() {
  return new ConcreteProductA();
}
```
```cpp
// ConcreteCreatorB.h
#ifndef CONCRETE_CREATOR_B_H
#define CONCRETE_CREATOR_B_H

#include "Creator.h"

class ConcreteCreatorB : public Creator {
public:
  Product* createProduct() override;
};

#endif // CONCREATOR_B_H
```
```cpp
// ConcreteCreatorB.cpp
#include "ConcreteCreatorB.h"
#include "ConcreteProductB.h"

Product* ConcreteCreatorB::createProduct() {
  return new ConcreteProductB();
}
```
```cpp
// Main.cpp
#include <iostream>
#include "ConcreteCreatorA.h"
#include "ConcreteCreatorB.h"

int main() {
  Creator* creatorA = new ConcreteCreatorA();
  Product* productA = creatorA->createProduct();
  productA->use();

  Creator* creatorB = new ConcreteCreatorB();
  Product* productB = creatorB->createProduct();
  productB->use();

  // Clean up memory
  delete productA;
  delete productB;
  delete creatorA;
  delete creatorB;

  return 0;
}
```

### **Python Implementation**
```python
# product.py
from abc import ABC, abstractmethod

class Product(ABC):
  @abstractmethod
  def use(self):
    pass
```
```python
# concrete_product_a.py
from product import Product

class ConcreteProductA(Product):
  def use(self):
    print("Using Product A")
```
```python
# concrete_product_b.py
from product import Product

class ConcreteProductB(Product):
  def use(self):
    print("Using Product B")
```
```python
# creator.py
from abc import ABC, abstractmethod
from product import Product

class Creator(ABC):
  @abstractmethod
  def create_product(self) -> Product:
    pass
```
```python
# concrete_creator_a.py
from creator import Creator
from concrete_product_a import ConcreteProductA

class ConcreteCreatorA(Creator):
  def create_product(self) -> ConcreteProductA:
    return ConcreteProductA()
```
```python
# concrete_creator_b.py
from creator import Creator
from concrete_product_b import ConcreteProductB

class ConcreteCreatorB(Creator):
  def create_product(self) -> ConcreteProductB:
    return ConcreteProductB()
```
```python
# main.py
from concrete_creator_a import ConcreteCreatorA
from concrete_creator_b import ConcreteCreatorB

if __name__ == "__main__":
  creator_a = ConcreteCreatorA()
  product_a = creator_a.create_product()
  product_a.use()

  creator_b = ConcreteCreatorB()
  product_b = creator_b.create_product()
  product_b.use()
```

### **JavaScript Implementation**
```javascript
// product.js
class Product {
  use() {
    throw new Error("Method 'use()' must be implemented.");
  }
}

module.exports = Product;
```
```javascript
// concreteProductA.js
const Product = require("./product");

class ConcreteProductA extends Product {
  use() {
    console.log("Using Product A");
  }
}

module.exports = ConcreteProductA;
```
```javascript
const Product = require("./product");

class ConcreteProductB extends Product {
  use() {
    console.log("Using Product B");
  }
}

module.exports = ConcreteProductB;
```
```javascript
// creator.js
class Creator {
  createProduct() {
    throw new Error("Method 'createProduct()' must be implemented.");
  }
}

module.exports = Creator;
```
```javascript
// concreteCreatorA.js
const Creator = require("./creator");
const ConcreteProductA = require("./concreteProductA");

class ConcreteCreatorA extends Creator {
  createProduct() {
    return new ConcreteProductA();
  }
}

module.exports = ConcreteCreatorA;
```
```javascript
// concreteCreatorB.js
const Creator = require("./creator");
const ConcreteProductB = require("./concreteProductB");

class ConcreteCreatorB extends Creator {
  createProduct() {
    return new ConcreteProductB();
  }
}

module.exports = ConcreteCreatorB;
```
```javascript
// main.js
const ConcreteCreatorA = require("./concreteCreatorA");
const ConcreteCreatorB = require("./concreteCreatorB");

const creatorA = new ConcreteCreatorA();
const productA = creatorA.createProduct();
productA.use();

const creatorB = new ConcreteCreatorB();
const productB = creatorB.createProduct();
productB.use();
```

## 📌 Running the Code
To test the **Factory Method pattern**, run the following commands:

### **Java**
```sh
cd Creational/FactoryMethod/Java
javac *.java
java Main
```

### **C#**
```sh
cd Creational/FactoryMethod/CSharp
dotnet build
dotnet run
```

### **C++**
```sh
cd Creational/FactoryMethod/Cpp
g++ *.cpp -o factory_method
./factory_method
```

### **Python**
```sh
cd Creational/FactoryMethod/Python
python3 main.py
```

### **JavaScript**
```sh
cd Creational/FactoryMethod/JavaScript
node main.js
```

## 📌 Expected Output
```
Using Product A
Using Product B
```

## 📌 Summary
- Factory Method allows object creation to be delegated to subclasses.
- Useful for frameworks and libraries that rely on extensibility.
- Provides flexibility by avoiding direct object instantiation.