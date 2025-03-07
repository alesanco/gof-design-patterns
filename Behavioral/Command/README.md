# Command Pattern

## 📌 What is the Command Pattern?
The **Command Pattern** is a behavioral design pattern that **encapsulates a request as an object**, allowing clients to parameterize methods with different requests, delay execution, or queue operations. It helps in decoupling the sender (Invoker) from the receiver (Receiver).

## 📌 When to Use Command
- When you need to **encapsulate requests as objects**.
- When implementing **undo/redo functionality**.
- When you want to **decouple request senders from receivers**, allowing flexible command execution.

## 📌 Example: Smart Home Remote Control
A **smart home system** where a remote control can send commands to a **light** to turn it ON or OFF. The remote can store different commands dynamically.

## 📌 Implementation in Different Languages
Each language implements the **Command pattern** differently based on its capabilities.

### **Java Implementation**
```java
// Command.java

public interface Command {
  void execute();
}
```
```java
// TurnOnCommand.java

public class TurnOnCommand implements Command {
  private Light light;

  public TurnOnCommand(Light light) {
    this.light = light;
  }

  @Override
  public void execute() {
    light.turnOn();
  }
}
```
```java
// TurnOffCommand.java

public class TurnOffCommand implements Command {
  private Light light;

  public TurnOffCommand(Light light) {
    this.light = light;
  }

  @Override
  public void execute() {
    light.turnOff();
  }
}
```
```java
// Light.java

public class Light {
  public void turnOn() {
    System.out.println("The light is ON.");
  }

  public void turnOff() {
    System.out.println("The light is OFF.");
  }
}
```
```java
// RemoteControl.java

public class RemoteControl {
  private Command command;

  public void setCommand(Command command) {
    this.command = command;
  }

  public void pressButton() {
    if (command != null) {
      command.execute();
    } else {
      System.out.println("No command assigned to button.");
    }
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    Light light = new Light();
    Command turnOn = new TurnOnCommand(light);
    Command turnOff = new TurnOffCommand(light);

    RemoteControl remote = new RemoteControl();

    remote.setCommand(turnOn);
    remote.pressButton(); // The light is ON.

    remote.setCommand(turnOff);
    remote.pressButton(); // The light is OFF.
  }
}
```

### **C# Implementation**
```csharp
// ICommand.cs

public interface ICommand {
  void Execute();
}
```
```csharp
// TurnOnCommand.cs

public class TurnOnCommand : ICommand {
  private readonly Light _light;

  public TurnOnCommand(Light light) {
    _light = light;
  }

  public void Execute() {
    _light.TurnOn();
  }
}
```
```csharp
// TurnOffCommand.cs

public class TurnOffCommand : ICommand {
  private readonly Light _light;

  public TurnOffCommand(Light light) {
    _light = light;
  }

  public void Execute() {
    _light.TurnOff();
  }
}
```
```csharp
// Light.cs

using System;

public class Light {
  public void TurnOn() {
    Console.WriteLine("The light is ON.");
  }

  public void TurnOff() {
    Console.WriteLine("The light is OFF.");
  }
}
```
```csharp
// RemoteControl.cs

using System;

public class RemoteControl {
  private ICommand? _command;

  public void SetCommand(ICommand command) {
    _command = command;
  }

  public void PressButton() {
    if (_command != null) {
      _command.Execute();
    } else {
      Console.WriteLine("No command assigned to button.");
    }
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    Light light = new Light();
    ICommand turnOn = new TurnOnCommand(light);
    ICommand turnOff = new TurnOffCommand(light);

    RemoteControl remote = new RemoteControl();

    remote.SetCommand(turnOn);
    remote.PressButton(); // The light is ON.

    remote.SetCommand(turnOff);
    remote.PressButton(); // The light is OFF.
  }
}
```

### **C++ Implementation**
```cpp
// Command.h

#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
  virtual void execute() = 0;
  virtual ~Command() = default;
};

#endif // COMMAND_H
```
```cpp
// TurnOnCommand.h

#ifndef TURN_ON_COMMAND_H
#define TURN_ON_COMMAND_H

#include "Command.h"
#include "Light.h"

class TurnOnCommand : public Command {
private:
  Light* light;

public:
  TurnOnCommand(Light* light) : light(light) {}
  void execute() override { light->turnOn(); }
};

#endif // TURN_ON_COMMAND_H
```
```cpp
// TurnOffCommand.h

#ifndef TURN_OFF_COMMAND_H
#define TURN_OFF_COMMAND_H

#include "Command.h"
#include "Light.h"

class TurnOffCommand : public Command {
private:
  Light* light;

public:
  TurnOffCommand(Light* light) : light(light) {}
  void execute() override { light->turnOff(); }
};

#endif // TURN_OFF_COMMAND_H
```
```cpp
// Light.h

#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>

class Light {
public:
  void turnOn();
  void turnOff();
};

#endif // LIGHT_H
```
```cpp
// Light.cpp

#include "Light.h"

void Light::turnOn() {
  std::cout << "The light is ON." << std::endl;
}

void Light::turnOff() {
  std::cout << "The light is OFF." << std::endl;
}
```
```cpp
// RemoteControl.h

#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include "Command.h"

class RemoteControl {
private:
  Command* command;

public:
  void setCommand(Command* cmd) { command = cmd; }
  void pressButton();
};

#endif // REMOTE_CONTROL_H
```
```cpp
// RemoteControl.cpp

#include "RemoteControl.h"
#include <iostream>

void RemoteControl::pressButton() {
  if (command) {
    command->execute();
  } else {
    std::cout << "No command assigned to button." << std::endl;
  }
}
```
```cpp
// Main.cpp

#include "Light.h"
#include "TurnOnCommand.h"
#include "TurnOffCommand.h"
#include "RemoteControl.h"

int main() {
  Light light;
  TurnOnCommand turnOn(&light);
  TurnOffCommand turnOff(&light);

  RemoteControl remote;

  remote.setCommand(&turnOn);
  remote.pressButton(); // The light is ON.

  remote.setCommand(&turnOff);
  remote.pressButton(); // The light is OFF.

  return 0;
}
```

### **Python Implementation**
```python
# command.py

from abc import ABC, abstractmethod

class Command(ABC):
  @abstractmethod
  def execute(self):
    pass
```
```python
# turn_on_command.py

from command import Command

class TurnOnCommand(Command):
  def __init__(self, light):
    self.light = light

  def execute(self):
    self.light.turn_on()
```
```python
# turn_off_command.py

from command import Command

class TurnOffCommand(Command):
  def __init__(self, light):
    self.light = light

  def execute(self):
    self.light.turn_off()
```
```python
# light.py

class Light:
  def turn_on(self):
    print("The light is ON.")

  def turn_off(self):
    print("The light is OFF.")
```
```python
# remote_control.py

class RemoteControl:
  def __init__(self):
    self.command = None

  def set_command(self, command):
    self.command = command

  def press_button(self):
    if self.command:
      self.command.execute()
    else:
      print("No command assigned to button.")
```
```python
# main.py

from light import Light
from turn_on_command import TurnOnCommand
from turn_off_command import TurnOffCommand
from remote_control import RemoteControl

if __name__ == "__main__":
  light = Light()
  turn_on = TurnOnCommand(light)
  turn_off = TurnOffCommand(light)

  remote = RemoteControl()

  remote.set_command(turn_on)
  remote.press_button()  # The light is ON.

  remote.set_command(turn_off)
  remote.press_button()  # The light is OFF.
```

### **JavaScript Implementation**
```javascript
// command.js

class Command {
  execute() {
    throw new Error("execute() must be implemented by subclasses");
  }
}

module.exports = Command;
```
```javascript
// turnOnCommand.js

const Command = require("./command");

class TurnOnCommand extends Command {
  constructor(light) {
    super();
    this.light = light;
  }

  execute() {
    this.light.turnOn();
  }
}

module.exports = TurnOnCommand;
```
```javascript
// turnOffCommand.js

const Command = require("./command");

class TurnOffCommand extends Command {
  constructor(light) {
    super();
    this.light = light;
  }

  execute() {
    this.light.turnOff();
  }
}

module.exports = TurnOffCommand;
```
```javascript
// light.js

class Light {
  turnOn() {
    console.log("The light is ON.");
  }

  turnOff() {
    console.log("The light is OFF.");
  }
}

module.exports = Light;
```
```javascript
// remoteControl.js

class RemoteControl {
  constructor() {
    this.command = null;
  }

  setCommand(command) {
    this.command = command;
  }

  pressButton() {
    if (this.command) {
      this.command.execute();
    } else {
      console.log("No command assigned to button.");
    }
  }
}

module.exports = RemoteControl;
```
```javascript
// main.js

const Light = require("./light");
const TurnOnCommand = require("./turnOnCommand");
const TurnOffCommand = require("./turnOffCommand");
const RemoteControl = require("./remoteControl");

const light = new Light();
const turnOn = new TurnOnCommand(light);
const turnOff = new TurnOffCommand(light);

const remote = new RemoteControl();

remote.setCommand(turnOn);
remote.pressButton(); // The light is ON.

remote.setCommand(turnOff);
remote.pressButton(); // The light is OFF.
```

## 📌 Running the Code
To test the **Command pattern**, run the following commands:

### **Java**
```sh
cd Behavioral/Command/Java
javac *.java
java Main
```

### **C#**
```sh
cd Behavioral/Command/CSharp
dotnet build
dotnet run
```

### **C++**
```sh
cd Behavioral/Command/Cpp
g++ *.cpp -o command
./command
```

### **Python**
```sh
cd Behavioral/Command/Python
python3 main.py
```

### **JavaScript**
```sh
cd Behavioral/Command/JavaScript
node main.js
```

## 📌 Expected Output
```
The light is ON.
The light is OFF.
```

## 📌 Summary
- Encapsulates requests as objects, making them reusable and flexible.
- Decouples command execution from request invocation, enhancing maintainability.
- Allows dynamic command assignment and future undo/redo extension.