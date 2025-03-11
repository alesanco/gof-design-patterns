# Decorator Pattern

## 📌 What is the Decorator Pattern?
The **Decorator Pattern** is a structural design pattern that allows adding **new behaviors to objects dynamically** without modifying their existing structure. It uses **composition instead of inheritance**, enabling greater flexibility in extending functionality.

## 📌 When to Use Decorator
Use the **Decorator pattern** when:

- You want to **add responsibilities dynamically** to objects **at runtime**.
- Extending a class via **subclassing is impractical** or would lead to an excessive number of subclasses.
- You need a **flexible alternative to subclassing** for extending functionality.

## 📌 Example: Coffee Customization System
Imagine a **coffee ordering system** where customers can **customize their coffee** with additional ingredients like **milk, sugar, or caramel**. Instead of modifying the base `Coffee` class for each variation, we use **decorators** to dynamically add these features.

### 📌 Implementation in Different Languages
Each language implements the **Decorator pattern** differently based on its capabilities.

#### **Java Implementation**
```java
// Coffee.java

public interface Coffee {
  String getDescription();
  double getCost();
}
```
```java
// SimpleCoffee.java

public class SimpleCoffee implements Coffee {
  @Override
  public String getDescription() {
    return "Simple Coffee";
  }

  @Override
  public double getCost() {
    return 5.0;
  }
}
```
```java
// CoffeeDecorator.java

public abstract class CoffeeDecorator implements Coffee {
  protected Coffee decoratedCoffee;

  public CoffeeDecorator(Coffee coffee) {
    this.decoratedCoffee = coffee;
  }

  @Override
  public String getDescription() {
    return decoratedCoffee.getDescription();
  }

  @Override
  public double getCost() {
    return decoratedCoffee.getCost();
  }
}
```
```java
// MilkDecorator.java

public class MilkDecorator extends CoffeeDecorator {
  public MilkDecorator(Coffee coffee) {
    super(coffee);
  }

  @Override
  public String getDescription() {
    return decoratedCoffee.getDescription() + ", Milk";
  }

  @Override
  public double getCost() {
    return decoratedCoffee.getCost() + 1.5;
  }
}
```
```java
// SugarDecorator.java

public class SugarDecorator extends CoffeeDecorator {
  public SugarDecorator(Coffee coffee) {
    super(coffee);
  }

  @Override
  public String getDescription() {
    return decoratedCoffee.getDescription() + ", Sugar";
  }

  @Override
  public double getCost() {
    return decoratedCoffee.getCost() + 0.5;
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    Coffee basicCoffee = new SimpleCoffee();
    System.out.println(basicCoffee.getDescription() + " -> $" + basicCoffee.getCost());

    Coffee milkCoffee = new MilkDecorator(basicCoffee);
    System.out.println(milkCoffee.getDescription() + " -> $" + milkCoffee.getCost());

    Coffee sugarMilkCoffee = new SugarDecorator(milkCoffee);
    System.out.println(sugarMilkCoffee.getDescription() + " -> $" + sugarMilkCoffee.getCost());
  }
}
```

#### **C# Implementation**
```csharp
// ICoffee.cs

public interface ICoffee {
  string GetDescription();
  double GetCost();
}
```
```csharp
// SimpleCoffee.cs

public class SimpleCoffee : ICoffee {
  public string GetDescription() {
    return "Simple Coffee";
  }

  public double GetCost() {
    return 5.0;
  }
}
```
```csharp
// CoffeeDecorator.cs

public abstract class CoffeeDecorator : ICoffee {
  protected ICoffee decoratedCoffee;

  public CoffeeDecorator(ICoffee coffee) {
    this.decoratedCoffee = coffee;
  }

  public virtual string GetDescription() {
    return decoratedCoffee.GetDescription();
  }

  public virtual double GetCost() {
    return decoratedCoffee.GetCost();
  }
}
```
```csharp
// MilkDecorator.cs

public class MilkDecorator : CoffeeDecorator {
  public MilkDecorator(ICoffee coffee) : base(coffee) {}

  public override string GetDescription() {
    return decoratedCoffee.GetDescription() + ", Milk";
  }

  public override double GetCost() {
    return decoratedCoffee.GetCost() + 1.5;
  }
}
```
```csharp
// SugarDecorator.cs

public class SugarDecorator : CoffeeDecorator {
  public SugarDecorator(ICoffee coffee) : base(coffee) {}

  public override string GetDescription() {
    return decoratedCoffee.GetDescription() + ", Sugar";
  }

  public override double GetCost() {
    return decoratedCoffee.GetCost() + 0.5;
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    ICoffee basicCoffee = new SimpleCoffee();
    Console.WriteLine($"{basicCoffee.GetDescription()} -> ${basicCoffee.GetCost()}");

    ICoffee milkCoffee = new MilkDecorator(basicCoffee);
    Console.WriteLine($"{milkCoffee.GetDescription()} -> ${milkCoffee.GetCost()}");

    ICoffee sugarMilkCoffee = new SugarDecorator(milkCoffee);
    Console.WriteLine($"{sugarMilkCoffee.GetDescription()} -> ${sugarMilkCoffee.GetCost()}");
  }
}
```

#### **C++ Implementation**
```cpp
// ICoffee.h

#ifndef ICOFFEE_H
#define ICOFFEE_H

#include <string>

class ICoffee {
public:
  virtual ~ICoffee() = default;
  virtual std::string getDescription() const = 0;
  virtual double getCost() const = 0;
};

#endif // ICOFFEE_H
```
```cpp
// SimpleCoffee.h

#ifndef SIMPLECOFFEE_H
#define SIMPLECOFFEE_H

#include "ICoffee.h"

class SimpleCoffee : public ICoffee {
public:
  std::string getDescription() const override;
  double getCost() const override;
};

#endif // SIMPLECOFFEE_H
```
```cpp
// SimpleCoffee.cpp

#include "SimpleCoffee.h"

std::string SimpleCoffee::getDescription() const {
  return "Simple Coffee";
}

double SimpleCoffee::getCost() const {
  return 5.0;
}
```
```cpp
// CoffeeDecorator.h

#ifndef COFFEEDECORATOR_H
#define COFFEEDECORATOR_H

#include "ICoffee.h"
#include <memory>

class CoffeeDecorator : public ICoffee {
protected:
  std::unique_ptr<ICoffee> decoratedCoffee;

public:
  CoffeeDecorator(std::unique_ptr<ICoffee> coffee);
  std::string getDescription() const override;
  double getCost() const override;
};

#endif // COFFEEDECORATOR_H
```
```cpp
// CoffeeDecorator.cpp

#include "CoffeeDecorator.h"

CoffeeDecorator::CoffeeDecorator(std::unique_ptr<ICoffee> coffee)
  : decoratedCoffee(std::move(coffee)) {}

std::string CoffeeDecorator::getDescription() const {
  return decoratedCoffee->getDescription();
}

double CoffeeDecorator::getCost() const {
  return decoratedCoffee->getCost();
}
```
```cpp
// MilkDecorator.h

#ifndef MILKDECORATOR_H
#define MILKDECORATOR_H

#include "CoffeeDecorator.h"

class MilkDecorator : public CoffeeDecorator {
public:
  MilkDecorator(std::unique_ptr<ICoffee> coffee);
  std::string getDescription() const override;
  double getCost() const override;
};

#endif // MILKDECORATOR_H
```
```cpp
// MilkDecorator.cpp

#include "MilkDecorator.h"

MilkDecorator::MilkDecorator(std::unique_ptr<ICoffee> coffee)
  : CoffeeDecorator(std::move(coffee)) {}

std::string MilkDecorator::getDescription() const {
  return decoratedCoffee->getDescription() + ", Milk";
}

double MilkDecorator::getCost() const {
  return decoratedCoffee->getCost() + 1.5;
}
```
```cpp
// SugarDecorator.h

#ifndef SUGARDECORATOR_H
#define SUGARDECORATOR_H

#include "CoffeeDecorator.h"

class SugarDecorator : public CoffeeDecorator {
public:
  SugarDecorator(std::unique_ptr<ICoffee> coffee);
  std::string getDescription() const override;
  double getCost() const override;
};

#endif // SUGARDECORATOR_H
```
```cpp
// SugarDecorator.cpp

#include "SugarDecorator.h"

SugarDecorator::SugarDecorator(std::unique_ptr<ICoffee> coffee)
  : CoffeeDecorator(std::move(coffee)) {}

std::string SugarDecorator::getDescription() const {
  return decoratedCoffee->getDescription() + ", Sugar";
}

double SugarDecorator::getCost() const {
  return decoratedCoffee->getCost() + 0.5;
}
```
```cpp
// Main.cpp

#include "SimpleCoffee.h"
#include "MilkDecorator.h"
#include "SugarDecorator.h"
#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<ICoffee> basicCoffee = std::make_unique<SimpleCoffee>();
  std::cout << basicCoffee->getDescription() << " -> $" << basicCoffee->getCost() << std::endl;

  std::unique_ptr<ICoffee> milkCoffee = std::make_unique<MilkDecorator>(std::move(basicCoffee));
  std::cout << milkCoffee->getDescription() << " -> $" << milkCoffee->getCost() << std::endl;

  std::unique_ptr<ICoffee> sugarMilkCoffee = std::make_unique<SugarDecorator>(std::move(milkCoffee));
  std::cout << sugarMilkCoffee->getDescription() << " -> $" << sugarMilkCoffee->getCost() << std::endl;

  return 0;
}
```

#### **Python Implementation**
```python
# coffee.py

from abc import ABC, abstractmethod

class Coffee(ABC):
  @abstractmethod
  def get_description(self) -> str:
    pass

  @abstractmethod
  def get_cost(self) -> float:
    pass
```
```python
# simple_coffee.py

from coffee import Coffee

class SimpleCoffee(Coffee):
  def get_description(self) -> str:
    return "Simple Coffee"

  def get_cost(self) -> float:
    return 5.0
```
```python
# coffee_decorator.py

from coffee import Coffee

class CoffeeDecorator(Coffee):
  def __init__(self, coffee: Coffee):
    self._decorated_coffee = coffee

  def get_description(self) -> str:
    return self._decorated_coffee.get_description()

  def get_cost(self) -> float:
    return self._decorated_coffee.get_cost()
```
```python
# milk_decorator.py

from coffee_decorator import CoffeeDecorator

class MilkDecorator(CoffeeDecorator):
  def get_description(self) -> str:
    return self._decorated_coffee.get_description() + ", Milk"

  def get_cost(self) -> float:
    return self._decorated_coffee.get_cost() + 1.5
```
```python
# sugar_decorator.py

from coffee_decorator import CoffeeDecorator

class SugarDecorator(CoffeeDecorator):
  def get_description(self) -> str:
    return self._decorated_coffee.get_description() + ", Sugar"

  def get_cost(self) -> float:
    return self._decorated_coffee.get_cost() + 0.5
```
```python
# main.py

from simple_coffee import SimpleCoffee
from milk_decorator import MilkDecorator
from sugar_decorator import SugarDecorator

if __name__ == "__main__":
  basic_coffee = SimpleCoffee()
  print(f"{basic_coffee.get_description()} -> ${basic_coffee.get_cost()}")

  milk_coffee = MilkDecorator(basic_coffee)
  print(f"{milk_coffee.get_description()} -> ${milk_coffee.get_cost()}")

  sugar_milk_coffee = SugarDecorator(milk_coffee)
  print(f"{sugar_milk_coffee.get_description()} -> ${sugar_milk_coffee.get_cost()}")
```

#### **JavaScript Implementation**
```javascript
// coffee.js

class Coffee {
  getDescription() {
    throw new Error("Method 'getDescription()' must be implemented.");
  }

  getCost() {
    throw new Error("Method 'getCost()' must be implemented.");
  }
}

module.exports = Coffee;
```
```javascript
// simpleCoffee.js

const Coffee = require("./coffee");

class SimpleCoffee extends Coffee {
  getDescription() {
    return "Simple Coffee";
  }

  getCost() {
    return 5.0;
  }
}

module.exports = SimpleCoffee;
```
```javascript
// coffeeDecorator.js

const Coffee = require("./coffee");

class CoffeeDecorator extends Coffee {
  constructor(coffee) {
    super();
    this.decoratedCoffee = coffee;
  }

  getDescription() {
    return this.decoratedCoffee.getDescription();
  }

  getCost() {
    return this.decoratedCoffee.getCost();
  }
}

module.exports = CoffeeDecorator;
```
```javascript
// milkDecorator.js

const CoffeeDecorator = require("./coffeeDecorator");

class MilkDecorator extends CoffeeDecorator {
  getDescription() {
    return this.decoratedCoffee.getDescription() + ", Milk";
  }

  getCost() {
    return this.decoratedCoffee.getCost() + 1.5;
  }
}

module.exports = MilkDecorator;
```
```javascript
// sugarDecorator.js

const CoffeeDecorator = require("./coffeeDecorator");

class SugarDecorator extends CoffeeDecorator {
  getDescription() {
    return this.decoratedCoffee.getDescription() + ", Sugar";
  }

  getCost() {
    return this.decoratedCoffee.getCost() + 0.5;
  }
}

module.exports = SugarDecorator;
```
```javascript
// main.js

const SimpleCoffee = require("./simpleCoffee");
const MilkDecorator = require("./milkDecorator");
const SugarDecorator = require("./sugarDecorator");

const basicCoffee = new SimpleCoffee();
console.log(`${basicCoffee.getDescription()} -> $${basicCoffee.getCost()}`);

const milkCoffee = new MilkDecorator(basicCoffee);
console.log(`${milkCoffee.getDescription()} -> $${milkCoffee.getCost()}`);

const sugarMilkCoffee = new SugarDecorator(milkCoffee);
console.log(`${sugarMilkCoffee.getDescription()} -> $${sugarMilkCoffee.getCost()}`);
```

### 📌 Running the Code
To test the **Decorator pattern**, run the following commands:

#### **Java**
```sh
cd Structural/Decorator/Java
javac *.java
java Main
```

#### **C#**
```sh
cd Structural/Decorator/CSharp
dotnet build
dotnet run
```

#### **C++**
```sh
cd Structural/Decorator/Cpp
g++ *.cpp -o decorator
./decorator
```

#### **Python**
```sh
cd Structural/Decorator/Python
python3 main.py
```

#### **JavaScript**
```sh
cd Structural/Decorator/JavaScript
node main.js
```

### 📌 Expected Output
```
Simple Coffee -> $5.0
Simple Coffee, Milk -> $6.5
Simple Coffee, Milk, Sugar -> $7.0
```

## 📌 Summary
- Adds responsibilities dynamically without modifying the base class.
- Avoids subclass explosion, offering a flexible alternative to inheritance.
- Follows the Open/Closed Principle, allowing behavior extension without modifying existing code.