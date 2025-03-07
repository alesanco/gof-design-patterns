# Bridge Pattern

## 📌 What is the Bridge Pattern?
The **Bridge Pattern** is a **structural design pattern that decouples an abstraction from its implementation**, allowing them to evolve independently. It is used to avoid a permanent binding between an abstraction and its implementation and enables flexibility and maintainability in system design.

## 📌 When to Use Bridge
Use the **Bridge pattern** when:
- You want to **separate abstraction from implementation** so they can be extended independently.
- You have **multiple variations of a class** that need to be managed efficiently.
- A **strong coupling between abstraction and implementation** would make the system hard to maintain and extend.

## 📌 Example: Remote Control for Devices
Imagine you are designing a **remote control system** that works with multiple devices, such as **TVs and Radios**. Instead of creating a **separate remote for each device**, the Bridge pattern allows us to separate **device behavior from remote control behavior**, making the system more flexible and maintainable.

## 📌 Implementation in Different Languages
Each language implements the **Bridge pattern** differently based on its capabilities.

### **Java Implementation**
```java
// Device.java

public interface Device {
  void turnOn();
  void turnOff();
  void setVolume(int volume);
  int getVolume();
  boolean isOn();
}
```
```java
// Radio.java

public class Radio implements Device {
  private boolean on = false;
  private int volume = 30;

  @Override
  public void turnOn() {
    on = true;
    System.out.println("Radio is now ON.");
  }

  @Override
  public void turnOff() {
    on = false;
    System.out.println("Radio is now OFF.");
  }

  @Override
  public void setVolume(int volume) {
    this.volume = volume;
    System.out.println("Radio volume set to " + volume);
  }

  @Override
  public int getVolume() {
    return volume;
  }

  @Override
  public boolean isOn() {
    return on;
  }
}
```
```java
// TV.java

public class TV implements Device {
  private boolean on = false;
  private int volume = 50;

  @Override
  public void turnOn() {
    on = true;
    System.out.println("TV is now ON.");
  }

  @Override
  public void turnOff() {
    on = false;
    System.out.println("TV is now OFF.");
  }

  @Override
  public void setVolume(int volume) {
    this.volume = volume;
    System.out.println("TV volume set to " + volume);
  }

  @Override
  public int getVolume() {
    return volume;
  }

  @Override
  public boolean isOn() {
    return on;
  }
}
```
```java
// Remote.java

public abstract class Remote {
  protected Device device;

  public Remote(Device device) {
    this.device = device;
  }

  public void togglePower() {
    if (device.isOn()) {
      device.turnOff();
    } else {
      device.turnOn();
    }
  }

  public abstract void volumeUp();
  public abstract void volumeDown();
}

```
```java
// BasicRemote.java

public class BasicRemote extends Remote {
  public BasicRemote(Device device) {
    super(device);
  }

  @Override
  public void volumeUp() {
    device.setVolume(device.getVolume() + 10);
  }

  @Override
  public void volumeDown() {
    device.setVolume(device.getVolume() - 10);
  }
}
```
```java
// AdvancedRemote.java

public class AdvancedRemote extends BasicRemote {
  public AdvancedRemote(Device device) {
    super(device);
  }

  public void mute() {
    device.setVolume(0);
    System.out.println("Device is muted.");
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    Device tv = new TV();
    Remote basicRemote = new BasicRemote(tv);

    basicRemote.togglePower();
    basicRemote.volumeUp();
    basicRemote.volumeDown();

    Device radio = new Radio();
    AdvancedRemote advancedRemote = new AdvancedRemote(radio);

    advancedRemote.togglePower();
    advancedRemote.volumeUp();
    advancedRemote.mute();
  }
}
```

### **C# Implementation**
```csharp
// IDevice.cs

public interface IDevice {
  void TurnOn();
  void TurnOff();
  void SetVolume(int volume);
  int GetVolume();
  bool IsOn();
}
```
```csharp
// Radio.cs

using System;

public class Radio : IDevice {
  private bool isOn = false;
  private int volume = 30;

  public void TurnOn() {
    isOn = true;
    Console.WriteLine("Radio is now ON.");
  }

  public void TurnOff() {
    isOn = false;
    Console.WriteLine("Radio is now OFF.");
  }

  public void SetVolume(int volume) {
    this.volume = volume;
    Console.WriteLine($"Radio volume set to {volume}");
  }

  public int GetVolume() {
    return volume;
  }

  public bool IsOn() {
    return isOn;
  }
}
```
```csharp
// TV.cs

using System;

public class TV : IDevice {
  private bool isOn = false;
  private int volume = 50;

  public void TurnOn() {
    isOn = true;
    Console.WriteLine("TV is now ON.");
  }

  public void TurnOff() {
    isOn = false;
    Console.WriteLine("TV is now OFF.");
  }

  public void SetVolume(int volume) {
    this.volume = volume;
    Console.WriteLine($"TV volume set to {volume}");
  }

  public int GetVolume() {
    return volume;
  }

  public bool IsOn() {
    return isOn;
  }
}
```
```csharp
// IRemote.cs

public interface IRemote {
  void TogglePower();
  void VolumeUp();
  void VolumeDown();
}
```
```csharp
// BasicRemote.cs

public class BasicRemote : IRemote {
  protected IDevice device;

  public BasicRemote(IDevice device) {
    this.device = device;
  }

  public void TogglePower() {
    if (device.IsOn()) {
      device.TurnOff();
    } else {
      device.TurnOn();
    }
  }

  public void VolumeUp() {
    device.SetVolume(device.GetVolume() + 10);
  }

  public void VolumeDown() {
    device.SetVolume(device.GetVolume() - 10);
  }
}
```
```csharp
// AdvancedRemote.cs

using System;

public class AdvancedRemote : BasicRemote {
  public AdvancedRemote(IDevice device) : base(device) {}

  public void Mute() {
    device.SetVolume(0);
    Console.WriteLine("Device is muted.");
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    IDevice tv = new TV();
    IRemote basicRemote = new BasicRemote(tv);

    basicRemote.TogglePower();
    basicRemote.VolumeUp();
    basicRemote.VolumeDown();

    IDevice radio = new Radio();
    AdvancedRemote advancedRemote = new AdvancedRemote(radio);

    advancedRemote.TogglePower();
    advancedRemote.VolumeUp();
    advancedRemote.Mute();
  }
}
```

### **C++ Implementation**
```cpp
// IDevice.h

#ifndef IDEVICE_H
#define IDEVICE_H

class IDevice {
public:
  virtual ~IDevice() = default;
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
  virtual void setVolume(int volume) = 0;
  virtual int getVolume() const = 0;
  virtual bool isOn() const = 0;
};

#endif // IDEVICE_H
```
```cpp
// Radio.h

#ifndef RADIO_H
#define RADIO_H

#include "IDevice.h"
#include <iostream>

class Radio : public IDevice {
private:
  bool on = false;
  int volume = 30;

public:
  void turnOn() override;
  void turnOff() override;
  void setVolume(int volume) override;
  int getVolume() const override;
  bool isOn() const override;
};

#endif // RADIO_H
```
```cpp
// Radio.cpp

#include "Radio.h"

void Radio::turnOn() {
  on = true;
  std::cout << "Radio is now ON." << std::endl;
}

void Radio::turnOff() {
  on = false;
  std::cout << "Radio is now OFF." << std::endl;
}

void Radio::setVolume(int volume) {
  this->volume = volume;
  std::cout << "Radio volume set to " << volume << std::endl;
}

int Radio::getVolume() const {
  return volume;
}

bool Radio::isOn() const {
  return on;
}
```
```cpp
// TV.h

#ifndef TV_H
#define TV_H

#include "IDevice.h"
#include <iostream>

class TV : public IDevice {
private:
  bool on = false;
  int volume = 50;

public:
  void turnOn() override;
  void turnOff() override;
  void setVolume(int volume) override;
  int getVolume() const override;
  bool isOn() const override;
};

#endif // TV_H
```
```cpp
// TV.cpp

#include "TV.h"

void TV::turnOn() {
  on = true;
  std::cout << "TV is now ON." << std::endl;
}

void TV::turnOff() {
  on = false;
  std::cout << "TV is now OFF." << std::endl;
}

void TV::setVolume(int volume) {
  this->volume = volume;
  std::cout << "TV volume set to " << volume << std::endl;
}

int TV::getVolume() const {
  return volume;
}

bool TV::isOn() const {
  return on;
}
```
```cpp
// IRemote.h

#ifndef IREMOTE_H
#define IREMOTE_H

#include "IDevice.h"

class IRemote {
protected:
  IDevice* device;

public:
  IRemote(IDevice* device) : device(device) {}
  virtual ~IRemote() = default;
  virtual void togglePower() = 0;
  virtual void volumeUp() = 0;
  virtual void volumeDown() = 0;
};

#endif // IREMOTE_H
```
```cpp
// BasicRemote.h

#ifndef BASICREMOTE_H
#define BASICREMOTE_H

#include "IRemote.h"

class BasicRemote : public IRemote {
public:
  BasicRemote(IDevice* device);
  void togglePower() override;
  void volumeUp() override;
  void volumeDown() override;
};

#endif // BASICREMOTE_H
```
```cpp
// BasicRemote.cpp

#include "BasicRemote.h"
#include <iostream>

BasicRemote::BasicRemote(IDevice* device) : IRemote(device) {}

void BasicRemote::togglePower() {
  if (device->isOn()) {
    device->turnOff();
  } else {
    device->turnOn();
  }
}

void BasicRemote::volumeUp() {
  device->setVolume(device->getVolume() + 10);
}

void BasicRemote::volumeDown() {
  device->setVolume(device->getVolume() - 10);
}
```
```cpp
// AdvancedRemote.h

#ifndef ADVANCEDREMOTE_H
#define ADVANCEDREMOTE_H

#include "BasicRemote.h"

class AdvancedRemote : public BasicRemote {
public:
  AdvancedRemote(IDevice* device);
  void mute();
};

#endif // ADVANCEDREMOTE_H
```
```cpp
// AdvancedRemote.cpp

#include "AdvancedRemote.h"
#include <iostream>

AdvancedRemote::AdvancedRemote(IDevice* device) : BasicRemote(device) {}

void AdvancedRemote::mute() {
  device->setVolume(0);
  std::cout << "Device is muted." << std::endl;
}
```
```cpp
// Main.cpp

#include "TV.h"
#include "Radio.h"
#include "BasicRemote.h"
#include "AdvancedRemote.h"

int main() {
  IDevice* tv = new TV();
  BasicRemote basicRemote(tv);

  basicRemote.togglePower();
  basicRemote.volumeUp();
  basicRemote.volumeDown();

  IDevice* radio = new Radio();
  AdvancedRemote advancedRemote(radio);

  advancedRemote.togglePower();
  advancedRemote.volumeUp();
  advancedRemote.mute();

  delete tv;
  delete radio;

  return 0;
}
```

### **Python Implementation**
```python
# device.py

from abc import ABC, abstractmethod

class Device(ABC):
  @abstractmethod
  def turn_on(self):
    pass

  @abstractmethod
  def turn_off(self):
    pass

  @abstractmethod
  def set_volume(self, volume: int):
    pass

  @abstractmethod
  def get_volume(self) -> int:
    pass

  @abstractmethod
  def is_on(self) -> bool:
    pass
```
```python
# radio.py

from device import Device

class Radio(Device):
  def __init__(self):
    self._on = False
    self._volume = 30

  def turn_on(self):
    self._on = True
    print("Radio is now ON.")

  def turn_off(self):
    self._on = False
    print("Radio is now OFF.")

  def set_volume(self, volume: int):
    self._volume = volume
    print(f"Radio volume set to {volume}")

  def get_volume(self) -> int:
    return self._volume

  def is_on(self) -> bool:
    return self._on
```
```python
# tv.py

from device import Device

class TV(Device):
  def __init__(self):
    self._on = False
    self._volume = 50

  def turn_on(self):
    self._on = True
    print("TV is now ON.")

  def turn_off(self):
    self._on = False
    print("TV is now OFF.")

  def set_volume(self, volume: int):
    self._volume = volume
    print(f"TV volume set to {volume}")

  def get_volume(self) -> int:
    return self._volume

  def is_on(self) -> bool:
    return self._on
```
```python
# remote.py

from abc import ABC, abstractmethod
from device import Device

class Remote(ABC):
  def __init__(self, device: Device):
    self.device = device

  def toggle_power(self):
    if self.device.is_on():
      self.device.turn_off()
    else:
      self.device.turn_on()

  @abstractmethod
  def volume_up(self):
    pass

  @abstractmethod
  def volume_down(self):
    pass
```
```python
# basic_remote.py

from remote import Remote

class BasicRemote(Remote):
  def volume_up(self):
    self.device.set_volume(self.device.get_volume() + 10)
  def volume_down(self):
    self.device.set_volume(self.device.get_volume() - 10)
```
```python
# advanced_remote.py

from basic_remote import BasicRemote

class AdvancedRemote(BasicRemote):
  def mute(self):
    self.device.set_volume(0)
    print("Device is muted.")
```
```python
# main.py

from tv import TV
from radio import Radio
from basic_remote import BasicRemote
from advanced_remote import AdvancedRemote

if __name__ == "__main__":
  tv = TV()
  basic_remote = BasicRemote(tv)

  basic_remote.toggle_power()
  basic_remote.volume_up()
  basic_remote.volume_down()

  radio = Radio()
  advanced_remote = AdvancedRemote(radio)

  advanced_remote.toggle_power()
  advanced_remote.volume_up()
  advanced_remote.mute()
```

### **JavaScript Implementation**
```javascript
// device.js

class Device {
  turnOn() {
    throw new Error("Method 'turnOn()' must be implemented.");
  }

  turnOff() {
    throw new Error("Method 'turnOff()' must be implemented.");
  }

  setVolume(volume) {
    throw new Error("Method 'setVolume()' must be implemented.");
  }

  getVolume() {
    throw new Error("Method 'getVolume()' must be implemented.");
  }

  isOn() {
    throw new Error("Method 'isOn()' must be implemented.");
  }
}

module.exports = Device;
```
```javascript
// radio.js

const Device = require("./device");

class Radio extends Device {
  constructor() {
    super();
    this.on = false;
    this.volume = 30;
  }

  turnOn() {
    this.on = true;
    console.log("Radio is now ON.");
  }

  turnOff() {
    this.on = false;
    console.log("Radio is now OFF.");
  }

  setVolume(volume) {
    this.volume = volume;
    console.log(`Radio volume set to ${volume}`);
  }

  getVolume() {
    return this.volume;
  }

  isOn() {
    return this.on;
  }
}

module.exports = Radio;
```
```javascript
// tv.js

const Device = require("./device");

class TV extends Device {
  constructor() {
    super();
    this.on = false;
    this.volume = 50;
  }

  turnOn() {
    this.on = true;
    console.log("TV is now ON.");
  }

  turnOff() {
    this.on = false;
    console.log("TV is now OFF.");
  }

  setVolume(volume) {
    this.volume = volume;
    console.log(`TV volume set to ${volume}`);
  }

  getVolume() {
    return this.volume;
  }

  isOn() {
    return this.on;
  }
}

module.exports = TV;
```
```javascript
// remote.js

class Remote {
  constructor(device) {
    this.device = device;
  }

  togglePower() {
    if (this.device.isOn()) {
      this.device.turnOff();
    } else {
      this.device.turnOn();
    }
  }
}

module.exports = Remote;
```
```javascript
// basicRemote.js

const Remote = require("./remote");

class BasicRemote extends Remote {
  volumeUp() {
    this.device.setVolume(this.device.getVolume() + 10);
  }

  volumeDown() {
    this.device.setVolume(this.device.getVolume() - 10);
  }
}

module.exports = BasicRemote;
```
```javascript
// advancedRemote.js

const BasicRemote = require("./basicRemote");

class AdvancedRemote extends BasicRemote {
  mute() {
    this.device.setVolume(0);
    console.log("Device is muted.");
  }
}

module.exports = AdvancedRemote;
```
```javascript
// main.js

const TV = require("./tv");
const Radio = require("./radio");
const BasicRemote = require("./basicRemote");
const AdvancedRemote = require("./advancedRemote");

const tv = new TV();
const basicRemote = new BasicRemote(tv);

basicRemote.togglePower();
basicRemote.volumeUp();
basicRemote.volumeDown();

const radio = new Radio();
const advancedRemote = new AdvancedRemote(radio);

advancedRemote.togglePower();
advancedRemote.volumeUp();
advancedRemote.mute();
```

## 📌 Running the Code
To test the **Bridge pattern**, run the following commands:

### **Java**
```sh
cd Structural/Bridge/Java
javac *.java
java Main
```

### **C#**
```sh
cd Structural/Bridge/CSharp
dotnet build
dotnet run
```

### **C++**
```sh
cd Structural/Bridge/Cpp
g++ *.cpp -o bridge
./bridge
```

### **Python**
```sh
cd Structural/Bridge/Python
python3 main.py
```

### **JavaScript**
```sh
cd Structural/Bridge/JavaScript
node main.js
```

## 📌 Expected Output
```
TV is now ON.
TV volume set to 60
TV volume set to 50
Radio is now ON.
Radio volume set to 40
Radio volume set to 0
Device is muted.
```

## 📌 Summary
- Decouples abstraction from implementation, allowing independent evolution.
- Reduces class explosion by avoiding deep inheritance hierarchies.
- Improves maintainability by separating high-level control from low-level operations.