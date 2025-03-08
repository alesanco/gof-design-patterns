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
