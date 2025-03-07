// FlyweightCharacter.cs

using System;

public class FlyweightCharacter {
  private readonly char symbol;

  public FlyweightCharacter(char symbol) {
    this.symbol = symbol;
  }

  public void Display() {
    Console.WriteLine($"Character: {symbol}");
  }
}
