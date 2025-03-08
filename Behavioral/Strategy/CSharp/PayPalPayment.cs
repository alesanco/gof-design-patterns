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
