# Strategy Pattern

## 📌 What is the Strategy Pattern?
The **Strategy Pattern** is a behavioral design pattern that **defines a family of algorithms, encapsulates each one, and makes them interchangeable at runtime**. This pattern allows the algorithm to be selected at runtime instead of being hardcoded into the client.

## 📌 When to Use the Strategy Pattern
Use the **Strategy pattern** when:
- There are multiple ways to perform an operation and selecting the method dynamically is needed.
- There is a need to **eliminate multiple conditional statements** controlling different behaviors.
- Algorithms must be **encapsulated and interchangeable** without modifying client code.

## 📌 Example: Payment Processing System
A **Payment Processing System** where users can choose between different payment methods:

- **Credit Card Payment**
- **PayPal Payment**
- **Bitcoin Payment**

Each payment method is encapsulated as a separate strategy that can be switched dynamically.

## 📌 Implementation in Different Languages
Each language implements the **Strategy pattern** differently based on its capabilities.

### **Java Implementation**
```java
// PaymentStrategy.java

public interface PaymentStrategy {
  void pay(double amount);
}
```
```java
// CreditCardPayment.java

public class CreditCardPayment implements PaymentStrategy {
  private String cardNumber;

  public CreditCardPayment(String cardNumber) {
    this.cardNumber = cardNumber;
  }

  @Override
  public void pay(double amount) {
    System.out.println("Paid $" + amount + " using Credit Card (Card Number: " + cardNumber + ")");
  }
}
```
```java
// PayPalPayment.java

public class PayPalPayment implements PaymentStrategy {
  private String email;

  public PayPalPayment(String email) {
    this.email = email;
  }

  @Override
  public void pay(double amount) {
    System.out.println("Paid $" + amount + " using PayPal (Email: " + email + ")");
  }
}
```
```java
// BitcoinPayment.java

public class BitcoinPayment implements PaymentStrategy {
  private String walletAddress;

  public BitcoinPayment(String walletAddress) {
    this.walletAddress = walletAddress;
  }

  @Override
  public void pay(double amount) {
    System.out.println("Paid $" + amount + " using Bitcoin (Wallet: " + walletAddress + ")");
  }
}
```
```java
// PaymentProcessor.java

public class PaymentProcessor {
  private PaymentStrategy paymentStrategy;

  public void setPaymentStrategy(PaymentStrategy paymentStrategy) {
    this.paymentStrategy = paymentStrategy;
  }

  public void processPayment(double amount) {
    if (paymentStrategy == null) {
      System.out.println("No payment strategy selected.");
      return;
    }
    paymentStrategy.pay(amount);
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    PaymentProcessor processor = new PaymentProcessor();

    processor.setPaymentStrategy(new CreditCardPayment("1234-5678-9876-5432"));
    processor.processPayment(100.0);

    processor.setPaymentStrategy(new PayPalPayment("user@example.com"));
    processor.processPayment(50.0);

    processor.setPaymentStrategy(new BitcoinPayment("1A2b3C4d5E6f7G8h9I"));
    processor.processPayment(200.0);
  }
}
```

### **C# Implementation**
```csharp
// IPaymentStrategy.cs

public interface IPaymentStrategy {
  void Pay(double amount);
}
```
```csharp
// CreditCardPayment.cs

using System;

public class CreditCardPayment : IPaymentStrategy {
  private string _cardNumber;

  public CreditCardPayment(string cardNumber) {
    _cardNumber = cardNumber;
  }

  public void Pay(double amount) {
    Console.WriteLine($"Paid ${amount} using Credit Card (Card Number: {_cardNumber})");
  }
}
```
```csharp
// PayPalPayment.cs

using System;

public class PayPalPayment : IPaymentStrategy {
  private string _email;

  public PayPalPayment(string email) {
    _email = email;
  }

  public void Pay(double amount) {
    Console.WriteLine($"Paid ${amount} using PayPal (Email: {_email})");
  }
}
```
```csharp
// BitcoinPayment.cs

using System;

public class BitcoinPayment : IPaymentStrategy {
  private string _walletAddress;

  public BitcoinPayment(string walletAddress) {
    _walletAddress = walletAddress;
  }

  public void Pay(double amount) {
    Console.WriteLine($"Paid ${amount} using Bitcoin (Wallet: {_walletAddress})");
  }
}
```
```csharp
// PaymentProcessor.cs

using System;

public class PaymentProcessor {
  private IPaymentStrategy? _paymentStrategy;

  public void SetPaymentStrategy(IPaymentStrategy paymentStrategy) {
    _paymentStrategy = paymentStrategy;
  }

  public void ProcessPayment(double amount) {
    if (_paymentStrategy == null) {
      Console.WriteLine("No payment strategy selected.");
      return;
    }
    _paymentStrategy.Pay(amount);
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    PaymentProcessor processor = new PaymentProcessor();

    processor.SetPaymentStrategy(new CreditCardPayment("1234-5678-9876-5432"));
    processor.ProcessPayment(100.0);

    processor.SetPaymentStrategy(new PayPalPayment("user@example.com"));
    processor.ProcessPayment(50.0);

    processor.SetPaymentStrategy(new BitcoinPayment("1A2b3C4d5E6f7G8h9I"));
    processor.ProcessPayment(200.0);
  }
}
```

### **C++ Implementation**
```cpp
// PaymentStrategy.h

#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H

class PaymentStrategy {
public:
  virtual void pay(double amount) = 0;
  virtual ~PaymentStrategy() = default;
};

#endif // PAYMENTSTRATEGY_H
```
```cpp
// CreditCardPayment.h

#ifndef CREDITCARDPAYMENT_H
#define CREDITCARDPAYMENT_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

class CreditCardPayment : public PaymentStrategy {
private:
  std::string cardNumber;

public:
  explicit CreditCardPayment(const std::string& cardNumber);
  void pay(double amount) override;
};

#endif // CREDITCARDPAYMENT_H
```
```cpp
// CreditCardPayment.cpp

#include "CreditCardPayment.h"

CreditCardPayment::CreditCardPayment(const std::string& cardNumber) : cardNumber(cardNumber) {}

void CreditCardPayment::pay(double amount) {
  std::cout << "Paid $" << amount << " using Credit Card (Card Number: " << cardNumber << ")" << std::endl;
}
```
```cpp
// PayPalPayment.h

#ifndef PAYPALPAYMENT_H
#define PAYPALPAYMENT_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

class PayPalPayment : public PaymentStrategy {
private:
  std::string email;

public:
  explicit PayPalPayment(const std::string& email);
  void pay(double amount) override;
};

#endif // PAYPALPAYMENT_H
```
```cpp
// PayPalPayment.cpp

#include "PayPalPayment.h"

PayPalPayment::PayPalPayment(const std::string& email) : email(email) {}

void PayPalPayment::pay(double amount) {
  std::cout << "Paid $" << amount << " using PayPal (Email: " << email << ")" << std::endl;
}
```
```cpp
// BitcoinPayment.h

#ifndef BITCOINPAYMENT_H
#define BITCOINPAYMENT_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

class BitcoinPayment : public PaymentStrategy {
private:
  std::string walletAddress;

public:
  explicit BitcoinPayment(const std::string& walletAddress);
  void pay(double amount) override;
};

#endif // BITCOINPAYMENT_H
```
```cpp
// BitcoinPayment.cpp

#include "BitcoinPayment.h"

BitcoinPayment::BitcoinPayment(const std::string& walletAddress) : walletAddress(walletAddress) {}

void BitcoinPayment::pay(double amount) {
  std::cout << "Paid $" << amount << " using Bitcoin (Wallet: " << walletAddress << ")" << std::endl;
}
```
```cpp
// PaymentProcessor.h

#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H

#include "PaymentStrategy.h"

class PaymentProcessor {
private:
  PaymentStrategy* paymentStrategy;

public:
  PaymentProcessor();
  ~PaymentProcessor();
  void setPaymentStrategy(PaymentStrategy* strategy);
  void processPayment(double amount);
};

#endif // PAYMENTPROCESSOR_H
```
```cpp
// PaymentProcessor.cpp

#include "PaymentProcessor.h"
#include <iostream>

PaymentProcessor::PaymentProcessor() : paymentStrategy(nullptr) {}

PaymentProcessor::~PaymentProcessor() {
  delete paymentStrategy;
}

void PaymentProcessor::setPaymentStrategy(PaymentStrategy* strategy) {
  delete paymentStrategy;
  paymentStrategy = strategy;
}

void PaymentProcessor::processPayment(double amount) {
  if (paymentStrategy == nullptr) {
    std::cout << "No payment strategy selected." << std::endl;
    return;
  }
  paymentStrategy->pay(amount);
}
```
```cpp
// Main.cpp

#include "PaymentProcessor.h"
#include "CreditCardPayment.h"
#include "PayPalPayment.h"
#include "BitcoinPayment.h"

int main() {
  PaymentProcessor processor;

  processor.setPaymentStrategy(new CreditCardPayment("1234-5678-9876-5432"));
  processor.processPayment(100.0);

  processor.setPaymentStrategy(new PayPalPayment("user@example.com"));
  processor.processPayment(50.0);

  processor.setPaymentStrategy(new BitcoinPayment("1A2b3C4d5E6f7G8h9I"));
  processor.processPayment(200.0);

  return 0;
}
```

### **Python Implementation**
```python
# payment_strategy.py

from abc import ABC, abstractmethod

class PaymentStrategy(ABC):
  @abstractmethod
  def pay(self, amount):
    pass
```
```python
# credit_card_payment.py

from payment_strategy import PaymentStrategy

class CreditCardPayment(PaymentStrategy):
  def __init__(self, card_number):
    self.card_number = card_number

  def pay(self, amount):
    print(f"Paid ${amount} using Credit Card (Card Number: {self.card_number})")
```
```python
# paypal_payment.py

from payment_strategy import PaymentStrategy

class PayPalPayment(PaymentStrategy):
  def __init__(self, email):
    self.email = email

  def pay(self, amount):
    print(f"Paid ${amount} using PayPal (Email: {self.email})")
```
```python
# bitcoin_payment.py

from payment_strategy import PaymentStrategy

class BitcoinPayment(PaymentStrategy):
  def __init__(self, wallet_address):
    self.wallet_address = wallet_address

  def pay(self, amount):
    print(f"Paid ${amount} using Bitcoin (Wallet: {self.wallet_address})")
```
```python
# payment_processor.py

class PaymentProcessor:
  def __init__(self):
    self._payment_strategy = None

  def set_payment_strategy(self, payment_strategy):
    self._payment_strategy = payment_strategy

  def process_payment(self, amount):
    if self._payment_strategy is None:
      print("No payment strategy selected.")
      return
    self._payment_strategy.pay(amount)
```
```python
# main.py

from payment_processor import PaymentProcessor
from credit_card_payment import CreditCardPayment
from paypal_payment import PayPalPayment
from bitcoin_payment import BitcoinPayment

if __name__ == "__main__":
  processor = PaymentProcessor()

  processor.set_payment_strategy(CreditCardPayment("1234-5678-9876-5432"))
  processor.process_payment(100.0)

  processor.set_payment_strategy(PayPalPayment("user@example.com"))
  processor.process_payment(50.0)

  processor.set_payment_strategy(BitcoinPayment("1A2b3C4d5E6f7G8h9I"))
  processor.process_payment(200.0)
```

### **JavaScript Implementation**
```javascript
// paymentStrategy.js

class PaymentStrategy {
  pay(amount) {
    throw new Error("Method 'pay()' must be implemented.");
  }
}

module.exports = PaymentStrategy;
```
```javascript
// creditCardPayment.js

const PaymentStrategy = require("./paymentStrategy");

class CreditCardPayment extends PaymentStrategy {
  constructor(cardNumber) {
    super();
    this.cardNumber = cardNumber;
  }

  pay(amount) {
    console.log(`Paid $${amount} using Credit Card (Card Number: ${this.cardNumber})`);
  }
}

module.exports = CreditCardPayment;
```
```javascript
// payPalPayment.js

const PaymentStrategy = require("./paymentStrategy");

class PayPalPayment extends PaymentStrategy {
  constructor(email) {
    super();
    this.email = email;
  }

  pay(amount) {
    console.log(`Paid $${amount} using PayPal (Email: ${this.email})`);
  }
}

module.exports = PayPalPayment;
```
```javascript
// bitcoinPayment.js

const PaymentStrategy = require("./paymentStrategy");

class BitcoinPayment extends PaymentStrategy {
  constructor(walletAddress) {
    super();
    this.walletAddress = walletAddress;
  }

  pay(amount) {
    console.log(`Paid $${amount} using Bitcoin (Wallet: ${this.walletAddress})`);
  }
}

module.exports = BitcoinPayment;
```
```javascript
// paymentProcessor.js

class PaymentProcessor {
  constructor() {
    this.paymentStrategy = null;
  }

  setPaymentStrategy(paymentStrategy) {
    this.paymentStrategy = paymentStrategy;
  }

  processPayment(amount) {
    if (!this.paymentStrategy) {
      console.log("No payment strategy selected.");
      return;
    }
    this.paymentStrategy.pay(amount);
  }
}

module.exports = PaymentProcessor;
```
```javascript
// main.js

const PaymentProcessor = require("./paymentProcessor");
const CreditCardPayment = require("./creditCardPayment");
const PayPalPayment = require("./payPalPayment");
const BitcoinPayment = require("./bitcoinPayment");

const processor = new PaymentProcessor();

processor.setPaymentStrategy(new CreditCardPayment("1234-5678-9876-5432"));
processor.processPayment(100.0);

processor.setPaymentStrategy(new PayPalPayment("user@example.com"));
processor.processPayment(50.0);

processor.setPaymentStrategy(new BitcoinPayment("1A2b3C4d5E6f7G8h9I"));
processor.processPayment(200.0);
```

## 📌 Running the Code
To test the **Strategy pattern**, run the following commands:

### Java
```sh
cd Behavioral/Strategy/Java
javac *.java
java Main
```

### C#
```sh
cd Behavioral/Strategy/CSharp
dotnet build
dotnet run
```

### C++
```sh
cd Behavioral/Strategy/Cpp
g++ *.cpp -o strategy
./strategy
```

### Python
```sh
cd Behavioral/Strategy/Python
python3 main.py
```

### JavaScript
```sh
cd Behavioral/Strategy/JavaScript
node main.js
```

## 📌 Expected Output
```
Paid $100.0 using Credit Card (Card Number: 1234-5678-9876-5432)
Paid $50.0 using PayPal (Email: user@example.com)
Paid $200.0 using Bitcoin (Wallet: 1A2b3C4d5E6f7G8h9I)
```

## 📌 Summary
- Encapsulates multiple algorithms (payment methods) in separate classes.
- Removes conditional logic by using polymorphism.
- Allows dynamic selection of payment strategies at runtime.