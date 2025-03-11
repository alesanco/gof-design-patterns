# Builder Pattern

## 📌 What is the Builder Pattern?
The **Builder pattern** is a **creational design pattern** used to construct **complex objects step by step**. Instead of using large constructors with many parameters (**Telescoping Constructor Problem**), the Builder pattern **allows incremental construction** through a series of method calls.

## 📌 When to Use Builder
Use the **Builder pattern** when:

- You need to create objects with **many optional parameters**.
- The object construction process is **complicated**.
- You want to avoid **large constructors with multiple parameters**.
- You need an **immutable object** where all properties are set at once.

## 📌 Example: Car Builder
Imagine we are designing a **Car Builder** that allows us to create cars **step by step** with optional features:
- **Engine type** (e.g., Petrol, Diesel, Electric)
- **GPS system** (Yes/No)
- **Sunroof** (Yes/No)
- **Seats** (e.g., Standard, Leather)

Instead of a constructor with many parameters, we build the car incrementally.

### 📌 Implementation in Different Languages
Each language implements the **Builder pattern** differently based on its capabilities.

#### **Java Implementation**
```java
// Car.java

public class Car {
  private final String engine;
  private final boolean hasGPS;
  private final boolean hasSunroof;
  private final String seats;

  private Car(CarBuilder builder) {
    this.engine = builder.engine;
    this.hasGPS = builder.hasGPS;
    this.hasSunroof = builder.hasSunroof;
    this.seats = builder.seats;
  }

  public void showSpecifications() {
    System.out.println("Car Specifications:");
    System.out.println("Engine: " + engine);
    System.out.println("GPS: " + (hasGPS ? "Yes" : "No"));
    System.out.println("Sunroof: " + (hasSunroof ? "Yes" : "No"));
    System.out.println("Seats: " + seats);
  }

  // Builder Class
  public static class CarBuilder {
    private String engine;
    private boolean hasGPS;
    private boolean hasSunroof;
    private String seats;

    public CarBuilder setEngine(String engine) {
      this.engine = engine;
      return this;
    }

    public CarBuilder setGPS(boolean hasGPS) {
      this.hasGPS = hasGPS;
      return this;
    }

    public CarBuilder setSunroof(boolean hasSunroof) {
      this.hasSunroof = hasSunroof;
      return this;
    }

    public CarBuilder setSeats(String seats) {
      this.seats = seats;
      return this;
    }

    public Car build() {
      return new Car(this);
    }
  }
}
```
```java
// CarDirector.java

public class CarDirector {
  public Car buildLuxuryCar() {
    return new Car.CarBuilder()
            .setEngine("V8 Turbo")
            .setGPS(true)
            .setSunroof(true)
            .setSeats("Leather")
            .build();
  }

  public Car buildEconomyCar() {
    return new Car.CarBuilder()
            .setEngine("1.6L Petrol")
            .setGPS(false)
            .setSunroof(false)
            .setSeats("Standard")
            .build();
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    CarDirector director = new CarDirector();

    // Build a Luxury Car
    Car luxuryCar = director.buildLuxuryCar();
    System.out.println("\nLuxury Car:");
    luxuryCar.showSpecifications();

    // Build an Economy Car
    Car economyCar = director.buildEconomyCar();
    System.out.println("\nEconomy Car:");
    economyCar.showSpecifications();
  }
}
```

#### **C# Implementation**
```csharp
// Car.cs

using System;

public class Car {
  public string Engine { get; private set; }
  public bool HasGPS { get; private set; }
  public bool HasSunroof { get; private set; }
  public string Seats { get; private set; }

  private Car(CarBuilder builder) {
    Engine = builder.Engine ?? "Unknown Engine";
    HasGPS = builder.HasGPS;
    HasSunroof = builder.HasSunroof;
    Seats = builder.Seats ?? "Standard";
  }

  public void ShowSpecifications() {
    Console.WriteLine("Car Specifications:");
    Console.WriteLine($"Engine: {Engine}");
    Console.WriteLine($"GPS: {(HasGPS ? "Yes" : "No")}");
    Console.WriteLine($"Sunroof: {(HasSunroof ? "Yes" : "No")}");
    Console.WriteLine($"Seats: {Seats}");
  }

  // Builder Class
  public class CarBuilder {
    public string? Engine { get; private set; }
    public bool HasGPS { get; private set; }
    public bool HasSunroof { get; private set; }
    public string? Seats { get; private set; }

    public CarBuilder SetEngine(string engine) {
      Engine = engine;
      return this;
    }

    public CarBuilder SetGPS(bool hasGPS) {
      HasGPS = hasGPS;
      return this;
    }

    public CarBuilder SetSunroof(bool hasSunroof) {
      HasSunroof = hasSunroof;
      return this;
    }

    public CarBuilder SetSeats(string seats) {
      Seats = seats;
      return this;
    }

    public Car Build() {
      return new Car(this);
    }
  }
}
```
```csharp
// CarDirector.cs

public class CarDirector {
  public Car BuildLuxuryCar() {
    return new Car.CarBuilder()
            .SetEngine("V8 Turbo")
            .SetGPS(true)
            .SetSunroof(true)
            .SetSeats("Leather")
            .Build();
  }

  public Car BuildEconomyCar() {
    return new Car.CarBuilder()
            .SetEngine("1.6L Petrol")
            .SetGPS(false)
            .SetSunroof(false)
            .SetSeats("Standard")
            .Build();
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    CarDirector director = new CarDirector();

    // Build a Luxury Car
    Car luxuryCar = director.BuildLuxuryCar();
    Console.WriteLine("\nLuxury Car:");
    luxuryCar.ShowSpecifications();

    // Build an Economy Car
    Car economyCar = director.BuildEconomyCar();
    Console.WriteLine("\nEconomy Car:");
    economyCar.ShowSpecifications();
  }
}
```

#### **C++ Implementation**
```cpp
// Car.h

#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
  std::string engine;
  bool hasGPS;
  bool hasSunroof;
  std::string seats;

public:
  Car(std::string engine, bool hasGPS, bool hasSunroof, std::string seats);
  void showSpecifications();
};

#endif // CAR_H
```
```cpp
// Car.cpp

#include "Car.h"
#include <iostream>

Car::Car(std::string engine, bool hasGPS, bool hasSunroof, std::string seats)
  : engine(engine), hasGPS(hasGPS), hasSunroof(hasSunroof), seats(seats) {}

void Car::showSpecifications() {
  std::cout << "Car Specifications:\n";
  std::cout << "Engine: " << engine << std::endl;
  std::cout << "GPS: " << (hasGPS ? "Yes" : "No") << std::endl;
  std::cout << "Sunroof: " << (hasSunroof ? "Yes" : "No") << std::endl;
  std::cout << "Seats: " << seats << std::endl;
}
```
```cpp
// ICarBuilder.h

#ifndef I_CAR_BUILDER_H
#define I_CAR_BUILDER_H

#include "Car.h"

class ICarBuilder {
public:
  virtual ~ICarBuilder() = default;
  virtual ICarBuilder* setEngine(const std::string& engine) = 0;
  virtual ICarBuilder* setGPS(bool hasGPS) = 0;
  virtual ICarBuilder* setSunroof(bool hasSunroof) = 0;
  virtual ICarBuilder* setSeats(const std::string& seats) = 0;
  virtual Car* build() = 0;
};

#endif // I_CAR_BUILDER_H
```
```cpp
// CarBuilder.h

#ifndef CAR_BUILDER_H
#define CAR_BUILDER_H

#include "ICarBuilder.h"

class CarBuilder : public ICarBuilder {
private:
  std::string engine = "Unknown Engine";
  bool hasGPS = false;
  bool hasSunroof = false;
  std::string seats = "Standard";

public:
  ICarBuilder* setEngine(const std::string& engine) override;
  ICarBuilder* setGPS(bool hasGPS) override;
  ICarBuilder* setSunroof(bool hasSunroof) override;
  ICarBuilder* setSeats(const std::string& seats) override;
  Car* build() override;
};

#endif // CAR_BUILDER_H
```
```cpp
// CarBuilder.cpp

#include "CarBuilder.h"

ICarBuilder* CarBuilder::setEngine(const std::string& engine) {
  this->engine = engine;
  return this;
}

ICarBuilder* CarBuilder::setGPS(bool hasGPS) {
  this->hasGPS = hasGPS;
  return this;
}

ICarBuilder* CarBuilder::setSunroof(bool hasSunroof) {
  this->hasSunroof = hasSunroof;
  return this;
}

ICarBuilder* CarBuilder::setSeats(const std::string& seats) {
  this->seats = seats;
  return this;
}

Car* CarBuilder::build() {
  return new Car(engine, hasGPS, hasSunroof, seats);
}
```
```cpp
// CarDirector.h

#ifndef CAR_DIRECTOR_H
#define CAR_DIRECTOR_H

#include "CarBuilder.h"

class CarDirector {
public:
  Car* buildLuxuryCar();
  Car* buildEconomyCar();
};

#endif // CAR_DIRECTOR_H
```
```cpp
// CarDirector.cpp

#include "CarDirector.h"

Car* CarDirector::buildLuxuryCar() {
  return (new CarBuilder())
          ->setEngine("V8 Turbo")
          ->setGPS(true)
          ->setSunroof(true)
          ->setSeats("Leather")
          ->build();
}

Car* CarDirector::buildEconomyCar() {
  return (new CarBuilder())
          ->setEngine("1.6L Petrol")
          ->setGPS(false)
          ->setSunroof(false)
          ->setSeats("Standard")
          ->build();
}
```
```cpp
// Main.cpp

#include <iostream>
#include "CarDirector.h"

int main() {
  CarDirector director;

  // Build a Luxury Car
  Car* luxuryCar = director.buildLuxuryCar();
  std::cout << "\nLuxury Car:\n";
  luxuryCar->showSpecifications();

  // Build an Economy Car
  Car* economyCar = director.buildEconomyCar();
  std::cout << "\nEconomy Car:\n";
  economyCar->showSpecifications();

  // Clean up memory
  delete luxuryCar;
  delete economyCar;

  return 0;
}
```

#### **Python Implementation**
```python
# car.py

class Car:
  def __init__(self, engine, has_gps, has_sunroof, seats):
    self.engine = engine
    self.has_gps = has_gps
    self.has_sunroof = has_sunroof
    self.seats = seats

  def show_specifications(self):
    print("Car Specifications:")
    print(f"Engine: {self.engine}")
    print(f"GPS: {'Yes' if self.has_gps else 'No'}")
    print(f"Sunroof: {'Yes' if self.has_sunroof else 'No'}")
    print(f"Seats: {self.seats}")
```
```python
# car_builder.py

from car import Car

class CarBuilder:
  def __init__(self):
    self.engine = "Unknown Engine"
    self.has_gps = False
    self.has_sunroof = False
    self.seats = "Standard"

  def set_engine(self, engine):
    self.engine = engine
    return self

  def set_gps(self, has_gps):
    self.has_gps = has_gps
    return self

  def set_sunroof(self, has_sunroof):
    self.has_sunroof = has_sunroof
    return self

  def set_seats(self, seats):
    self.seats = seats
    return self

  def build(self):
    return Car(self.engine, self.has_gps, self.has_sunroof, self.seats)
```
```python
# car_director.py

from car_builder import CarBuilder

class CarDirector:
  def build_luxury_car(self):
    return CarBuilder()\
            .set_engine("V8 Turbo")\
            .set_gps(True)\
            .set_sunroof(True)\
            .set_seats("Leather")\
            .build()

  def build_economy_car(self):
    return CarBuilder()\
            .set_engine("1.6L Petrol")\
            .set_gps(False)\
            .set_sunroof(False)\
            .set_seats("Standard")\
            .build()
```
```python
# main.py

from car_director import CarDirector

if __name__ == "__main__":
  director = CarDirector()

  # Build a Luxury Car
  luxury_car = director.build_luxury_car()
  print("\nLuxury Car:")
  luxury_car.show_specifications()

  # Build an Economy Car
  economy_car = director.build_economy_car()
  print("\nEconomy Car:")
  economy_car.show_specifications()
```

#### **JavaScript Implementation**
```javascript
// car.js

class Car {
  constructor(engine, hasGPS, hasSunroof, seats) {
    this.engine = engine;
    this.hasGPS = hasGPS;
    this.hasSunroof = hasSunroof;
    this.seats = seats;
  }

  showSpecifications() {
    console.log("Car Specifications:");
    console.log(`Engine: ${this.engine}`);
    console.log(`GPS: ${this.hasGPS ? "Yes" : "No"}`);
    console.log(`Sunroof: ${this.hasSunroof ? "Yes" : "No"}`);
    console.log(`Seats: ${this.seats}`);
  }
}

module.exports = Car;
```
```javascript
// carBuilder.js

const Car = require("./car");

class CarBuilder {
  constructor() {
    this.engine = "Unknown Engine";
    this.hasGPS = false;
    this.hasSunroof = false;
    this.seats = "Standard";
  }

  setEngine(engine) {
    this.engine = engine;
    return this;
  }

  setGPS(hasGPS) {
    this.hasGPS = hasGPS;
    return this;
  }

  setSunroof(hasSunroof) {
    this.hasSunroof = hasSunroof;
    return this;
  }

  setSeats(seats) {
    this.seats = seats;
    return this;
  }

  build() {
    return new Car(this.engine, this.hasGPS, this.hasSunroof, this.seats);
  }
}

module.exports = CarBuilder;
```
```javascript
// carDirector.js

const CarBuilder = require("./carBuilder");

class CarDirector {
  buildLuxuryCar() {
    return new CarBuilder()
            .setEngine("V8 Turbo")
            .setGPS(true)
            .setSunroof(true)
            .setSeats("Leather")
            .build();
  }

  buildEconomyCar() {
    return new CarBuilder()
            .setEngine("1.6L Petrol")
            .setGPS(false)
            .setSunroof(false)
            .setSeats("Standard")
            .build();
  }
}

module.exports = CarDirector;
```
```javascript
// main.js

const CarDirector = require("./carDirector");
const director = new CarDirector();

// Build a Luxury Car
const luxuryCar = director.buildLuxuryCar();
console.log("\nLuxury Car:");
luxuryCar.showSpecifications();

// Build an Economy Car
const economyCar = director.buildEconomyCar();
console.log("\nEconomy Car:");
economyCar.showSpecifications();
```

### 📌 Running the Code
To test the **Builder pattern**, run the following commands:

#### **Java**
```sh
cd Creational/Builder/Java
javac *.java
java Main
```

#### **C#**
```sh
cd Creational/Builder/CSharp
dotnet build
dotnet run
```

#### **C++**
```sh
cd Creational/Builder/Cpp
g++ *.cpp -o builder
./builder
```

#### **Python**
```sh
cd Creational/Builder/Python
python3 main.py
```

#### **JavaScript**
```sh
cd Creational/Builder/JavaScript
node main.js
```

### 📌 Expected Output
```
Luxury Car:
Car Specifications:
Engine: V8 Turbo
GPS: Yes
Sunroof: Yes
Seats: Leather

Economy Car:
Car Specifications:
Engine: 1.6L Petrol
GPS: No
Sunroof: No
Seats: Standard
```

## 📌 Summary
- Builder pattern simplifies complex object creation step by step.
- Avoids constructors with many parameters (**Telescoping Constructor Problem**).
- Ensures immutability and flexible object configuration.
