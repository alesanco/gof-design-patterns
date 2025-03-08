# Singleton Pattern

## 📌 What is the Singleton Pattern?
The **Singleton pattern** ensures that a class has **only one instance** and provides a **global access point** to that instance. It is commonly used for managing shared resources, such as database connections, logging, and configuration settings.

## 📌 When to Use Singleton
Use the **Singleton pattern** when:

- You need to **control access** to a shared resource (e.g., logging, configuration).
- You want to **prevent multiple instances** from being created (e.g., a database connection pool).
- Global access is required, but **without using global variables**.

## 📌 Example: Logger System
Imagine we are designing a **Logger System** where all log messages must be written to the same log file. We need to ensure that only **one instance** of the logger exists throughout the application.

## 📌 Implementation in Different Languages
Each language implements the **Singleton pattern** differently based on its capabilities.

### **Java Implementation**
```java
// Logger.java

public class Logger {
  private static Logger instance;

  private Logger() {
    System.out.println("Logger instance created.");
  }

  public static Logger getInstance() {
    if (instance == null) {
      instance = new Logger();
    }
    return instance;
  }

  public void log(String message) {
    System.out.println("[LOG]: " + message);
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    Logger logger1 = Logger.getInstance();
    logger1.log("Initializing the system...");

    Logger logger2 = Logger.getInstance();
    logger2.log("System running.");

    // Verify if both instances are the same
    System.out.println("Logger instances are the same: " + (logger1 == logger2));
  }
}
```

### **C# Implementation**
```csharp
// Logger.cs

using System;

public sealed class Logger {
  private static Logger? instance;
  private static readonly object lockObject = new();

  private Logger() {
    Console.WriteLine("Logger instance created.");
  }

  public static Logger Instance {
    get {
      lock (lockObject) {
        if (instance == null) {
          instance = new Logger();
        }
        return instance;
      }
    }
  }

  public void Log(string message) {
    Console.WriteLine($"[LOG]: {message}");
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    Logger logger1 = Logger.Instance;
    logger1.Log("Initializing the system...");

    Logger logger2 = Logger.Instance;
    logger2.Log("System running.");

    // Verify if both instances are the same
    Console.WriteLine($"Logger instances are the same: {logger1 == logger2}");
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
// Logger.h

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <memory>
#include <mutex>

class Logger {
private:
  static std::unique_ptr<Logger> instance;
  static std::mutex mutex;

  Logger(); // Private constructor to prevent direct instantiation

public:
  static Logger* getInstance();
  void log(const std::string& message);

  // Delete copy constructor and assignment operator
  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;
};

#endif // LOGGER_H
```
```cpp
// Logger.cpp

#include "Logger.h"

std::unique_ptr<Logger> Logger::instance;
std::mutex Logger::mutex;

Logger::Logger() {
  std::cout << "Logger instance created." << std::endl;
}

Logger* Logger::getInstance() {
  std::lock_guard<std::mutex> lock(mutex);
  if (!instance) {
    instance = std::unique_ptr<Logger>(new Logger());
  }
  return instance.get();
}

void Logger::log(const std::string& message) {
  std::cout << "[LOG]: " << message << std::endl;
}
```
```cpp
// Main.cpp

#include "Logger.h"

int main() {
  Logger* logger1 = Logger::getInstance();
  logger1->log("Initializing the system...");

  Logger* logger2 = Logger::getInstance();
  logger2->log("System running.");

  // Verify if both instances are the same
  std::cout << "Logger instances are the same: " << (logger1 == logger2) << std::endl;

  return 0;
}
```

### **Python Implementation**
```python
# logger.py

import threading

class Logger:
  _instance = None
  _lock = threading.Lock()  # Ensures thread safety

  def __new__(cls):
    with cls._lock:  # Thread-safe singleton
      if cls._instance is None:
        cls._instance = super(Logger, cls).__new__(cls)
        print("Logger instance created.")
      return cls._instance

  def log(self, message: str):
    print(f"[LOG]: {message}")
```
```python
# main.py

from logger import Logger

if __name__ == "__main__":
  logger1 = Logger()
  logger1.log("Initializing the system...")

  logger2 = Logger()
  logger2.log("System running.")

  # Verify if both instances are the same
  print(f"Logger instances are the same: {logger1 is logger2}")
```

### **JavaScript Implementation**
```javascript
// logger.js

class Logger {
  static instance = null;

  constructor() {
    if (Logger.instance) {
      return Logger.instance;
    }
    Logger.instance = this;
    console.log("Logger instance created.");
  }

  log(message) {
    console.log(`[LOG]: ${message}`);
  }
}

module.exports = new Logger();
```
```javascript
// main.js

const logger1 = require("./logger");
logger1.log("Initializing the system...");

const logger2 = require("./logger");
logger2.log("System running.");

// Verify if both instances are the same
console.log(`Logger instances are the same: ${logger1 === logger2}`);
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