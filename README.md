# GoF Design Patterns 🛠️

A **multi-language** repository demonstrating all **23 Gang of Four (GoF) design patterns** in **Java**, **C#**, **C++**, **Python** and **JavaScript**. This project provides **simple and self-contained implementations** of each pattern, making it easy to compare how different languages implement the same software architecture concepts.

## 📖 About This Project
Design patterns are **proven solutions to common software design problems**. They improve **code organization**, **scalability**, and **maintainability** by following best practices in object-oriented programming.

This repository contains implementations of the **three main design pattern categories**:
- **Creational Patterns** 🏗️ → Object creation strategies.
- **Structural Patterns** 🏛️ → Organizing relationships between objects.
- **Behavioral Patterns** 🎭 → Managing object communication.

Each pattern is implemented in **multiple languages** for easy cross-language comparisons.

| Language | Why It's a Good Choice for Design Patterns |
|----------|--------------------------------------------|
| **Java** | The most common language for learning GoF design patterns. Strong OOP support. |
| **C#** | Similar to Java but with modern .NET features like delegates, events, and LINQ. |
| **C++** | Shows how patterns work with manual memory management and low-level features. |
| **Python** | Demonstrates patterns in a dynamic, high-level scripting language with fewer constraints. |
| **JavaScript** | Showcases design patterns in a prototype-based, dynamically-typed language. Useful for frontend & backend (Node.js) and introduces functional programming aspects.

This balance of **static** (**Java**, **C#**, **C++**) and **dynamic** (**Python**, **JavaScript**) languages provides broad coverage of **OOP patterns** while showcasing how different programming paradigms handle them.

---

## 📂 Project Structure
```
.
├── Behavioral
│   └── ...
├── Creational
│   ├── ...
│   └── Singleton
│       ├── Cpp
│       │   ├── Main.cpp
│       │   └── Singleton.cpp
│       ├── CSharp
│       │   ├── Program.cs
│       │   └── Singleton.cs
│       ├── Java
│       │   ├── Main.java
│       │   └── Singleton.java
│       ├── JavaScript
│       │   ├── main.js
│       │   └── singleton.js
│       ├── Python
│       │   ├── main.py
│       │   └── singleton.py
│       └── README.md
├── Structural
│   └── ...
└── README.md
```

Each **design pattern** has:
- **Language-specific subfolders** (`Cpp/`, `CSharp/`, `Java/`, `Python/`) containing the code implementations.
- **Documentation** (`README.md`) explaining the pattern, applicable to all languages.

The **naming convention** follows the following rules:

| Language | Folder Naming | File Naming |
|----------|---------------|-------------|
**Java**, **C#**, **C++** | **PascalCase** (`Singleton/`, `FactoryMethod/`) | **PascalCase** (`Singleton.java`, `FactoryMethod.cs`, `Singleton.cpp`) |
**Python** | **PascalCase** (`Creational/`) | **snake_case** (`singleton.py`, `factory_method.py`)

---

## 🔥 Included Design Patterns

### **Creational Patterns (5)**
| Pattern | Description |
|---------|------------|
| **Singleton** | Ensures only one instance of a class exists. |
| **Factory Method** | Provides an interface for creating objects but lets subclasses alter the type. |
| **Abstract Factory** | A factory that creates families of related objects. |
| **Builder** | Separates object construction from representation. |
| **Prototype** | Creates objects by copying an existing instance. |

### **Structural Patterns (7)**
| Pattern | Description |
|---------|------------|
| **Adapter** | Converts one interface to another expected by clients. |
| **Bridge** | Separates abstraction from implementation. |
| **Composite** | Organizes objects into tree structures. |
| **Decorator** | Dynamically adds new functionality to objects. |
| **Facade** | Provides a simplified interface to a complex system. |
| **Flyweight** | Reduces memory usage by sharing data between similar objects. |
| **Proxy** | Controls access to an object by acting as an intermediary. |

### **Behavioral Patterns (11)**
| Pattern | Description |
|---------|------------|
| **Chain of Responsibility** | Passes a request along a chain of handlers. |
| **Command** | Encapsulates a request as an object. |
| **Interpreter** | Defines a grammar and interpreter for language rules. |
| **Iterator** | Provides sequential access to elements without exposing structure. |
| **Mediator** | Centralizes communication between multiple objects. |
| **Memento** | Captures and restores an object’s state. |
| **Observer** | Defines a dependency where state changes notify subscribers. |
| **State** | Alters object behavior based on internal state changes. |
| **Strategy** | Defines interchangeable algorithms at runtime. |
| **Template Method** | Defines the structure of an algorithm with steps overridden by subclasses. |
| **Visitor** | Separates operations from object structure to allow adding new behaviors. |

---

## 🛠️ How to Use

### **Clone the Repository**
```
git clone https://github.com/alesanco/gof-design-patterns.git
cd gof-design-patterns
```

### **Run Examples**
Each pattern folder contains working implementation examples in multiple languages.

For example, to run the **Singleton** pattern:

**Java**:
```
cd Creational/Singleton/Java
javac Singleton.java
java Singleton
```

**C#**:
```
cd Creational/Singleton/CSharp
dotnet run Singleton.cs
```

**C++**:
```
cd Creational/Singleton/Cpp
g++ Singleton.cpp -o singleton
./singleton
```

**Python**:
```
cd Creational/Singleton/Python
python singleton.py
```

**JavaScript** (Node.js):
```
cd Creational/Singleton/JavaScript
node main.js
```

## 🏷️ License
This project is licensed under the MIT License.