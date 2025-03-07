// SoundSystem.cs

using System;

public class SoundSystem {
  public void TurnOn() {
    Console.WriteLine("Sound System is ON.");
  }

  public void TurnOff() {
    Console.WriteLine("Sound System is OFF.");
  }

  public void SetVolume(int level) {
    Console.WriteLine($"Sound System volume set to: {level}");
  }
}
