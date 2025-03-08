# Observer Pattern

## 📌 What is the Observer Pattern?
The **Observer Pattern** is a behavioral design pattern where an object (the **subject**) maintains a list of dependent objects (**observers**) that need to be notified of any changes in its state. This pattern is useful in event-driven systems, UI frameworks, and real-time applications where multiple components need to react to changes dynamically.

## 📌 When to Use Observer
Use the **Observer pattern** when:

- Multiple objects need to be notified when another object's state changes.
- An object should not depend on the concrete classes of its listeners.
- Implementing **event-driven architectures**, UI frameworks, or pub-sub systems.

## 📌 Example: News Agency & Subscribers
We implement a **News Agency** where users can subscribe to receive news updates.
- **`NewsAgency` (Subject):** Maintains a list of subscribers and notifies them of updates.
- **`Subscriber` (Observer):** Receives news updates and reacts accordingly.
- **`EmailSubscriber` & `SMSSubscriber`:** Specialized subscribers that receive updates via email or SMS.

## 📌 Implementation in Different Languages
Each language implements the **Observer pattern** differently based on its capabilities.

### **Java Implementation**
```java
// Observer.java

public interface Observer {
  void update(String news);
}
```
```java
// Subject.java

public interface Subject {
  void addObserver(Observer observer);
  void removeObserver(Observer observer);
  void notifyObservers(String news);
}
```
```java
// NewsAgency.java

import java.util.ArrayList;
import java.util.List;

public class NewsAgency implements Subject {
  private List<Observer> observers = new ArrayList<>();

  @Override
  public void addObserver(Observer observer) {
    observers.add(observer);
  }

  @Override
  public void removeObserver(Observer observer) {
    observers.remove(observer);
  }

  @Override
  public void notifyObservers(String news) {
    for (Observer observer : observers) {
      observer.update(news);
    }
  }
}
```
```java
// Subscriber.java

public class Subscriber implements Observer {
  private String name;

  public Subscriber(String name) {
    this.name = name;
  }

  protected String getName() {
    return name;
  }

  @Override
  public void update(String news) {
    System.out.println(name + " received news update: " + news);
  }
}
```
```java
// EmailSubscriber.java

public class EmailSubscriber extends Subscriber {
  public EmailSubscriber(String name) {
    super(name);
  }

  @Override
  public void update(String news) {
    System.out.println(getName() + " (Email) received: " + news);
  }
}
```
```java
// SMSSubscriber.java

public class SMSSubscriber extends Subscriber {
  public SMSSubscriber(String name) {
    super(name);
  }

  @Override
  public void update(String news) {
    System.out.println(getName() + " (SMS) received: " + news);
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    NewsAgency agency = new NewsAgency();

    Observer subscriber1 = new EmailSubscriber("Alice");
    Observer subscriber2 = new SMSSubscriber("Bob");
    Observer subscriber3 = new EmailSubscriber("Charlie");

    agency.addObserver(subscriber1);
    agency.addObserver(subscriber2);
    agency.addObserver(subscriber3);

    agency.notifyObservers("Breaking News: Observer Pattern Implemented!");
    
    agency.removeObserver(subscriber2);

    agency.notifyObservers("Update: Java Observer Example Completed!");
  }
}
```

### **C# Implementation**
```csharp
// IObserver.cs

public interface IObserver {
  void Update(string news);
}
```
```csharp
// ISubject.cs

public interface ISubject {
  void AddObserver(IObserver observer);
  void RemoveObserver(IObserver observer);
  void NotifyObservers(string news);
}
```
```csharp
// NewsAgency.cs

using System;
using System.Collections.Generic;

public class NewsAgency : ISubject {
  private List<IObserver> observers = new List<IObserver>();

  public void AddObserver(IObserver observer) {
    observers.Add(observer);
  }

  public void RemoveObserver(IObserver observer) {
    observers.Remove(observer);
  }

  public void NotifyObservers(string news) {
    foreach (IObserver observer in observers) {
      observer.Update(news);
    }
  }
}
```
```csharp
// Subscriber.cs

using System;

public class Subscriber : IObserver {
  protected string Name { get; }

  public Subscriber(string name) {
    Name = name;
  }

  public virtual void Update(string news) {
    Console.WriteLine($"{Name} received news update: {news}");
  }
}
```
```csharp
// EmailSubscriber.cs

using System;

public class EmailSubscriber : Subscriber {
  public EmailSubscriber(string name) : base(name) {}

  public override void Update(string news) {
    Console.WriteLine($"📧 {Name} (Email) received: {news}");
  }
}
```
```csharp
// SMSSubscriber.cs

using System;

public class SMSSubscriber : Subscriber {
  public SMSSubscriber(string name) : base(name) {}

  public override void Update(string news) {
    Console.WriteLine($"📱 {Name} (SMS) received: {news}");
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    NewsAgency agency = new NewsAgency();

    IObserver subscriber1 = new EmailSubscriber("Alice");
    IObserver subscriber2 = new SMSSubscriber("Bob");
    IObserver subscriber3 = new EmailSubscriber("Charlie");

    agency.AddObserver(subscriber1);
    agency.AddObserver(subscriber2);
    agency.AddObserver(subscriber3);

    agency.NotifyObservers("Breaking News: Observer Pattern Implemented!");

    agency.RemoveObserver(subscriber2);

    agency.NotifyObservers("Update: C# Observer Example Completed!");
  }
}
```

### **C++ Implementation**
```cpp
// Observer.h

#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer {
public:
  virtual void update(const std::string& news) = 0;
  virtual ~Observer() = default;
};

#endif // OBSERVER_H
```
```cpp
// Subject.h

#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>

class Subject {
public:
  virtual void addObserver(Observer* observer) = 0;
  virtual void removeObserver(Observer* observer) = 0;
  virtual void notifyObservers(const std::string& news) = 0;
  virtual ~Subject() = default;
};

#endif // SUBJECT_H
```
```cpp
// NewsAgency.h

#ifndef NEWSAGENCY_H
#define NEWSAGENCY_H

#include "Subject.h"
#include <vector>
#include <algorithm>

class NewsAgency : public Subject {
private:
  std::vector<Observer*> observers;

public:
  void addObserver(Observer* observer) override;
  void removeObserver(Observer* observer) override;
  void notifyObservers(const std::string& news) override;
};

#endif // NEWSAGENCY_H
```
```cpp
// NewsAgency.cpp

#include "NewsAgency.h"

void NewsAgency::addObserver(Observer* observer) {
  observers.push_back(observer);
}

void NewsAgency::removeObserver(Observer* observer) {
  observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void NewsAgency::notifyObservers(const std::string& news) {
  for (Observer* observer : observers) {
    observer->update(news);
  }
}
```
```cpp
// Subscriber.cpp

#include "Subscriber.h"

Subscriber::Subscriber(const std::string& name) : name(name) {}

void Subscriber::update(const std::string& news) {
  std::cout << name << " received news update: " << news << std::endl;
}
```
```cpp
// EmailSubscriber.h

#ifndef EMAILSUBSCRIBER_H
#define EMAILSUBSCRIBER_H

#include "Subscriber.h"

class EmailSubscriber : public Subscriber {
public:
  explicit EmailSubscriber(const std::string& name);
  void update(const std::string& news) override;
};

#endif // EMAILSUBSCRIBER_H
```
```cpp
// EmailSubscriber.cpp

#include "EmailSubscriber.h"

EmailSubscriber::EmailSubscriber(const std::string& name) : Subscriber(name) {}

void EmailSubscriber::update(const std::string& news) {
  std::cout << name << " (Email) received: " << news << std::endl;
}
```
```cpp
// SMSSubscriber.h

#ifndef SMSSUBSCRIBER_H
#define SMSSUBSCRIBER_H

#include "Subscriber.h"

class SMSSubscriber : public Subscriber {
public:
  explicit SMSSubscriber(const std::string& name);
  void update(const std::string& news) override;
};

#endif // SMSSUBSCRIBER_H
```
```cpp
// SMSSubscriber.cpp

#include "SMSSubscriber.h"

SMSSubscriber::SMSSubscriber(const std::string& name) : Subscriber(name) {}

void SMSSubscriber::update(const std::string& news) {
  std::cout << name << " (SMS) received: " << news << std::endl;
}
```
```cpp
// Main.cpp

#include "NewsAgency.h"
#include "EmailSubscriber.h"
#include "SMSSubscriber.h"

int main() {
  NewsAgency agency;

  Observer* subscriber1 = new EmailSubscriber("Alice");
  Observer* subscriber2 = new SMSSubscriber("Bob");
  Observer* subscriber3 = new EmailSubscriber("Charlie");

  agency.addObserver(subscriber1);
  agency.addObserver(subscriber2);
  agency.addObserver(subscriber3);

  agency.notifyObservers("Breaking News: Observer Pattern Implemented!");

  agency.removeObserver(subscriber2);

  agency.notifyObservers("Update: C++ Observer Example Completed!");

  delete subscriber1;
  delete subscriber2;
  delete subscriber3;

  return 0;
}
```

### **Python Implementation**
```python
# observer.py

from abc import ABC, abstractmethod

class Observer(ABC):
  @abstractmethod
  def update(self, news):
    pass
```
```python
# subject.py

from abc import ABC, abstractmethod

class Subject(ABC):
  @abstractmethod
  def add_observer(self, observer):
    pass

  @abstractmethod
  def remove_observer(self, observer):
    pass

  @abstractmethod
  def notify_observers(self, news):
    pass
```
```python
# news_agency.py

from subject import Subject

class NewsAgency(Subject):
  def __init__(self):
    self._observers = []

  def add_observer(self, observer):
    self._observers.append(observer)

  def remove_observer(self, observer):
    self._observers.remove(observer)

  def notify_observers(self, news):
    for observer in self._observers:
      observer.update(news)
```
```python
# subscriber.py

from observer import Observer

class Subscriber(Observer):
  def __init__(self, name):
    self._name = name

  def update(self, news):
    print(f"{self._name} received news update: {news}")
```
```python
# email_subscriber.py

from subscriber import Subscriber

class EmailSubscriber(Subscriber):
  def update(self, news):
    print(f"{self._name} (Email) received: {news}")
```
```python
# sms_subscriber.py

from subscriber import Subscriber

class SMSSubscriber(Subscriber):
  def update(self, news):
    print(f"{self._name} (SMS) received: {news}")
```
```python
# main.py

from news_agency import NewsAgency
from email_subscriber import EmailSubscriber
from sms_subscriber import SMSSubscriber

if __name__ == "__main__":
  agency = NewsAgency()

  subscriber1 = EmailSubscriber("Alice")
  subscriber2 = SMSSubscriber("Bob")
  subscriber3 = EmailSubscriber("Charlie")

  agency.add_observer(subscriber1)
  agency.add_observer(subscriber2)
  agency.add_observer(subscriber3)

  agency.notify_observers("Breaking News: Observer Pattern Implemented!")

  agency.remove_observer(subscriber2)

  agency.notify_observers("Update: Python Observer Example Completed!")
```

### **JavaScript Implementation**
```javascript
// observer.js

class Observer {
  update(news) {
    throw new Error("Method 'update()' must be implemented.");
  }
}

module.exports = Observer;
```
```javascript
// subject.js

class Subject {
  constructor() {
    this.observers = [];
  }

  addObserver(observer) {
    this.observers.push(observer);
  }

  removeObserver(observer) {
    this.observers = this.observers.filter(obs => obs !== observer);
  }

  notifyObservers(news) {
    this.observers.forEach(observer => observer.update(news));
  }
}

module.exports = Subject;
```
```javascript
// newsAgency.js

const Subject = require("./subject");

class NewsAgency extends Subject {
  constructor() {
    super();
  }
}

module.exports = NewsAgency;
```
```javascript
// subscriber.js

const Observer = require("./observer");

class Subscriber extends Observer {
  constructor(name) {
    super();
    this.name = name;
  }

  update(news) {
    console.log(`${this.name} received news update: ${news}`);
  }
}

module.exports = Subscriber;
```
```javascript
// emailSubscriber.js

const Subscriber = require("./subscriber");

class EmailSubscriber extends Subscriber {
  update(news) {
    console.log(`${this.name} (Email) received: ${news}`);
  }
}

module.exports = EmailSubscriber;
```
```javascript
// smsSubscriber.js

const Subscriber = require("./subscriber");

class SMSSubscriber extends Subscriber {
  update(news) {
    console.log(`${this.name} (SMS) received: ${news}`);
  }
}

module.exports = SMSSubscriber;
```
```javascript
// main.js

const NewsAgency = require("./newsAgency");
const EmailSubscriber = require("./emailSubscriber");
const SMSSubscriber = require("./smsSubscriber");

const agency = new NewsAgency();

const subscriber1 = new EmailSubscriber("Alice");
const subscriber2 = new SMSSubscriber("Bob");
const subscriber3 = new EmailSubscriber("Charlie");

agency.addObserver(subscriber1);
agency.addObserver(subscriber2);
agency.addObserver(subscriber3);

agency.notifyObservers("Breaking News: Observer Pattern Implemented!");

agency.removeObserver(subscriber2);

agency.notifyObservers("Update: JavaScript Observer Example Completed!");
```

## 📌 Running the Code
To test the **Observer pattern**, run the following commands:

### Java
```sh
cd Behavioral/Observer/Java
javac *.java
java Main
```

### C#
```sh
cd Behavioral/Observer/CSharp
dotnet build
dotnet run
```

### C++
```sh
cd Behavioral/Observer/Cpp
g++ *.cpp -o observer
./observer
```

### Python
```sh
cd Behavioral/Observer/Python
python3 main.py
```

### JavaScript
```sh
cd Behavioral/Observer/JavaScript
node main.js
```

## 📌 Expected Output
```
Alice (Email) received: Breaking News: Observer Pattern Implemented!
Bob (SMS) received: Breaking News: Observer Pattern Implemented!
Charlie (Email) received: Breaking News: Observer Pattern Implemented!

Alice (Email) received: Update: Observer Example Completed!
Charlie (Email) received: Update: Observer Example Completed!
```

## 📌 Summary
- Decouples subjects and observers, enabling flexible subscription.
- Supports dynamic event-driven architectures, used in UI frameworks, messaging systems, etc.
- Ensures multiple observers receive updates automatically.