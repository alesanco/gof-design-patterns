# Flyweight Pattern

## 📌 What is the Flyweight Pattern?
The **Flyweight Pattern** is a structural design pattern that **reduces memory usage** by sharing objects instead of creating new instances. It is used when dealing with **a large number of similar objects**, minimizing redundant data storage and improving performance.

## 📌 When to Use Flyweight
Use the **Flyweight pattern** when:

- A large number of objects exist, leading to **high memory consumption**.
- Objects **share common, unchanging data** that can be reused.
- Performance optimization is necessary due to **excessive object creation**.

## 📌 Example: Text Editor Character Storage
Imagine a **text editor** that processes a large amount of text. Instead of creating a new object for each character, the **Flyweight pattern** allows **reusing character objects**, significantly reducing memory consumption.

## 📌 Implementation in Different Languages

### **Java Implementation**
```java
// FlyweightCharacter.java

public class FlyweightCharacter {
  private final char symbol;

  public FlyweightCharacter(char symbol) {
    this.symbol = symbol;
  }

  public void display() {
    System.out.println("Character: " + symbol);
  }
}
```
```java
// CharacterFactory.java

import java.util.HashMap;
import java.util.Map;

public class CharacterFactory {
  private static final Map<Character, FlyweightCharacter> characterPool = new HashMap<>();

  public static FlyweightCharacter getCharacter(char symbol) {
    characterPool.putIfAbsent(symbol, new FlyweightCharacter(symbol));
    return characterPool.get(symbol);
  }

  public static int getPoolSize() {
    return characterPool.size();
  }
}
```
```java
// TextEditor.java

import java.util.ArrayList;
import java.util.List;

public class TextEditor {
  private final List<FlyweightCharacter> characters = new ArrayList<>();

  public void addCharacter(char symbol) {
    characters.add(CharacterFactory.getCharacter(symbol));
  }

  public void displayCharacters() {
    for (FlyweightCharacter character : characters) {
      character.display();
    }
    System.out.println("Total unique characters in memory: " + CharacterFactory.getPoolSize());
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    TextEditor editor = new TextEditor();
    
    String text = "Hello Flyweight!";
    for (char c : text.toCharArray()) {
      editor.addCharacter(c);
    }

    editor.displayCharacters();
  }
}
```

### **C# Implementation**
```csharp
// FlyweightCharacter.cs

using System;

public class FlyweightCharacter {
  private readonly char symbol;

  public FlyweightCharacter(char symbol) {
    this.symbol = symbol;
  }

  public void Display() {
    Console.WriteLine($"Character: {symbol}");
  }
}
```
```csharp
// CharacterFactory.cs

using System;
using System.Collections.Generic;

public static class CharacterFactory {
  private static readonly Dictionary<char, FlyweightCharacter> characterPool = new Dictionary<char, FlyweightCharacter>();

  public static FlyweightCharacter GetCharacter(char symbol) {
    if (!characterPool.ContainsKey(symbol)) {
      characterPool[symbol] = new FlyweightCharacter(symbol);
    }
    return characterPool[symbol];
  }

  public static int GetPoolSize() {
    return characterPool.Count;
  }
}
```
```csharp
// TextEditor.cs

using System;
using System.Collections.Generic;

public class TextEditor {
  private readonly List<FlyweightCharacter> characters = new List<FlyweightCharacter>();

  public void AddCharacter(char symbol) {
    characters.Add(CharacterFactory.GetCharacter(symbol));
  }

  public void DisplayCharacters() {
    foreach (FlyweightCharacter character in characters) {
      character.Display();
    }
    Console.WriteLine($"Total unique characters in memory: {CharacterFactory.GetPoolSize()}");
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    TextEditor editor = new TextEditor();
    
    string text = "Hello Flyweight!";
    foreach (char c in text) {
      editor.AddCharacter(c);
    }

    editor.DisplayCharacters();
  }
}
```

### **C++ Implementation**
```cpp
// FlyweightCharacter.h

#ifndef FLYWEIGHT_CHARACTER_H
#define FLYWEIGHT_CHARACTER_H

#include <iostream>

class FlyweightCharacter {
private:
  char symbol;

public:
  explicit FlyweightCharacter(char symbol);
  void display() const;
};

#endif // FLYWEIGHT_CHARACTER_H
```
```cpp
// FlyweightCharacter.cpp

#include "FlyweightCharacter.h"

FlyweightCharacter::FlyweightCharacter(char symbol) : symbol(symbol) {}

void FlyweightCharacter::display() const {
  std::cout << "Character: " << symbol << std::endl;
}
```
```cpp
// CharacterFactory.h

#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H

#include "FlyweightCharacter.h"
#include <unordered_map>

class CharacterFactory {
private:
  static std::unordered_map<char, FlyweightCharacter*> characterPool;

public:
  static FlyweightCharacter* getCharacter(char symbol);
  static int getPoolSize();
  static void cleanup();
};

#endif // CHARACTER_FACTORY_H
```
```cpp
// CharacterFactory.cpp

#include "CharacterFactory.h"

std::unordered_map<char, FlyweightCharacter*> CharacterFactory::characterPool;

FlyweightCharacter* CharacterFactory::getCharacter(char symbol) {
  if (characterPool.find(symbol) == characterPool.end()) {
    characterPool[symbol] = new FlyweightCharacter(symbol);
  }
  return characterPool[symbol];
}

int CharacterFactory::getPoolSize() {
  return characterPool.size();
}

void CharacterFactory::cleanup() {
  for (auto& pair : characterPool) {
    delete pair.second;
  }
  characterPool.clear();
}
```
```cpp
// TextEditor.h

#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include "CharacterFactory.h"
#include <vector>

class TextEditor {
private:
  std::vector<FlyweightCharacter*> characters;

public:
  void addCharacter(char symbol);
  void displayCharacters() const;
};

#endif // TEXT_EDITOR_H
```
```cpp
// TextEditor.cpp

#include "TextEditor.h"
#include <iostream>

void TextEditor::addCharacter(char symbol) {
  characters.push_back(CharacterFactory::getCharacter(symbol));
}

void TextEditor::displayCharacters() const {
  for (FlyweightCharacter* character : characters) {
    character->display();
  }
  std::cout << "Total unique characters in memory: " << CharacterFactory::getPoolSize() << std::endl;
}
```
```cpp// Main.cpp

#include "TextEditor.h"

int main() {
  TextEditor editor;
  
  std::string text = "Hello Flyweight!";
  for (char c : text) {
    editor.addCharacter(c);
  }

  editor.displayCharacters();

  // Cleanup to prevent memory leaks
  CharacterFactory::cleanup();

  return 0;
}
```

### **Python Implementation**
```python
# flyweight_character.py

class FlyweightCharacter:
  def __init__(self, symbol: str):
    self._symbol = symbol

  def display(self):
    print(f"Character: {self._symbol}")
```
```python
# character_factory.py

from flyweight_character import FlyweightCharacter

class CharacterFactory:
  _character_pool = {}

  @staticmethod
  def get_character(symbol: str):
    if symbol not in CharacterFactory._character_pool:
      CharacterFactory._character_pool[symbol] = FlyweightCharacter(symbol)
    return CharacterFactory._character_pool[symbol]

  @staticmethod
  def get_pool_size():
    return len(CharacterFactory._character_pool)
```
```python
# text_editor.py

from character_factory import CharacterFactory
from flyweight_character import FlyweightCharacter

class TextEditor:
  def __init__(self):
    self._characters = []

  def add_character(self, symbol: str):
    self._characters.append(CharacterFactory.get_character(symbol))

  def display_characters(self):
    for character in self._characters:
      character.display()
    print(f"Total unique characters in memory: {CharacterFactory.get_pool_size()}")
```
```python
# main.py

from text_editor import TextEditor

if __name__ == "__main__":
  editor = TextEditor()
  
  text = "Hello Flyweight!"
  for char in text:
    editor.add_character(char)

  editor.display_characters()
```

### **JavaScript Implementation**
```javascript
// flyweightCharacter.js

class FlyweightCharacter {
  constructor(symbol) {
    this.symbol = symbol;
  }

  display() {
    console.log(`Character: ${this.symbol}`);
  }
}

module.exports = FlyweightCharacter;
```
```javascript
// characterFactory.js

const FlyweightCharacter = require("./flyweightCharacter");

class CharacterFactory {
  static characterPool = new Map();

  static getCharacter(symbol) {
    if (!this.characterPool.has(symbol)) {
      this.characterPool.set(symbol, new FlyweightCharacter(symbol));
    }
    return this.characterPool.get(symbol);
  }

  static getPoolSize() {
    return this.characterPool.size;
  }
}

module.exports = CharacterFactory;
```
```javascript
// textEditor.js

const CharacterFactory = require("./characterFactory");

class TextEditor {
  constructor() {
    this.characters = [];
  }

  addCharacter(symbol) {
    this.characters.push(CharacterFactory.getCharacter(symbol));
  }

  displayCharacters() {
    this.characters.forEach(character => character.display());
    console.log(`Total unique characters in memory: ${CharacterFactory.getPoolSize()}`);
  }
}

module.exports = TextEditor;
```
```javascript
// main.js

const TextEditor = require("./textEditor");

const editor = new TextEditor();

const text = "Hello Flyweight!";
for (const char of text) {
  editor.addCharacter(char);
}

editor.displayCharacters();
```

## 📌 Running the Code
To test the **Flyweight pattern**, run the following commands:

### **Java**
```sh
cd Structural/Flyweight/Java
javac *.java
java Main
```

### **C#**
```sh
cd Structural/Flyweight/CSharp
dotnet build
dotnet run
```

### **C++**
```sh
cd Structural/Flyweight/Cpp
g++ *.cpp -o flyweight
./flyweight
```

### **Python**
```sh
cd Structural/Flyweight/Python
python3 main.py
```

### **JavaScript**
```sh
cd Structural/Flyweight/JavaScript
node main.js
```

## 📌 Expected Output
```
Character: H
Character: e
Character: l
Character: l
Character: o
Character:  
Character: F
Character: l
Character: y
Character: w
Character: e
Character: i
Character: g
Character: h
Character: t
Character: !
Total unique characters in memory: 13
```

## 📌 Summary
- Minimizes memory usage by sharing objects instead of creating new ones.
- Improves performance in scenarios with a large number of similar objects.
- Separates intrinsic (shared) and extrinsic (unique) states of objects.