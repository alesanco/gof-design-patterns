# Memento Pattern

## 📌 What is the Memento Pattern?
The **Memento Pattern** is a behavioral design pattern that allows an object to **save and restore its state** without exposing its internal structure. This is useful for implementing undo/redo functionality in applications such as text editors, games, and configuration management systems.

## 📌 When to Use Memento
Use the **Memento pattern** when:

- You need to implement **undo/redo functionality**.
- An object's state must be **restored to a previous version** without exposing its internal details.
- Saving and restoring state **should not break encapsulation**.

## 📌 Example: Text Editor with Undo Functionality
We implement a **text editor** where a user can type text and undo their changes. Instead of tracking all modifications manually, we use a **Memento object** to store snapshots of the text content.

### 📌 Implementation in Different Languages
Each language implements the **Memento pattern** differently based on its capabilities.

#### **Java Implementation**
```java
// EditorMemento.java

public class EditorMemento {
  private final String content;

  public EditorMemento(String content) {
    this.content = content;
  }

  public String getContent() {
    return content;
  }
}
```
```java
// Editor.java

public class Editor {
  private String content = "";

  public void type(String words) {
    content = words;
  }

  public EditorMemento save() {
    return new EditorMemento(content);
  }

  public void restore(EditorMemento memento) {
    if (memento != null) {
      content = memento.getContent();
    }
  }

  public String getContent() {
    return content;
  }
}
```
```java
// History.java

import java.util.Stack;

public class History {
  private Stack<EditorMemento> history = new Stack<>();

  public void save(EditorMemento memento) {
    if (memento != null) {
      history.push(memento);
    }
  }

  public EditorMemento undo() {
    if (history.size() > 1) {
      history.pop(); // Remove the latest state
    }
    return history.isEmpty() ? null : history.peek(); // Return the previous state
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    Editor editor = new Editor();
    History history = new History();

    // Always save the initial empty state
    history.save(editor.save());

    // Save before making any changes
    editor.type("Hello, World!");
    history.save(editor.save());

    editor.type("New content added.");
    history.save(editor.save());

    System.out.println("Current content: " + editor.getContent());

    editor.restore(history.undo());
    System.out.println("After undo: " + editor.getContent());

    editor.restore(history.undo());
    System.out.println("After second undo: " + editor.getContent());
  }
}
```

#### **C# Implementation**
```csharp
// EditorMemento.cs

public class EditorMemento {
  public string Content { get; }

  public EditorMemento(string content) {
    Content = content;
  }
}
```
```csharp
// Editor.cs

public class Editor {
  private string content = "";

  public void Type(string words) {
    content = words;
  }

  public EditorMemento Save() {
    return new EditorMemento(content);
  }

  public void Restore(EditorMemento memento) {
    if (memento != null) {
      content = memento.Content;
    }
  }

  public string GetContent() {
    return content;
  }
}
```
```csharp
// History.cs

using System.Collections.Generic;

public class History {
  private Stack<EditorMemento> history = new Stack<EditorMemento>();

  public void Save(EditorMemento memento) {
    if (memento != null) {
      history.Push(memento);
    }
  }

  public EditorMemento Undo() {
    if (history.Count > 1) {
      history.Pop(); // Remove the latest state
    }
    return history.Count > 0 ? history.Peek() : null; // Return the previous state
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    Editor editor = new Editor();
    History history = new History();

    // Always save the initial empty state
    history.Save(editor.Save());

    // Save before making any changes
    editor.Type("Hello, World!");
    history.Save(editor.Save());

    editor.Type("New content added.");
    history.Save(editor.Save());

    Console.WriteLine("Current content: " + editor.GetContent());

    editor.Restore(history.Undo());
    Console.WriteLine("After undo: " + editor.GetContent());

    editor.Restore(history.Undo());
    Console.WriteLine("After second undo: " + editor.GetContent());
  }
}
```

#### **C++ Implementation**
```cpp
// EditorMemento.h

#ifndef EDITORMEMENTO_H
#define EDITORMEMENTO_H

#include <string>

class EditorMemento {
private:
  std::string content;

public:
  explicit EditorMemento(const std::string& content);
  std::string getContent() const;
};

#endif // EDITORMEMENTO_H
```
```cpp
// EditorMemento.cpp

#include "EditorMemento.h"

EditorMemento::EditorMemento(const std::string& content) : content(content) {}

std::string EditorMemento::getContent() const {
  return content;
}
```
```cpp
// Editor.h

#ifndef EDITOR_H
#define EDITOR_H

#include "EditorMemento.h"
#include <string>

class Editor {
private:
  std::string content;

public:
  void type(const std::string& words);
  EditorMemento save() const;
  void restore(const EditorMemento& memento);
  std::string getContent() const;
};

#endif // EDITOR_H
```
```cpp
// Editor.cpp

#include "Editor.h"

void Editor::type(const std::string& words) {
  content = words;
}

EditorMemento Editor::save() const {
  return EditorMemento(content);
}

void Editor::restore(const EditorMemento& memento) {
  content = memento.getContent();
}

std::string Editor::getContent() const {
  return content;
}
```
```cpp
// History.h

#ifndef HISTORY_H
#define HISTORY_H

#include "EditorMemento.h"
#include <stack>

class History {
private:
  std::stack<EditorMemento> history;

public:
  void save(const EditorMemento& memento);
  EditorMemento undo();
};

#endif // HISTORY_H
```
```cpp
// History.cpp

#include "History.h"

void History::save(const EditorMemento& memento) {
  history.push(memento);
}

EditorMemento History::undo() {
  if (history.size() > 1) {
    history.pop(); // Remove the latest state
  }
  return history.empty() ? EditorMemento("") : history.top(); // Return the previous state
}
```
```cpp
// Main.cpp

#include "Editor.h"
#include "History.h"
#include <iostream>

int main() {
  Editor editor;
  History history;

  // Always save the initial empty state
  history.save(editor.save());

  // Save before making any changes
  editor.type("Hello, World!");
  history.save(editor.save());

  editor.type("New content added.");
  history.save(editor.save());

  std::cout << "Current content: " << editor.getContent() << std::endl;

  editor.restore(history.undo());
  std::cout << "After undo: " << editor.getContent() << std::endl;

  editor.restore(history.undo());
  std::cout << "After second undo: " << editor.getContent() << std::endl;

  return 0;
}
```

#### **Python Implementation**
```python
# editor_memento.py

class EditorMemento:
  def __init__(self, content):
    self._content = content

  def get_content(self):
    return self._content
```
```python
# editor.py

from editor_memento import EditorMemento

class Editor:
  def __init__(self):
    self._content = ""

  def type(self, words):
    self._content = words

  def save(self):
    return EditorMemento(self._content)

  def restore(self, memento):
    if memento:
      self._content = memento.get_content()

  def get_content(self):
    return self._content
```
```python
# history.py

class History:
  def __init__(self):
    self._history = []

  def save(self, memento):
    if memento:
      self._history.append(memento)

  def undo(self):
    if len(self._history) > 1:
      self._history.pop()  # Remove the latest state
    return self._history[-1] if self._history else None
```
```python
# main.py

from editor import Editor
from history import History

if __name__ == "__main__":
  editor = Editor()
  history = History()

  # Always save the initial empty state
  history.save(editor.save())

  # Save before making any changes
  editor.type("Hello, World!")
  history.save(editor.save())

  editor.type("New content added.")
  history.save(editor.save())

  print("Current content:", editor.get_content())

  editor.restore(history.undo())
  print("After undo:", editor.get_content())

  editor.restore(history.undo())
  print("After second undo:", editor.get_content())
```

#### **JavaScript Implementation**
```javascript
// editorMemento.js

class EditorMemento {
  constructor(content) {
    this._content = content;
  }

  getContent() {
    return this._content;
  }
}

module.exports = EditorMemento;
```
```javascript
// editor.js

const EditorMemento = require("./editorMemento");

class Editor {
  constructor() {
    this._content = "";
  }

  type(words) {
    this._content = words;
  }

  save() {
    return new EditorMemento(this._content);
  }

  restore(memento) {
    if (memento) {
      this._content = memento.getContent();
    }
  }

  getContent() {
    return this._content;
  }
}

module.exports = Editor;
```
```javascript
// history.js

class History {
  constructor() {
    this._history = [];
  }

  save(memento) {
    if (memento) {
      this._history.push(memento);
    }
  }

  undo() {
    if (this._history.length > 1) {
      this._history.pop(); // Remove the latest state
    }
    return this._history.length > 0 ? this._history[this._history.length - 1] : null;
  }
}

module.exports = History;
```
```javascript
// main.js

const Editor = require("./editor");
const History = require("./history");

const editor = new Editor();
const history = new History();

// Always save the initial empty state
history.save(editor.save());

// Save before making any changes
editor.type("Hello, World!");
history.save(editor.save());

editor.type("New content added.");
history.save(editor.save());

console.log("Current content:", editor.getContent());

editor.restore(history.undo());
console.log("After undo:", editor.getContent());

editor.restore(history.undo());
console.log("After second undo:", editor.getContent());
```

### 📌 Running the Code
To test the **Memento pattern**, run the following commands:

#### **Java**
```sh
cd Behavioral/Memento/Java
javac *.java
java Main
```

#### **C#**
```sh
cd Behavioral/Memento/CSharp
dotnet build
dotnet run
```

#### **C++**
```sh
cd Behavioral/Memento/Cpp
g++ *.cpp -o memento
./memento
```

#### **Python**
```sh
cd Behavioral/Memento/Python
python3 main.py
```

#### **JavaScript**
```sh
cd Behavioral/Memento/JavaScript
node main.js
```

### 📌 Expected Output
```
Current content: New content added.
After undo: Hello, World!
After second undo:
```

## 📌 Summary
- Encapsulates state changes without violating encapsulation.
- Supports multiple undo levels, enabling state management flexibility.
- Simplifies state restoration, reducing complexity in the main object.