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
