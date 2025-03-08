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
