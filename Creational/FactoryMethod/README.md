# Factory Method Pattern

## 📌 What is the Factory Method Pattern?
The **Factory Method pattern** provides an interface for creating objects in a **superclass**, but allows **subclasses** to alter the type of objects that will be created. Instead of calling a constructor directly, object creation is delegated to **factory methods**.

## 📌 When to Use Factory Method
Use the **Factory Method pattern** when:
- You want to delegate **object creation** to subclasses.
- You need to **extend the creation logic** without modifying existing code.
- A class **doesn’t know what specific subclass it should instantiate**.

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