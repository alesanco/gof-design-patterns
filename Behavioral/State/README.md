# State Pattern

## 📌 What is the State Pattern?
The **State Pattern** is a behavioral design pattern that **allows an object to alter its behavior when its internal state changes**. Instead of using large conditional statements, this pattern encapsulates state-specific behavior inside separate classes.

## 📌 When to Use the State Pattern
Use the **State pattern** when:
- An object's behavior depends on its state and changes dynamically.
- Multiple conditional statements control state-dependent behavior.
- State-specific logic needs to be encapsulated to improve maintainability.

## 📌 Example: Traffic Light System
We implement a **Traffic Light System** where the traffic light cycles through different states:

- **Red Light** → Stop
- **Green Light** → Go
- **Yellow Light** → Prepare

Each state transitions dynamically without the main object knowing its next state in advance.

## 📌 Implementation in Different Languages
Each language implements the **State pattern** differently based on its capabilities.

### **Java Implementation**
```java
// TrafficLightState.java

public interface TrafficLightState {
  void handle(TrafficLight trafficLight);
}
```
```java
// RedLight.java

public class RedLight implements TrafficLightState {
  @Override
  public void handle(TrafficLight trafficLight) {
    System.out.println("Red Light - STOP!");
    trafficLight.setState(new GreenLight()); // Transition to Green
  }
}
```
```java
// YellowLight.java

public class YellowLight implements TrafficLightState {
  @Override
  public void handle(TrafficLight trafficLight) {
    System.out.println("Yellow Light - PREPARE!");
    trafficLight.setState(new RedLight()); // Transition to Red
  }
}
```
```java
// GreenLight.java

public class GreenLight implements TrafficLightState {
  @Override
  public void handle(TrafficLight trafficLight) {
    System.out.println("Green Light - GO!");
    trafficLight.setState(new YellowLight()); // Transition to Yellow
  }
}
```
```java
// TrafficLight.java

public class TrafficLight {
  private TrafficLightState state;

  public TrafficLight() {
    state = new RedLight(); // Initial state
  }

  public void setState(TrafficLightState state) {
    this.state = state;
  }

  public void change() {
    state.handle(this);
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    TrafficLight trafficLight = new TrafficLight();

    for (int i = 0; i < 6; i++) {
      trafficLight.change();
    }
  }
}
```

### **C# Implementation**
```csharp
// ITrafficLightState.cs

public interface ITrafficLightState {
  void Handle(TrafficLight trafficLight);
}
```
```csharp
// RedLight.cs

using System;

public class RedLight : ITrafficLightState {
  public void Handle(TrafficLight trafficLight) {
    Console.WriteLine("Red Light - STOP!");
    trafficLight.SetState(new GreenLight()); // Transition to Green
  }
}
```
```csharp
// YellowLight.cs

using System;

public class YellowLight : ITrafficLightState {
  public void Handle(TrafficLight trafficLight) {
    Console.WriteLine("Yellow Light - PREPARE!");
    trafficLight.SetState(new RedLight()); // Transition to Red
  }
}
```
```csharp
// GreenLight.cs

using System;

public class GreenLight : ITrafficLightState {
  public void Handle(TrafficLight trafficLight) {
    Console.WriteLine("Green Light - GO!");
    trafficLight.SetState(new YellowLight()); // Transition to Yellow
  }
}
```
```csharp
// TrafficLight.cs

public class TrafficLight {
  private ITrafficLightState _state;

  public TrafficLight() {
    _state = new RedLight(); // Initial state
  }

  public void SetState(ITrafficLightState state) {
    _state = state;
  }

  public void Change() {
    _state.Handle(this);
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    TrafficLight trafficLight = new TrafficLight();

    for (int i = 0; i < 6; i++) {
      trafficLight.Change();
    }
  }
}
```

### **C++ Implementation**
```cpp
// TrafficLightState.h

#ifndef TRAFFICLIGHTSTATE_H
#define TRAFFICLIGHTSTATE_H

class TrafficLight;

class TrafficLightState {
public:
  virtual void handle(TrafficLight* trafficLight) = 0;
  virtual ~TrafficLightState() = default;
};

#endif // TRAFFICLIGHTSTATE_H
```
```cpp
// RedLight.h

#ifndef REDLIGHT_H
#define REDLIGHT_H

#include "TrafficLightState.h"
#include "TrafficLight.h"
#include "GreenLight.h"
#include <iostream>

class RedLight : public TrafficLightState {
public:
  void handle(TrafficLight* trafficLight) override;
};

#endif // REDLIGHT_H
```
```cpp
// RedLight.cpp

#include "RedLight.h"

void RedLight::handle(TrafficLight* trafficLight) {
  std::cout << "Red Light - STOP!" << std::endl;
  trafficLight->setState(new GreenLight()); // Transition to Green
}
```
```cpp
// YellowLight.h

#ifndef YELLOWLIGHT_H
#define YELLOWLIGHT_H

#include "TrafficLightState.h"
#include "TrafficLight.h"
#include "RedLight.h"
#include <iostream>

class YellowLight : public TrafficLightState {
public:
  void handle(TrafficLight* trafficLight) override;
};

#endif // YELLOWLIGHT_H
```
```cpp
// YellowLight.cpp

#include "YellowLight.h"

void YellowLight::handle(TrafficLight* trafficLight) {
  std::cout << "Yellow Light - PREPARE!" << std::endl;
  trafficLight->setState(new RedLight()); // Transition to Red
}
```
```cpp
// GreenLight.h

#ifndef GREENLIGHT_H
#define GREENLIGHT_H

#include "TrafficLightState.h"
#include "TrafficLight.h"
#include "YellowLight.h"
#include <iostream>

class GreenLight : public TrafficLightState {
public:
  void handle(TrafficLight* trafficLight) override;
};

#endif // GREENLIGHT_H
```
```cpp
// GreenLight.cpp

#include "GreenLight.h"

void GreenLight::handle(TrafficLight* trafficLight) {
  std::cout << "Green Light - GO!" << std::endl;
  trafficLight->setState(new YellowLight()); // Transition to Yellow
}
```
```cpp
// TrafficLight.h

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "TrafficLightState.h"

class TrafficLight {
private:
  TrafficLightState* state;

public:
  TrafficLight();
  ~TrafficLight();
  void setState(TrafficLightState* newState);
  void change();
};

#endif // TRAFFICLIGHT_H
```
```cpp
// TrafficLight.cpp

#include "TrafficLight.h"
#include "RedLight.h"

TrafficLight::TrafficLight() {
  state = new RedLight(); // Initial state
}

TrafficLight::~TrafficLight() {
  delete state;
}

void TrafficLight::setState(TrafficLightState* newState) {
  delete state;
  state = newState;
}

void TrafficLight::change() {
  state->handle(this);
}
```
```cpp
// Main.cpp

#include "TrafficLight.h"

int main() {
  TrafficLight trafficLight;

  for (int i = 0; i < 6; i++) {
    trafficLight.change();
  }

  return 0;
}
```

### **Python Implementation**
```python
# traffic_light_state.py

from abc import ABC, abstractmethod

class TrafficLightState(ABC):
  @abstractmethod
  def handle(self, traffic_light):
    pass
```
```python
# red_light.py

from traffic_light_state import TrafficLightState
import green_light

class RedLight(TrafficLightState):
  def handle(self, traffic_light):
    print("Red Light - STOP!")
    traffic_light.set_state(green_light.GreenLight())  # Transition to Green
```
```python
# yellow_light.py

from traffic_light_state import TrafficLightState
import red_light

class YellowLight(TrafficLightState):
  def handle(self, traffic_light):
    print("Yellow Light - PREPARE!")
    traffic_light.set_state(red_light.RedLight())  # Transition to Red
```
```python
# green_light.py

from traffic_light_state import TrafficLightState
import yellow_light

class GreenLight(TrafficLightState):
  def handle(self, traffic_light):
    print("Green Light - GO!")
    traffic_light.set_state(yellow_light.YellowLight())  # Transition to Yellow
```
```python
# traffic_light.py

import red_light

class TrafficLight:
  def __init__(self):
    self._state = red_light.RedLight()  # Initial state

  def set_state(self, state):
    self._state = state

  def change(self):
    self._state.handle(self)
```
```python
# main.py

from traffic_light import TrafficLight

if __name__ == "__main__":
  traffic_light = TrafficLight()

  for _ in range(6):
    traffic_light.change()
```

### **JavaScript Implementation**
```javascript
// trafficLightState.js

class TrafficLightState {
  handle(trafficLight) {
    throw new Error("Method 'handle()' must be implemented.");
  }
}

module.exports = TrafficLightState;
```
```javascript
// redLight.js

const TrafficLightState = require("./trafficLightState");

class RedLight extends TrafficLightState {
  handle(trafficLight) {
    console.log("Red Light - STOP!");
    
    // Lazy import to avoid circular dependency
    const GreenLight = require("./greenLight");
    trafficLight.setState(new GreenLight()); // Transition to Green
  }
}

module.exports = RedLight;
```
```javascript
// yellowLight.js

const TrafficLightState = require("./trafficLightState");

class YellowLight extends TrafficLightState {
  handle(trafficLight) {
    console.log("Yellow Light - PREPARE!");
    
    // FIX: Require inside the method to avoid circular dependency
    const RedLight = require("./redLight");
    trafficLight.setState(new RedLight()); // Transition to Red
  }
}

module.exports = YellowLight;
```
```javascript
// greenLight.js

const TrafficLightState = require("./trafficLightState");

class GreenLight extends TrafficLightState {
  handle(trafficLight) {
    console.log("Green Light - GO!");
    
    // FIX: Lazy import to avoid circular dependency
    const YellowLight = require("./yellowLight");
    trafficLight.setState(new YellowLight()); // Transition to Yellow
  }
}

module.exports = GreenLight;
```
```javascript
// trafficLight.js

const RedLight = require("./redLight");

class TrafficLight {
  constructor() {
    this.state = new RedLight(); // Initial state
  }

  setState(state) {
    this.state = state;
  }

  change() {
    this.state.handle(this);
  }
}

module.exports = TrafficLight;
```
```javascript
// main.js

const TrafficLight = require("./trafficLight");

const trafficLight = new TrafficLight();

for (let i = 0; i < 6; i++) {
  trafficLight.change();
}
```

## 📌 Running the Code
To test the **State pattern**, run the following commands:

### Java
```sh
cd Behavioral/State/Java
javac *.java
java Main
```

### C#
```sh
cd Behavioral/State/CSharp
dotnet build
dotnet run
```

### C++
```sh
cd Behavioral/State/Cpp
g++ *.cpp -o state
./state
```

### Python
```sh
cd Behavioral/State/Python
python3 main.py
```

### JavaScript
```sh
cd Behavioral/State/JavaScript
node main.js
```

## 📌 Expected Output
```
Red Light - STOP!
Green Light - GO!
Yellow Light - PREPARE!
Red Light - STOP!
Green Light - GO!
Yellow Light - PREPARE!
```

## 📌 Summary
- Encapsulates state-specific behavior in separate classes.
- Eliminates complex conditional logic using polymorphism.
- Allows dynamic behavior modification at runtime.