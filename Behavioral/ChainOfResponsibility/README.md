# Chain of Responsibility Pattern

## 📌 What is the Chain of Responsibility Pattern?
The **Chain of Responsibility Pattern** is a behavioral design pattern that **allows a request to be processed by multiple handlers sequentially**. If one handler cannot process the request, it passes it to the next handler in the chain until one can handle it or there are no more handlers left.

## 📌 When to Use Chain of Responsibility
Use the **Chain of Responsibility pattern** when:

- Multiple handlers might process a request but **only one should handle it**.
- Requests should be **dynamically passed** through different processing chains.
- Decoupling request senders from receivers is required, **avoiding direct dependencies**.

## 📌 Example: Customer Support Request Handling
A **customer support system** where different levels of support (Basic, Supervisor, and Manager) handle issues. Requests that are too complex for a lower level get passed up the chain.

### 📌 Implementation in Different Languages

#### **Java Implementation**
```java
// SupportHandler.java

public abstract class SupportHandler {
  protected SupportHandler nextHandler;

  public void setNextHandler(SupportHandler nextHandler) {
    this.nextHandler = nextHandler;
  }

  public abstract void handleRequest(String request);
}
```
```java
// BasicSupport.java

public class BasicSupport extends SupportHandler {
  @Override
  public void handleRequest(String request) {
    if (request.equals("Basic Issue")) {
      System.out.println("BasicSupport: Handling request - " + request);
    } else if (nextHandler != null) {
      nextHandler.handleRequest(request); // Only pass if not handled
    } else {
      System.out.println("No handler available for - " + request);
    }
  }
}
```
```java
// Supervisor.java

public class Supervisor extends SupportHandler {
  @Override
  public void handleRequest(String request) {
    if (request.equals("Intermediate Issue")) {
      System.out.println("Supervisor: Handling request - " + request);
    } else if (nextHandler != null) {
      nextHandler.handleRequest(request); // Only pass if not handled
    } else {
      System.out.println("No handler available for - " + request);
    }
  }
}
```
```java
// Manager.java

public class Manager extends SupportHandler {
  @Override
  public void handleRequest(String request) {
    if (request.equals("Advanced Issue")) {
      System.out.println("Manager: Handling request - " + request);
    } else {
      System.out.println("No handler available for - " + request);
    }
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    SupportHandler basic = new BasicSupport();
    SupportHandler supervisor = new Supervisor();
    SupportHandler manager = new Manager();

    // Setting up the chain
    basic.setNextHandler(supervisor);
    supervisor.setNextHandler(manager);

    // Sending requests
    basic.handleRequest("Basic Issue");
    basic.handleRequest("Intermediate Issue");
    basic.handleRequest("Advanced Issue");
    basic.handleRequest("Unknown Issue");
  }
}
```

#### **C# Implementation**
```csharp
// SupportHandler.cs

public abstract class SupportHandler {
  protected SupportHandler? NextHandler;

  public void SetNextHandler(SupportHandler nextHandler) {
    NextHandler = nextHandler;
  }

  public abstract void HandleRequest(string request);
}
```
```csharp
// BasicSupport.cs

using System;

public class BasicSupport : SupportHandler {
  public override void HandleRequest(string request) {
    if (request == "Basic Issue") {
      Console.WriteLine($"BasicSupport: Handling request - {request}");
    } else if (NextHandler != null) {
      NextHandler.HandleRequest(request); // Only pass if not handled
    } else {
      Console.WriteLine($"No handler available for - {request}");
    }
  }
}
```
```csharp
// Supervisor.cs

using System;

public class Supervisor : SupportHandler {
  public override void HandleRequest(string request) {
    if (request == "Intermediate Issue") {
      Console.WriteLine($"Supervisor: Handling request - {request}");
    } else if (NextHandler != null) {
      NextHandler.HandleRequest(request); // Only pass if not handled
    } else {
      Console.WriteLine($"No handler available for - {request}");
    }
  }
}
```
```csharp
// Manager.cs

using System;

public class Manager : SupportHandler {
  public override void HandleRequest(string request) {
    if (request == "Advanced Issue") {
      Console.WriteLine($"Manager: Handling request - {request}");
    } else {
      Console.WriteLine($"No handler available for - {request}");
    }
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    SupportHandler basic = new BasicSupport();
    SupportHandler supervisor = new Supervisor();
    SupportHandler manager = new Manager();

    // Setting up the chain
    basic.SetNextHandler(supervisor);
    supervisor.SetNextHandler(manager);

    // Sending requests
    basic.HandleRequest("Basic Issue");
    basic.HandleRequest("Intermediate Issue");
    basic.HandleRequest("Advanced Issue");
    basic.HandleRequest("Unknown Issue");
  }
}
```

#### **C++ Implementation**
```cpp
// SupportHandler.h

#ifndef SUPPORT_HANDLER_H
#define SUPPORT_HANDLER_H

#include <string>

class SupportHandler {
protected:
  SupportHandler* nextHandler;

public:
  SupportHandler() : nextHandler(nullptr) {}
  void setNextHandler(SupportHandler* handler) { nextHandler = handler; }
  virtual void handleRequest(const std::string& request) = 0;
  virtual ~SupportHandler() = default;
};

#endif // SUPPORT_HANDLER_H
```
```cpp
// BasicSupport.h

#ifndef BASIC_SUPPORT_H
#define BASIC_SUPPORT_H

#include "SupportHandler.h"
#include <iostream>

class BasicSupport : public SupportHandler {
public:
  void handleRequest(const std::string& request) override;
};

#endif // BASIC_SUPPORT_H
```
```cpp
// BasicSupport.cpp

#include "BasicSupport.h"

void BasicSupport::handleRequest(const std::string& request) {
  if (request == "Basic Issue") {
    std::cout << "BasicSupport: Handling request - " << request << std::endl;
  } else if (nextHandler) {
    nextHandler->handleRequest(request);
  } else {
    std::cout << "No handler available for - " << request << std::endl;
  }
}
```
```cpp
// Supervisor.h

#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "SupportHandler.h"
#include <iostream>

class Supervisor : public SupportHandler {
public:
  void handleRequest(const std::string& request) override;
};

#endif // SUPERVISOR_H
```
```cpp
// Supervisor.cpp

#include "Supervisor.h"

void Supervisor::handleRequest(const std::string& request) {
  if (request == "Intermediate Issue") {
    std::cout << "Supervisor: Handling request - " << request << std::endl;
  } else if (nextHandler) {
    nextHandler->handleRequest(request);
  } else {
    std::cout << "No handler available for - " << request << std::endl;
  }
}
```
```cpp
// Manager.h

#ifndef MANAGER_H
#define MANAGER_H

#include "SupportHandler.h"
#include <iostream>

class Manager : public SupportHandler {
public:
  void handleRequest(const std::string& request) override;
};

#endif // MANAGER_H
```
```cpp
// Manager.cpp

#include "Manager.h"

void Manager::handleRequest(const std::string& request) {
  if (request == "Advanced Issue") {
    std::cout << "Manager: Handling request - " << request << std::endl;
  } else {
    std::cout << "No handler available for - " << request << std::endl;
  }
}
```
```cpp
// Main.cpp

#include "BasicSupport.h"
#include "Supervisor.h"
#include "Manager.h"

int main() {
  BasicSupport basic;
  Supervisor supervisor;
  Manager manager;

  // Setting up the chain
  basic.setNextHandler(&supervisor);
  supervisor.setNextHandler(&manager);

  // Sending requests
  basic.handleRequest("Basic Issue");
  basic.handleRequest("Intermediate Issue");
  basic.handleRequest("Advanced Issue");
  basic.handleRequest("Unknown Issue");

  return 0;
}
```

#### **Python Implementation**
```python
# support_handler.py

from abc import ABC, abstractmethod

class SupportHandler(ABC):
  def __init__(self):
    self._next_handler = None

  def set_next_handler(self, handler):
    self._next_handler = handler

  @abstractmethod
  def handle_request(self, request):
    pass
```
```python
# basic_support.py

from support_handler import SupportHandler

class BasicSupport(SupportHandler):
  def handle_request(self, request):
    if request == "Basic Issue":
      print(f"BasicSupport: Handling request - {request}")
    elif self._next_handler:
      self._next_handler.handle_request(request)
    else:
      print(f"No handler available for - {request}")
```
```python
# supervisor.py

from support_handler import SupportHandler

class Supervisor(SupportHandler):
  def handle_request(self, request):
    if request == "Intermediate Issue":
      print(f"Supervisor: Handling request - {request}")
    elif self._next_handler:
      self._next_handler.handle_request(request)
    else:
      print(f"No handler available for - {request}")
```
```python
# manager.py

from support_handler import SupportHandler

class Manager(SupportHandler):
  def handle_request(self, request):
    if request == "Advanced Issue":
      print(f"Manager: Handling request - {request}")
    else:
      print(f"No handler available for - {request}")
```
```python
# main.py

from basic_support import BasicSupport
from supervisor import Supervisor
from manager import Manager

if __name__ == "__main__":
  basic = BasicSupport()
  supervisor = Supervisor()
  manager = Manager()

  # Setting up the chain
  basic.set_next_handler(supervisor)
  supervisor.set_next_handler(manager)

  # Sending requests
  basic.handle_request("Basic Issue")
  basic.handle_request("Intermediate Issue")
  basic.handle_request("Advanced Issue")
```

#### **JavaScript Implementation**
```javascript
// SupportHandler.js

class SupportHandler {
  constructor() {
    this.nextHandler = null;
  }

  setNextHandler(handler) {
    this.nextHandler = handler;
  }

  handleRequest(request) {
    throw new Error("handleRequest() must be implemented by subclasses");
  }
}

module.exports = SupportHandler;
```
```javascript
// BasicSupport.js

const SupportHandler = require("./SupportHandler");

class BasicSupport extends SupportHandler {
  handleRequest(request) {
    if (request === "Basic Issue") {
      console.log(`BasicSupport: Handling request - ${request}`);
    } else if (this.nextHandler) {
      this.nextHandler.handleRequest(request);
    } else {
      console.log(`No handler available for - ${request}`);
    }
  }
}

module.exports = BasicSupport;
```
```javascript
// Supervisor.js

const SupportHandler = require("./SupportHandler");

class Supervisor extends SupportHandler {
  handleRequest(request) {
    if (request === "Intermediate Issue") {
      console.log(`Supervisor: Handling request - ${request}`);
    } else if (this.nextHandler) {
      this.nextHandler.handleRequest(request);
    } else {
      console.log(`No handler available for - ${request}`);
    }
  }
}

module.exports = Supervisor;
```
```javascript
// Manager.js

const SupportHandler = require("./SupportHandler");

class Manager extends SupportHandler {
  handleRequest(request) {
    if (request === "Advanced Issue") {
      console.log(`Manager: Handling request - ${request}`);
    } else {
      console.log(`No handler available for - ${request}`);
    }
  }
}

module.exports = Manager;
```
```javascript
// main.js

const BasicSupport = require("./BasicSupport");
const Supervisor = require("./Supervisor");
const Manager = require("./Manager");

const basic = new BasicSupport();
const supervisor = new Supervisor();
const manager = new Manager();

// Setting up the chain
basic.setNextHandler(supervisor);
supervisor.setNextHandler(manager);

// Sending requests
basic.handleRequest("Basic Issue");
basic.handleRequest("Intermediate Issue");
basic.handleRequest("Advanced Issue");
basic.handleRequest("Unknown Issue");
```

### 📌 Running the Code
To test the **Chain of Responsibility pattern**, run the following commands:

#### **Java**
```sh
cd Behavioral/ChainOfResponsibility/Java
javac *.java
java Main
```

#### **C#**
```sh
cd Behavioral/ChainOfResponsibility/CSharp
dotnet build
dotnet run
```

#### **C++**
```sh
cd Behavioral/ChainOfResponsibility/Cpp
g++ *.cpp -o chain_of_responsibility
./chain_of_responsibility
```

#### **Python**
```sh
cd Behavioral/ChainOfResponsibility/Python
python3 main.py
```

#### **JavaScript**
```sh
cd Behavioral/ChainOfResponsibility/JavaScript
node main.js
```

### 📌 Expected Output
```
BasicSupport: Handling request - Basic Issue
Supervisor: Handling request - Intermediate Issue
Manager: Handling request - Advanced Issue
No handler available for - Unknown Issue
```

## 📌 Summary
- Decouples request senders and receivers, allowing requests to be passed dynamically.
- Enables flexible processing chains where multiple handlers can process different types of requests.
- Improves maintainability by centralizing request handling logic in separate handler classes.