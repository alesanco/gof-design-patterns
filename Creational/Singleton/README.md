# Singleton Pattern

## 📌 What is the Singleton Pattern?
The **Singleton pattern** ensures that a class has **only one instance** and provides a **global access point** to that instance. It is commonly used for managing shared resources, such as database connections, logging, and configuration settings.

## 📌 When to Use Singleton
Use the **Singleton pattern** when:
- You need to **control access** to a shared resource (e.g., logging, configuration).
- You want to **prevent multiple instances** from being created (e.g., a database connection pool).
- Global access is required, but **without using global variables**.

## 📌 Implementation in Different Languages
Each language implements the **Singleton pattern** differently based on its capabilities.

### **Java Implementation**
```java
// Singleton.java
public class Singleton {
  private static Singleton instance;

  private Singleton() {} // Private constructor

  public static Singleton getInstance() {
    if (instance == null) {
      instance = new Singleton();
    }

    return instance;
  }
}
```
```java
// Main.java
public class Main {
  public static void main(String[] args) {
    Singleton s1 = Singleton.getInstance();
    Singleton s2 = Singleton.getInstance();

    System.out.println(s1 == s2); // Should print: true
  }
}
```

### **C# Implementation**
```csharp
// Singleton.cs
public class Singleton {
  private static Singleton? instance = null;
  
  private Singleton() {} // Private constructor

  public static Singleton GetInstance() {
    if (instance == null) {
      instance = new Singleton();
    }

    return instance;
  }
}
```
```csharp
// Program.cs
using System;

class Program {
  static void Main() {
    Singleton s1 = Singleton.GetInstance();
    Singleton s2 = Singleton.GetInstance();

    Console.WriteLine(s1 == s2); // Should print: True
  }
}
```

### **C++ Implementation**
```cpp
// Singleton.h
#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
private:
  static Singleton* instance;
  Singleton() {} // Private constructor

public:
  static Singleton* GetInstance();
  static void DestroyInstance();

  // Prevent copying
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
};

#endif // SINGLETON_H
```
```cpp
// Singleton.cpp
#include "Singleton.h"

Singleton* Singleton::instance = nullptr;

Singleton* Singleton::GetInstance() {
  if (instance == nullptr) {
    instance = new Singleton();
  }

  return instance;
}

void Singleton::DestroyInstance() {
  delete instance;
  instance = nullptr;
}
```
```cpp
// Main.cpp
#include <iostream>
#include "Singleton.h"

int main() {
  Singleton* s1 = Singleton::GetInstance();
  Singleton* s2 = Singleton::GetInstance();

  std::cout << (s1 == s2) << std::endl; // Should print: 1 (true)

  // Cleanup memory
  Singleton::DestroyInstance();

  return 0;
}
```

### **Python Implementation**
```python
# singleton.py
class Singleton:
  _instance = None

  def __new__(cls):
    if cls._instance is None:
      cls._instance = super(Singleton, cls).__new__(cls)

    return cls._instance
```
```python
# main.py
from singleton import Singleton

s1 = Singleton()
s2 = Singleton()

print(s1 is s2)  # Should print: True
```

### **JavaScript Implementation**
```javascript
// singleton.js
class Singleton {
  constructor() {
    if (!Singleton.instance) {
      Singleton.instance = this;
    }

    return Singleton.instance;
  }
}

module.exports = Singleton;
```
```javascript
// main.js
const Singleton = require("./singleton");

const s1 = new Singleton();
const s2 = new Singleton();

console.log(s1 === s2); // Should print: true
```

## 📌 Running the Code
To test the **Singleton pattern**, run the following commands:

### **Java**
```sh
cd Creational/Singleton/Java
javac *.java
java Main
```

### **C#**
```sh
cd Creational/Singleton/CSharp
dotnet build
dotnet run
```

### **C++**
```sh
cd Creational/Singleton/Cpp
g++ *.cpp -o singleton
./singleton
```

### **Python**
```sh
cd Creational/Singleton/Python
python3 main.py
```

### **JavaScript**
```sh
cd Creational/Singleton/JavaScript
node main.js
```

## 📌 Expected Output
```
true   (Java)
True   (C#)
1      (C++)
True   (Python)
true   (JavaScript)
```

## 📌 Summary
- Ensures a single instance of a class exists.
- Used for logging, configurations, and resource management.
- Implemented using private constructors and static methods.