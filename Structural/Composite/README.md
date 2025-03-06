# Composite Pattern

## 📌 What is the Composite Pattern?
The **Composite Pattern** is a structural design pattern that allows treating individual objects and compositions of objects **uniformly**. It is particularly useful when dealing with **hierarchical structures**, such as file systems, organizational charts, or UI components.

## 📌 When to use Composite
Use the **Composite pattern** when:
- You need to **represent part-whole hierarchies**.
- Clients should **treat individual objects and groups of objects uniformly**.
- Working with **recursive structures**, such as tree-like data structures.

## 📌 Example: File System
Imagine implementing a **file system** where both **files** and **folders** should be treated uniformly. A **folder** can contain **files** and **other folders**, forming a tree structure. The **Composite Pattern** enables recursive operations, like calculating the total size or listing contents, without distinguishing between files and folders.

## 📌 Implementation in Different Languages
Each language implements the **Composite pattern** differently based on its capabilities.

### **Java Implementation**
```java
// FileSystemComponent.java

public interface FileSystemComponent {
  void showDetails();
}
```
```java
// File.java

public class File implements FileSystemComponent {
  private String name;

  public File(String name) {
    this.name = name;
  }

  @Override
  public void showDetails() {
    System.out.println("File: " + name);
  }
}
```
```java
// Folder.java

import java.util.ArrayList;
import java.util.List;

public class Folder implements FileSystemComponent {
  private String name;
  private List<FileSystemComponent> components = new ArrayList<>();

  public Folder(String name) {
    this.name = name;
  }

  public void addComponent(FileSystemComponent component) {
    components.add(component);
  }

  @Override
  public void showDetails() {
    System.out.println("Folder: " + name);
    for (FileSystemComponent component : components) {
      component.showDetails();
    }
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    FileSystemComponent file1 = new File("document.txt");
    FileSystemComponent file2 = new File("photo.jpg");

    Folder folder1 = new Folder("My Documents");
    folder1.addComponent(file1);
    folder1.addComponent(file2);

    FileSystemComponent file3 = new File("video.mp4");
    Folder folder2 = new Folder("Media");
    folder2.addComponent(file3);
    folder2.addComponent(folder1);

    folder2.showDetails();
  }
}
```

### **C# Implementation**
```csharp
// IFileSystemComponent.cs

public interface IFileSystemComponent {
  void ShowDetails();
}
```
```csharp
// File.cs

using System;

public class File : IFileSystemComponent {
  private string name;

  public File(string name) {
    this.name = name;
  }

  public void ShowDetails() {
    Console.WriteLine($"File: {name}");
  }
}
```
```csharp
// Folder.cs

using System;
using System.Collections.Generic;

public class Folder : IFileSystemComponent {
  private string name;
  private List<IFileSystemComponent> components = new List<IFileSystemComponent>();

  public Folder(string name) {
    this.name = name;
  }

  public void AddComponent(IFileSystemComponent component) {
    components.Add(component);
  }

  public void ShowDetails() {
    Console.WriteLine($"Folder: {name}");
    foreach (var component in components) {
      component.ShowDetails();
    }
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    IFileSystemComponent file1 = new File("document.txt");
    IFileSystemComponent file2 = new File("photo.jpg");

    Folder folder1 = new Folder("My Documents");
    folder1.AddComponent(file1);
    folder1.AddComponent(file2);

    IFileSystemComponent file3 = new File("video.mp4");
    Folder folder2 = new Folder("Media");
    folder2.AddComponent(file3);
    folder2.AddComponent(folder1);

    folder2.ShowDetails();
  }
}
```

### **C++ Implementation**
```cpp
// IFileSystemComponent.h

#ifndef IFILESYSTEMCOMPONENT_H
#define IFILESYSTEMCOMPONENT_H

class IFileSystemComponent {
public:
  virtual ~IFileSystemComponent() = default;
  virtual void showDetails() const = 0;
};

#endif // IFILESYSTEMCOMPONENT_H
```
```cpp
// File.h

#ifndef FILE_H
#define FILE_H

#include "IFileSystemComponent.h"
#include <iostream>
#include <string>

class File : public IFileSystemComponent {
private:
  std::string name;

public:
  File(const std::string& name);
  void showDetails() const override;
};

#endif // FILE_H
```
```cpp
// File.cpp

#include "File.h"

File::File(const std::string& name) : name(name) {}

void File::showDetails() const {
  std::cout << "File: " << name << std::endl;
}
```
```cpp
// Folder.h

#ifndef FOLDER_H
#define FOLDER_H

#include "IFileSystemComponent.h"
#include <vector>
#include <memory>
#include <iostream>

class Folder : public IFileSystemComponent {
private:
  std::string name;
  std::vector<std::unique_ptr<IFileSystemComponent>> components;

public:
  Folder(const std::string& name);
  void addComponent(std::unique_ptr<IFileSystemComponent> component);
  void showDetails() const override;
};

#endif // FOLDER_H
```
```cpp
// Folder.cpp

#include "Folder.h"

Folder::Folder(const std::string& name) : name(name) {}

void Folder::addComponent(std::unique_ptr<IFileSystemComponent> component) {
  components.push_back(std::move(component));
}

void Folder::showDetails() const {
  std::cout << "Folder: " << name << std::endl;
  for (const auto& component : components) {
    component->showDetails();
  }
}
```
```cpp
// Main.cpp

#include "File.h"
#include "Folder.h"
#include <memory>

int main() {
  auto file1 = std::make_unique<File>("document.txt");
  auto file2 = std::make_unique<File>("photo.jpg");

  auto folder1 = std::make_unique<Folder>("My Documents");
  folder1->addComponent(std::make_unique<File>("document.txt"));
  folder1->addComponent(std::make_unique<File>("photo.jpg"));

  auto file3 = std::make_unique<File>("video.mp4");
  auto folder2 = std::make_unique<Folder>("Media");
  folder2->addComponent(std::make_unique<File>("video.mp4"));
  folder2->addComponent(std::move(folder1));

  folder2->showDetails();

  return 0;
}
```

### **Python Implementation**
```python
# file_system_component.py

from abc import ABC, abstractmethod

class FileSystemComponent(ABC):
  
  @abstractmethod
  def show_details(self):
    pass
```
```python
# file.py

from file_system_component import FileSystemComponent

class File(FileSystemComponent):
  
  def __init__(self, name):
    self.name = name

  def show_details(self):
    print(f"File: {self.name}")
```
```python
# folder.py

from file_system_component import FileSystemComponent

class Folder(FileSystemComponent):
  
  def __init__(self, name):
    self.name = name
    self.components = []

  def add_component(self, component):
    self.components.append(component)

  def show_details(self):
    print(f"Folder: {self.name}")
    for component in self.components:
      component.show_details()
```
```python
# main.py

from file import File
from folder import Folder

if __name__ == "__main__":
  file1 = File("document.txt")
  file2 = File("photo.jpg")

  folder1 = Folder("My Documents")
  folder1.add_component(file1)
  folder1.add_component(file2)

  file3 = File("video.mp4")
  folder2 = Folder("Media")
  folder2.add_component(file3)
  folder2.add_component(folder1)

  folder2.show_details()
```

### **JavaScript Implementation**
```javascript// fileSystemComponent.js

class FileSystemComponent {
  showDetails() {
    throw new Error("Method 'showDetails()' must be implemented.");
  }
}

module.exports = FileSystemComponent;
```
```javascript
// file.js

const FileSystemComponent = require("./fileSystemComponent");

class File extends FileSystemComponent {
  constructor(name) {
    super();
    this.name = name;
  }

  showDetails() {
    console.log(`File: ${this.name}`);
  }
}

module.exports = File;
```
```javascript
// folder.js

const FileSystemComponent = require("./fileSystemComponent");

class Folder extends FileSystemComponent {
  constructor(name) {
    super();
    this.name = name;
    this.components = [];
  }

  addComponent(component) {
    this.components.push(component);
  }

  showDetails() {
    console.log(`Folder: ${this.name}`);
    this.components.forEach(component => component.showDetails());
  }
}

module.exports = Folder;
```
```javascript
// main.js

const File = require("./file");
const Folder = require("./folder");

const file1 = new File("document.txt");
const file2 = new File("photo.jpg");

const folder1 = new Folder("My Documents");
folder1.addComponent(file1);
folder1.addComponent(file2);

const file3 = new File("video.mp4");
const folder2 = new Folder("Media");
folder2.addComponent(file3);
folder2.addComponent(folder1);

folder2.showDetails();
```

## 📌 Running the Code
To test the **Composite pattern**, run the following commands:

#### Java
```sh
cd Structural/Composite/Java
javac *.java
java Main
```

#### C#
```sh
cd Structural/Composite/CSharp
dotnet build
dotnet run
```

#### C++
```sh
cd Structural/Composite/Cpp
g++ *.cpp -o composite
./composite
```

#### Python
```sh
cd Structural/Composite/Python
python3 main.py
```

#### JavaScript
```sh
cd Structural/Composite/JavaScript
node main.js
```

## 📌 Expected Output
```
Folder: Media
File: video.mp4
Folder: My Documents
File: document.txt
File: photo.jpg
```

## 📌 Summary
- Manages part-whole relationships by treating objects and compositions uniformly.
- Supports recursive structures, such as file systems or organizational hierarchies.
- Simplifies client code by allowing the same operations to apply to both individual objects and groups.