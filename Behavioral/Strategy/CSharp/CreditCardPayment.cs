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
