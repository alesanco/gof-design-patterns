# Template Method Pattern

## 📌 What is the Template Method Pattern?
The **Template Method Pattern** is a behavioral design pattern that defines the **skeleton of an algorithm** in a base class while allowing subclasses to **override specific steps** without changing the overall structure.

## 📌 When to Use Template Method
Use the **Template Method pattern** when:

- **Multiple classes** share the same general behavior, but some steps vary.
- **Code duplication** can be avoided by defining a reusable structure in a base class.
- Enforcing **consistent behavior** across different implementations is required.

## 📌 Example: Data Processing System
A **Data Processing System** where different types of data sources (CSV, JSON) need to be processed using a standard sequence of steps:

1. **Read Data** (custom for each data type)
2. **Process Data** (common for all)
3. **Save Data** (common for all)

Each subclass implements its own **`readData()`** while keeping `processData()` and `saveData()` common.

## 📌 Implementation in Different Languages
Each language implements the **Template Method pattern** differently based on its capabilities.

### **Java Implementation**
```java
// DataProcessor.java

public abstract class DataProcessor {
  
  // Template method defining the structure of the algorithm
  public final void process() {
    readData();
    processData();
    saveData();
  }

  // Abstract method to be implemented by subclasses
  protected abstract void readData();

  // Concrete method with common behavior
  protected void processData() {
    System.out.println("Processing data...");
  }

  // Concrete method with common behavior
  protected void saveData() {
    System.out.println("Data saved successfully.");
  }
}
```
```java
// CSVProcessor.java

public class CSVProcessor extends DataProcessor {
  @Override
  protected void readData() {
    System.out.println("Reading data from CSV file...");
  }
}
```
```java
// JSONProcessor.java

public class JSONProcessor extends DataProcessor {
  @Override
  protected void readData() {
    System.out.println("Reading data from JSON file...");
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    DataProcessor csvProcessor = new CSVProcessor();
    csvProcessor.process();

    System.out.println("---------------------");

    DataProcessor jsonProcessor = new JSONProcessor();
    jsonProcessor.process();
  }
}
```

### **C# Implementation**
```csharp
// DataProcessor.cs

using System;

public abstract class DataProcessor {
  // Template method defining the structure of the algorithm
  public void Process() {
    ReadData();
    ProcessData();
    SaveData();
  }

  // Abstract method to be implemented by subclasses
  protected abstract void ReadData();

  // Concrete method with common behavior
  protected void ProcessData() {
    Console.WriteLine("Processing data...");
  }

  // Concrete method with common behavior
  protected void SaveData() {
    Console.WriteLine("Data saved successfully.");
  }
}
```
```csharp
// CSVProcessor.cs

using System;

public class CSVProcessor : DataProcessor {
  protected override void ReadData() {
    Console.WriteLine("Reading data from CSV file...");
  }
}
```
```csharp
// JSONProcessor.cs

using System;

public class JSONProcessor : DataProcessor {
  protected override void ReadData() {
    Console.WriteLine("Reading data from JSON file...");
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    DataProcessor csvProcessor = new CSVProcessor();
    csvProcessor.Process();

    Console.WriteLine("---------------------");

    DataProcessor jsonProcessor = new JSONProcessor();
    jsonProcessor.Process();
  }
}
```

### **C++ Implementation**
```cpp
// DataProcessor.h

#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <iostream>

class DataProcessor {
public:
  // Template method defining the structure of the algorithm
  void process();

  // Abstract method to be implemented by subclasses
  virtual void readData() = 0;

  // Concrete method with common behavior
  virtual void processData();
  
  // Concrete method with common behavior
  virtual void saveData();

  virtual ~DataProcessor() = default;
};

#endif // DATAPROCESSOR_H
```
```cpp
// DataProcessor.cpp

#include "DataProcessor.h"

void DataProcessor::process() {
  readData();
  processData();
  saveData();
}

void DataProcessor::processData() {
  std::cout << "Processing data..." << std::endl;
}

void DataProcessor::saveData() {
  std::cout << "Data saved successfully." << std::endl;
}
```
```cpp
// CSVProcessor.h

#ifndef CSVPROCESSOR_H
#define CSVPROCESSOR_H

#include "DataProcessor.h"

class CSVProcessor : public DataProcessor {
public:
  void readData() override;
};

#endif // CSVPROCESSOR_H
```
```cpp
// CSVProcessor.cpp

#include "CSVProcessor.h"

void CSVProcessor::readData() {
  std::cout << "Reading data from CSV file..." << std::endl;
}
```
```cpp
// JSONProcessor.h

#ifndef JSONPROCESSOR_H
#define JSONPROCESSOR_H

#include "DataProcessor.h"

class JSONProcessor : public DataProcessor {
public:
  void readData() override;
};

#endif // JSONPROCESSOR_H
```
```cpp
// JSONProcessor.cpp

#include "JSONProcessor.h"

void JSONProcessor::readData() {
  std::cout << "Reading data from JSON file..." << std::endl;
}
```
```cpp
// Main.cpp

#include "CSVProcessor.h"
#include "JSONProcessor.h"

int main() {
  CSVProcessor csvProcessor;
  csvProcessor.process();

  std::cout << "---------------------" << std::endl;

  JSONProcessor jsonProcessor;
  jsonProcessor.process();

  return 0;
}
```

### **Python Implementation**
```python
# data_processor.py

from abc import ABC, abstractmethod

class DataProcessor(ABC):
  # Template method defining the structure of the algorithm
  def process(self):
    self.read_data()
    self.process_data()
    self.save_data()

  # Abstract method to be implemented by subclasses
  @abstractmethod
  def read_data(self):
    pass

  # Concrete method with common behavior
  def process_data(self):
    print("Processing data...")

  # Concrete method with common behavior
  def save_data(self):
    print("Data saved successfully.")
```
```python
# csv_processor.py

from data_processor import DataProcessor

class CSVProcessor(DataProcessor):
  def read_data(self):
    print("Reading data from CSV file...")
```
```python
# json_processor.py

from data_processor import DataProcessor

class JSONProcessor(DataProcessor):
  def read_data(self):
    print("Reading data from JSON file...")
```
```python
# main.py

from csv_processor import CSVProcessor
from json_processor import JSONProcessor

if __name__ == "__main__":
  csv_processor = CSVProcessor()
  csv_processor.process()

  print("---------------------")

  json_processor = JSONProcessor()
  json_processor.process()
```

### **JavaScript Implementation**
```javascript
// dataProcessor.js

class DataProcessor {
  // Template method defining the structure of the algorithm
  process() {
    this.readData();
    this.processData();
    this.saveData();
  }

  // Abstract method to be implemented by subclasses
  readData() {
    throw new Error("Method 'readData()' must be implemented.");
  }

  // Concrete method with common behavior
  processData() {
    console.log("Processing data...");
  }

  // Concrete method with common behavior
  saveData() {
    console.log("Data saved successfully.");
  }
}

module.exports = DataProcessor;
```
```javascript
// csvProcessor.js

const DataProcessor = require("./dataProcessor");

class CSVProcessor extends DataProcessor {
  readData() {
    console.log("Reading data from CSV file...");
  }
}

module.exports = CSVProcessor;
```
```javascript
// jsonProcessor.js

const DataProcessor = require("./dataProcessor");

class JSONProcessor extends DataProcessor {
  readData() {
    console.log("Reading data from JSON file...");
  }
}

module.exports = JSONProcessor;
```
```javascript
// main.js

const CSVProcessor = require("./csvProcessor");
const JSONProcessor = require("./jsonProcessor");

const csvProcessor = new CSVProcessor();
csvProcessor.process();

console.log("---------------------");

const jsonProcessor = new JSONProcessor();
jsonProcessor.process();
```

## 📌 Running the Code
To test the **Template Method pattern**, run the following commands:

### Java
```sh
cd Behavioral/TemplateMethod/Java
javac *.java
java Main
```

### C#
```sh
cd Behavioral/TemplateMethod/CSharp
dotnet build
dotnet run
```

### C++
```sh
cd Behavioral/TemplateMethod/Cpp
g++ *.cpp -o template_method
./template_method
```

### Python
```sh
cd Behavioral/TemplateMethod/Python
python3 main.py
```

### JavaScript
```sh
cd Behavioral/TemplateMethod/JavaScript
node main.js
```

## 📌 Expected Output
```
Reading data from CSV file...
Processing data...
Data saved successfully.
---------------------
Reading data from JSON file...
Processing data...
Data saved successfully.
```

## 📌 Summary
- Defines a template method that establishes an algorithm's structure.
- Encapsulates common logic while allowing variation in certain steps.
- Encourages code reuse and consistency across multiple implementations.