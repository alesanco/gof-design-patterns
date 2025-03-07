# Facade Pattern

## 📌 What is the Facade Pattern?
The **Facade Pattern** is a structural design pattern that provides a **simplified interface** to a **complex system of classes, libraries, or APIs**. It helps in **hiding complexities** and **providing a unified, high-level interface**.

## 📌 When to Use Facade
Use the **Facade pattern** when:
- You want to **simplify interactions** with a complex system.
- Multiple subsystems have **intricate dependencies**, and you need a single entry point to manage them.
- You need to **decouple the client from the subsystem**, improving maintainability and flexibility.

## 📌 Example: Home Theater System
Imagine a **home theater system** with multiple components like a **DVD player, projector, sound system, and screen**. Instead of exposing each component individually, we provide a **single `HomeTheaterFacade` class** to control them all.

## 📌 Implementation in Different Languages
Each language implements the **Facade pattern** differently based on its capabilities.

### **Java Implementation**
```java
// DVDPlayer.java

public class DVDPlayer {
  public void turnOn() {
    System.out.println("DVD Player is ON.");
  }

  public void turnOff() {
    System.out.println("DVD Player is OFF.");
  }

  public void play(String movie) {
    System.out.println("Playing movie: " + movie);
  }
}
```
```java
// Projector.java

public class Projector {
  public void turnOn() {
    System.out.println("Projector is ON.");
  }

  public void turnOff() {
    System.out.println("Projector is OFF.");
  }

  public void setInput(String input) {
    System.out.println("Projector input set to: " + input);
  }
}
```
```java
// SoundSystem.java

public class SoundSystem {
  public void turnOn() {
    System.out.println("Sound System is ON.");
  }

  public void turnOff() {
    System.out.println("Sound System is OFF.");
  }

  public void setVolume(int level) {
    System.out.println("Sound System volume set to: " + level);
  }
}
```
```java
// Screen.java

public class Screen {
  public void lower() {
    System.out.println("Screen is lowered.");
  }

  public void raise() {
    System.out.println("Screen is raised.");
  }
}
```
```java
// HomeTheaterFacade.java

public class HomeTheaterFacade {
  private DVDPlayer dvdPlayer;
  private Projector projector;
  private SoundSystem soundSystem;
  private Screen screen;

  public HomeTheaterFacade(DVDPlayer dvdPlayer, Projector projector, SoundSystem soundSystem, Screen screen) {
    this.dvdPlayer = dvdPlayer;
    this.projector = projector;
    this.soundSystem = soundSystem;
    this.screen = screen;
  }

  public void watchMovie(String movie) {
    System.out.println("\nGetting ready to watch a movie...");
    screen.lower();
    projector.turnOn();
    projector.setInput("DVD");
    soundSystem.turnOn();
    soundSystem.setVolume(10);
    dvdPlayer.turnOn();
    dvdPlayer.play(movie);
  }

  public void endMovie() {
    System.out.println("\nShutting down home theater...");
    dvdPlayer.turnOff();
    soundSystem.turnOff();
    projector.turnOff();
    screen.raise();
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    DVDPlayer dvdPlayer = new DVDPlayer();
    Projector projector = new Projector();
    SoundSystem soundSystem = new SoundSystem();
    Screen screen = new Screen();

    HomeTheaterFacade homeTheater = new HomeTheaterFacade(dvdPlayer, projector, soundSystem, screen);

    homeTheater.watchMovie("Inception");
    homeTheater.endMovie();
  }
}
```

### **C# Implementation**
```csharp
// DVDPlayer.cs

using System;

public class DVDPlayer {
  public void TurnOn() {
    Console.WriteLine("DVD Player is ON.");
  }

  public void TurnOff() {
    Console.WriteLine("DVD Player is OFF.");
  }

  public void Play(string movie) {
    Console.WriteLine($"Playing movie: {movie}");
  }
}
```
```csharp
// Projector.cs

using System;

public class Projector {
  public void TurnOn() {
    Console.WriteLine("Projector is ON.");
  }

  public void TurnOff() {
    Console.WriteLine("Projector is OFF.");
  }

  public void SetInput(string input) {
    Console.WriteLine($"Projector input set to: {input}");
  }
}
```
```csharp
// SoundSystem.cs

using System;

public class SoundSystem {
  public void TurnOn() {
    Console.WriteLine("Sound System is ON.");
  }

  public void TurnOff() {
    Console.WriteLine("Sound System is OFF.");
  }

  public void SetVolume(int level) {
    Console.WriteLine($"Sound System volume set to: {level}");
  }
}
```
```csharp
// Screen.cs

using System;

public class Screen {
  public void Lower() {
    Console.WriteLine("Screen is lowered.");
  }

  public void Raise() {
    Console.WriteLine("Screen is raised.");
  }
}
```
```csharp
// HomeTheaterFacade.cs

using System;

public class HomeTheaterFacade {
  private DVDPlayer dvdPlayer;
  private Projector projector;
  private SoundSystem soundSystem;
  private Screen screen;

  public HomeTheaterFacade(DVDPlayer dvdPlayer, Projector projector, SoundSystem soundSystem, Screen screen) {
    this.dvdPlayer = dvdPlayer;
    this.projector = projector;
    this.soundSystem = soundSystem;
    this.screen = screen;
  }

  public void WatchMovie(string movie) {
    Console.WriteLine("\nGetting ready to watch a movie...");
    screen.Lower();
    projector.TurnOn();
    projector.SetInput("DVD");
    soundSystem.TurnOn();
    soundSystem.SetVolume(10);
    dvdPlayer.TurnOn();
    dvdPlayer.Play(movie);
  }

  public void EndMovie() {
    Console.WriteLine("\nShutting down home theater...");
    dvdPlayer.TurnOff();
    soundSystem.TurnOff();
    projector.TurnOff();
    screen.Raise();
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    DVDPlayer dvdPlayer = new DVDPlayer();
    Projector projector = new Projector();
    SoundSystem soundSystem = new SoundSystem();
    Screen screen = new Screen();

    HomeTheaterFacade homeTheater = new HomeTheaterFacade(dvdPlayer, projector, soundSystem, screen);

    homeTheater.WatchMovie("Inception");
    homeTheater.EndMovie();
  }
}
```

### **C++ Implementation**
```cpp
// DVDPlayer.h

#ifndef DVDPLAYER_H
#define DVDPLAYER_H

#include <iostream>
#include <string>

class DVDPlayer {
public:
  void turnOn();
  void turnOff();
  void play(const std::string& movie);
};

#endif // DVDPLAYER_H
```
```cpp
// DVDPlayer.cpp

#include "DVDPlayer.h"

void DVDPlayer::turnOn() {
  std::cout << "DVD Player is ON." << std::endl;
}

void DVDPlayer::turnOff() {
  std::cout << "DVD Player is OFF." << std::endl;
}

void DVDPlayer::play(const std::string& movie) {
  std::cout << "Playing movie: " << movie << std::endl;
}
```
```cpp
// Projector.h

#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <iostream>
#include <string>

class Projector {
public:
  void turnOn();
  void turnOff();
  void setInput(const std::string& input);
};

#endif // PROJECTOR_H
```
```cpp
// Projector.cpp

#include "Projector.h"

void Projector::turnOn() {
  std::cout << "Projector is ON." << std::endl;
}

void Projector::turnOff() {
  std::cout << "Projector is OFF." << std::endl;
}

void Projector::setInput(const std::string& input) {
  std::cout << "Projector input set to: " << input << std::endl;
}
```
```cpp
// SoundSystem.h

#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include <iostream>

class SoundSystem {
public:
  void turnOn();
  void turnOff();
  void setVolume(int level);
};

#endif // SOUNDSYSTEM_H
```
```cpp
// SoundSystem.cpp

#include "SoundSystem.h"

void SoundSystem::turnOn() {
  std::cout << "Sound System is ON." << std::endl;
}

void SoundSystem::turnOff() {
  std::cout << "Sound System is OFF." << std::endl;
}

void SoundSystem::setVolume(int level) {
  std::cout << "Sound System volume set to: " << level << std::endl;
}
```
```cpp
// Screen.h

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

class Screen {
public:
  void lower();
  void raise();
};

#endif // SCREEN_H
```
```cpp
// Screen.cpp

#include "Screen.h"

void Screen::lower() {
  std::cout << "Screen is lowered." << std::endl;
}

void Screen::raise() {
  std::cout << "Screen is raised." << std::endl;
}
```
```cpp
// HomeTheaterFacade.h

#ifndef HOMETHEATERFACADE_H
#define HOMETHEATERFACADE_H

#include "DVDPlayer.h"
#include "Projector.h"
#include "SoundSystem.h"
#include "Screen.h"
#include <string>

class HomeTheaterFacade {
private:
  DVDPlayer dvdPlayer;
  Projector projector;
  SoundSystem soundSystem;
  Screen screen;

public:
  HomeTheaterFacade(DVDPlayer dvd, Projector proj, SoundSystem sound, Screen scr);
  void watchMovie(const std::string& movie);
  void endMovie();
};

#endif // HOMETHEATERFACADE_H
```
```cpp
// HomeTheaterFacade.cpp

#include "HomeTheaterFacade.h"
#include <iostream>

HomeTheaterFacade::HomeTheaterFacade(DVDPlayer dvd, Projector proj, SoundSystem sound, Screen scr)
    : dvdPlayer(dvd), projector(proj), soundSystem(sound), screen(scr) {}

void HomeTheaterFacade::watchMovie(const std::string& movie) {
  std::cout << "\nGetting ready to watch a movie..." << std::endl;
  screen.lower();
  projector.turnOn();
  projector.setInput("DVD");
  soundSystem.turnOn();
  soundSystem.setVolume(10);
  dvdPlayer.turnOn();
  dvdPlayer.play(movie);
}

void HomeTheaterFacade::endMovie() {
  std::cout << "\nShutting down home theater..." << std::endl;
  dvdPlayer.turnOff();
  soundSystem.turnOff();
  projector.turnOff();
  screen.raise();
}
```
```cpp
// Main.cpp

#include "HomeTheaterFacade.h"

int main() {
  DVDPlayer dvdPlayer;
  Projector projector;
  SoundSystem soundSystem;
  Screen screen;

  HomeTheaterFacade homeTheater(dvdPlayer, projector, soundSystem, screen);

  homeTheater.watchMovie("Inception");
  homeTheater.endMovie();

  return 0;
}
```

### **Python Implementation**
```python
# dvd_player.py

class DVDPlayer:
  def turn_on(self):
    print("DVD Player is ON.")

  def turn_off(self):
    print("DVD Player is OFF.")

  def play(self, movie):
    print(f"Playing movie: {movie}")
```
```python
# projector.py

class Projector:
  def turn_on(self):
    print("Projector is ON.")

  def turn_off(self):
    print("Projector is OFF.")

  def set_input(self, input_source):
    print(f"Projector input set to: {input_source}")
```
```python
# sound_system.py

class SoundSystem:
  def turn_on(self):
    print("Sound System is ON.")

  def turn_off(self):
    print("Sound System is OFF.")

  def set_volume(self, level):
    print(f"Sound System volume set to: {level}")
```
```python
# screen.py

class Screen:
  def lower(self):
    print("Screen is lowered.")

  def raise_screen(self):
    print("Screen is raised.")
```
```python
# home_theater_facade.py

from dvd_player import DVDPlayer
from projector import Projector
from sound_system import SoundSystem
from screen import Screen

class HomeTheaterFacade:
  def __init__(self, dvd_player, projector, sound_system, screen):
    self.dvd_player = dvd_player
    self.projector = projector
    self.sound_system = sound_system
    self.screen = screen

  def watch_movie(self, movie):
    print("\nGetting ready to watch a movie...")
    self.screen.lower()
    self.projector.turn_on()
    self.projector.set_input("DVD")
    self.sound_system.turn_on()
    self.sound_system.set_volume(10)
    self.dvd_player.turn_on()
    self.dvd_player.play(movie)

  def end_movie(self):
    print("\nShutting down home theater...")
    self.dvd_player.turn_off()
    self.sound_system.turn_off()
    self.projector.turn_off()
    self.screen.raise_screen()
```
```python
# main.py

from dvd_player import DVDPlayer
from projector import Projector
from sound_system import SoundSystem
from screen import Screen
from home_theater_facade import HomeTheaterFacade

if __name__ == "__main__":
  dvd_player = DVDPlayer()
  projector = Projector()
  sound_system = SoundSystem()
  screen = Screen()

  home_theater = HomeTheaterFacade(dvd_player, projector, sound_system, screen)

  home_theater.watch_movie("Inception")
  home_theater.end_movie()
```

### **JavaScript Implementation**
```javascript
// dvdPlayer.js

class DVDPlayer {
  turnOn() {
    console.log("DVD Player is ON.");
  }

  turnOff() {
    console.log("DVD Player is OFF.");
  }

  play(movie) {
    console.log(`Playing movie: ${movie}`);
  }
}

module.exports = DVDPlayer;
```
```javascript
// projector.js

class Projector {
  turnOn() {
    console.log("Projector is ON.");
  }

  turnOff() {
    console.log("Projector is OFF.");
  }

  setInput(inputSource) {
    console.log(`Projector input set to: ${inputSource}`);
  }
}

module.exports = Projector;
```
```javascript
// soundSystem.js

class SoundSystem {
  turnOn() {
    console.log("Sound System is ON.");
  }

  turnOff() {
    console.log("Sound System is OFF.");
  }

  setVolume(level) {
    console.log(`Sound System volume set to: ${level}`);
  }
}

module.exports = SoundSystem;
```
```javascript
// screen.js

class Screen {
  lower() {
    console.log("Screen is lowered.");
  }

  raise() {
    console.log("Screen is raised.");
  }
}

module.exports = Screen;
```
```javascript
// homeTheaterFacade.js

const DVDPlayer = require("./dvdPlayer");
const Projector = require("./projector");
const SoundSystem = require("./soundSystem");
const Screen = require("./screen");

class HomeTheaterFacade {
  constructor(dvdPlayer, projector, soundSystem, screen) {
    this.dvdPlayer = dvdPlayer;
    this.projector = projector;
    this.soundSystem = soundSystem;
    this.screen = screen;
  }

  watchMovie(movie) {
    console.log("\nGetting ready to watch a movie...");
    this.screen.lower();
    this.projector.turnOn();
    this.projector.setInput("DVD");
    this.soundSystem.turnOn();
    this.soundSystem.setVolume(10);
    this.dvdPlayer.turnOn();
    this.dvdPlayer.play(movie);
  }

  endMovie() {
    console.log("\nShutting down home theater...");
    this.dvdPlayer.turnOff();
    this.soundSystem.turnOff();
    this.projector.turnOff();
    this.screen.raise();
  }
}

module.exports = HomeTheaterFacade;
```
```javascript
// main.js

const DVDPlayer = require("./dvdPlayer");
const Projector = require("./projector");
const SoundSystem = require("./soundSystem");
const Screen = require("./screen");
const HomeTheaterFacade = require("./homeTheaterFacade");

const dvdPlayer = new DVDPlayer();
const projector = new Projector();
const soundSystem = new SoundSystem();
const screen = new Screen();

const homeTheater = new HomeTheaterFacade(dvdPlayer, projector, soundSystem, screen);

homeTheater.watchMovie("Inception");
homeTheater.endMovie();
```

## 📌 Running the Code
To test the **Facade pattern**, run the following commands:

### **Java**
```sh
cd Structural/Facade/Java
javac *.java
java Main
```

### **C#**
```sh
cd Structural/Facade/CSharp
dotnet build
dotnet run
```

### **C++**
```sh
cd Structural/Facade/Cpp
g++ *.cpp -o facade
./facade
```

### **Python**
```sh
cd Structural/Facade/Python
python3 main.py
```

### **JavaScript**
```sh
cd Structural/Facade/JavaScript
node main.js
```

## 📌 Expected Output
```
Getting ready to watch a movie...
Screen is lowered.
Projector is ON.
Projector input set to: DVD
Sound System is ON.
Sound System volume set to: 10
DVD Player is ON.
Playing movie: Inception

Shutting down home theater...
DVD Player is OFF.
Sound System is OFF.
Projector is OFF.
Screen is raised.
```

## 📌 Summary
- Simplifies interactions with complex systems by providing a single entry point.
- Decouples clients from subsystem implementations, improving maintainability.
- Improves code readability and reduces dependencies by centralizing operations.