# Mediator Pattern

## 📌 What is the Mediator Pattern?
The **Mediator Pattern** is a behavioral design pattern that reduces **direct dependencies** between communicating objects by introducing a **mediator object**. Instead of objects referring to each other directly, they interact through a central mediator, improving maintainability and scalability.

## 📌 When to Use Mediator
Use the **Mediator pattern** when:

- A system has **many interacting components**, and direct communication would create a complex dependency structure.
- Changes in one component should not require modifications in others.
- Communication logic needs to be centralized for better control and reusability.

## 📌 Example: Chat Application Mediator
We implement a **chat system** where users send messages to each other. Instead of **direct messaging**, the **ChatMediator** manages communication between users.

## 📌 Implementation in Different Languages
Each language implements the **Mediator pattern** differently based on its capabilities.

### **Java Implementation**
```java
// Mediator.java

public interface Mediator {
  void sendMessage(String message, User user);
}
```
```java
// ChatMediator.java

import java.util.ArrayList;
import java.util.List;

public class ChatMediator implements Mediator {
  private List<User> users = new ArrayList<>();

  public void addUser(User user) {
    users.add(user);
  }

  @Override
  public void sendMessage(String message, User sender) {
    for (User user : users) {
      if (user != sender) {
        user.receiveMessage(message);
      }
    }
  }
}
```
```java
// User.java

public abstract class User {
  protected Mediator mediator;
  protected String name;

  public User(Mediator mediator, String name) {
    this.mediator = mediator;
    this.name = name;
  }

  public abstract void sendMessage(String message);
  public abstract void receiveMessage(String message);
}
```
```java
// ChatUser.java

public class ChatUser extends User {
  public ChatUser(Mediator mediator, String name) {
    super(mediator, name);
  }

  @Override
  public void sendMessage(String message) {
    System.out.println(name + " sends: " + message);
    mediator.sendMessage(message, this);
  }

  @Override
  public void receiveMessage(String message) {
    System.out.println(name + " receives: " + message);
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    ChatMediator chatMediator = new ChatMediator();

    User user1 = new ChatUser(chatMediator, "Alice");
    User user2 = new ChatUser(chatMediator, "Bob");
    User user3 = new ChatUser(chatMediator, "Charlie");

    chatMediator.addUser(user1);
    chatMediator.addUser(user2);
    chatMediator.addUser(user3);

    user1.sendMessage("Hello, everyone!");
    user2.sendMessage("Hey Alice!");
  }
}
```

### **C# Implementation**
```csharp
// IMediator.cs

public interface IMediator {
  void SendMessage(string message, User sender);
}
```
```csharp
// ChatMediator.cs

using System;
using System.Collections.Generic;

public class ChatMediator : IMediator {
  private readonly List<User> _users = new List<User>();

  public void AddUser(User user) {
    _users.Add(user);
  }

  public void SendMessage(string message, User sender) {
    foreach (var user in _users) {
      if (user != sender) {
        user.ReceiveMessage(message);
      }
    }
  }
}
```
```csharp
// User.cs

public abstract class User {
  protected IMediator mediator;
  protected string name;

  public User(IMediator mediator, string name) {
    this.mediator = mediator;
    this.name = name;
  }

  public abstract void SendMessage(string message);
  public abstract void ReceiveMessage(string message);
}
```
```csharp
// ChatUser.cs

using System;

public class ChatUser : User {
  public ChatUser(IMediator mediator, string name) : base(mediator, name) {}

  public override void SendMessage(string message) {
    Console.WriteLine($"{name} sends: {message}");
    mediator.SendMessage(message, this);
  }

  public override void ReceiveMessage(string message) {
    Console.WriteLine($"{name} receives: {message}");
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    ChatMediator chatMediator = new ChatMediator();

    User user1 = new ChatUser(chatMediator, "Alice");
    User user2 = new ChatUser(chatMediator, "Bob");
    User user3 = new ChatUser(chatMediator, "Charlie");

    chatMediator.AddUser(user1);
    chatMediator.AddUser(user2);
    chatMediator.AddUser(user3);

    user1.SendMessage("Hello, everyone!");
    user2.SendMessage("Hey Alice!");
  }
}
```

### **C++ Implementation**
```cpp
// Mediator.h

#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>
class User;

class Mediator {
public:
  virtual ~Mediator() = default;
  virtual void sendMessage(const std::string& message, User* sender) = 0;
};

#endif // MEDIATOR_H
```
```cpp
// ChatMediator.h

#ifndef CHATMEDIATOR_H
#define CHATMEDIATOR_H

#include "Mediator.h"
#include "User.h"
#include <vector>

class ChatMediator : public Mediator {
private:
  std::vector<User*> users;

public:
  void addUser(User* user);
  void sendMessage(const std::string& message, User* sender) override;
};

#endif // CHATMEDIATOR_H
```
```cpp
// ChatMediator.cpp

#include "ChatMediator.h"
#include <iostream>

void ChatMediator::addUser(User* user) {
  users.push_back(user);
}

void ChatMediator::sendMessage(const std::string& message, User* sender) {
  for (User* user : users) {
    if (user != sender) {
      user->receiveMessage(message);
    }
  }
}
```
```cpp
// User.h

#ifndef USER_H
#define USER_H

#include "Mediator.h"
#include <string>

class User {
protected:
  Mediator* mediator;
  std::string name;

public:
  User(Mediator* mediator, std::string name);
  virtual ~User() = default;
  virtual void sendMessage(const std::string& message) = 0;
  virtual void receiveMessage(const std::string& message) = 0;
};

#endif // USER_H
```
```cpp
// User.cpp

#include "User.h"

User::User(Mediator* mediator, std::string name) : mediator(mediator), name(std::move(name)) {}
```
```cpp
// ChatUser.h

#ifndef CHATUSER_H
#define CHATUSER_H

#include "User.h"

class ChatUser : public User {
public:
  ChatUser(Mediator* mediator, std::string name);
  void sendMessage(const std::string& message) override;
  void receiveMessage(const std::string& message) override;
};

#endif // CHATUSER_H
```
```cpp
// ChatUser.cpp

#include "ChatUser.h"
#include <iostream>

ChatUser::ChatUser(Mediator* mediator, std::string name) : User(mediator, std::move(name)) {}

void ChatUser::sendMessage(const std::string& message) {
  std::cout << name << " sends: " << message << std::endl;
  mediator->sendMessage(message, this);
}

void ChatUser::receiveMessage(const std::string& message) {
  std::cout << name << " receives: " << message << std::endl;
}
```
```cpp
// Main.cpp

#include "ChatMediator.h"
#include "ChatUser.h"
#include <iostream>

int main() {
  ChatMediator chatMediator;

  ChatUser user1(&chatMediator, "Alice");
  ChatUser user2(&chatMediator, "Bob");
  ChatUser user3(&chatMediator, "Charlie");

  chatMediator.addUser(&user1);
  chatMediator.addUser(&user2);
  chatMediator.addUser(&user3);

  user1.sendMessage("Hello, everyone!");
  user2.sendMessage("Hey Alice!");

  return 0;
}
```

### **Python Implementation**
```python
# mediator.py

from abc import ABC, abstractmethod

class Mediator(ABC):
  @abstractmethod
  def send_message(self, message, sender):
    pass
```
```python
# chat_mediator.py

from mediator import Mediator

class ChatMediator(Mediator):
  def __init__(self):
    self._users = []

  def add_user(self, user):
    self._users.append(user)

  def send_message(self, message, sender):
    for user in self._users:
      if user != sender:
        user.receive_message(message)
```
```python
# user.py

from abc import ABC, abstractmethod

class User(ABC):
  def __init__(self, mediator, name):
    self._mediator = mediator
    self._name = name

  @abstractmethod
  def send_message(self, message):
    pass

  @abstractmethod
  def receive_message(self, message):
    pass
```
```python
# chat_user.py

from user import User

class ChatUser(User):
  def __init__(self, mediator, name):
    super().__init__(mediator, name)

  def send_message(self, message):
    print(f"{self._name} sends: {message}")
    self._mediator.send_message(message, self)

  def receive_message(self, message):
    print(f"{self._name} receives: {message}")
```
```python
# main.py

from chat_mediator import ChatMediator
from chat_user import ChatUser

if __name__ == "__main__":
  chat_mediator = ChatMediator()

  user1 = ChatUser(chat_mediator, "Alice")
  user2 = ChatUser(chat_mediator, "Bob")
  user3 = ChatUser(chat_mediator, "Charlie")

  chat_mediator.add_user(user1)
  chat_mediator.add_user(user2)
  chat_mediator.add_user(user3)

  user1.send_message("Hello, everyone!")
  user2.send_message("Hey Alice!")
```

### **JavaScript Implementation**
```javascript
// mediator.js

class Mediator {
  sendMessage(message, sender) {
    throw new Error("sendMessage() must be implemented by subclasses");
  }
}

module.exports = Mediator;
```
```javascript
// chatMediator.js

const Mediator = require("./mediator");

class ChatMediator extends Mediator {
  constructor() {
    super();
    this.users = [];
  }

  addUser(user) {
    this.users.push(user);
  }

  sendMessage(message, sender) {
    this.users.forEach(user => {
      if (user !== sender) {
        user.receiveMessage(message);
      }
    });
  }
}

module.exports = ChatMediator;
```
```javascript
// user.js

class User {
  constructor(mediator, name) {
    this.mediator = mediator;
    this.name = name;
  }

  sendMessage(message) {
    throw new Error("sendMessage() must be implemented by subclasses");
  }

  receiveMessage(message) {
    throw new Error("receiveMessage() must be implemented by subclasses");
  }
}

module.exports = User;
```
```javascript
// chatUser.js

const User = require("./user");

class ChatUser extends User {
  constructor(mediator, name) {
    super(mediator, name);
  }

  sendMessage(message) {
    console.log(`${this.name} sends: ${message}`);
    this.mediator.sendMessage(message, this);
  }

  receiveMessage(message) {
    console.log(`${this.name} receives: ${message}`);
  }
}

module.exports = ChatUser;
```
```javascript
// main.js

const ChatMediator = require("./chatMediator");
const ChatUser = require("./chatUser");

const chatMediator = new ChatMediator();

const user1 = new ChatUser(chatMediator, "Alice");
const user2 = new ChatUser(chatMediator, "Bob");
const user3 = new ChatUser(chatMediator, "Charlie");

chatMediator.addUser(user1);
chatMediator.addUser(user2);
chatMediator.addUser(user3);

user1.sendMessage("Hello, everyone!");
user2.sendMessage("Hey Alice!");
```

## 📌 Running the Code
To test the **Mediator pattern**, run the following commands:

### Java
```sh
cd Behavioral/Mediator/Java
javac *.java
java Main
```

### C#
```sh
cd Behavioral/Mediator/CSharp
dotnet build
dotnet run
```

### C++
```sh
cd Behavioral/Mediator/Cpp
g++ *.cpp -o mediator
./mediator
```

### Python
```sh
cd Behavioral/Mediator/Python
python3 main.py
```

### JavaScript
```sh
cd Behavioral/Mediator/JavaScript
node main.js
```

## 📌 Expected Output
```
Alice sends: Hello, everyone!
Bob receives: Hello, everyone!
Charlie receives: Hello, everyone!
Bob sends: Hey Alice!
Alice receives: Hey Alice!
Charlie receives: Hey Alice!
```

## 📌 Summary
- Centralizes communication logic to reduce direct dependencies.
- Encapsulates interaction logic, making components loosely coupled.
- Improves maintainability by managing interactions in a single place.

