// Projector.cs

using System;

public class Projector {
  public void TurnOn() {
    Console.WriteLine("Projector is ON.");
  }

  public void TurnOff() {
    Console.WriteLine("Projector is OFF.");
  }

  public void SetInput(string input) {
    Console.WriteLine($"Projector input set to: {input}");
  }
}
