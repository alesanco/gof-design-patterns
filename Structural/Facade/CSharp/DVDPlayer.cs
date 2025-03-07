// DVDPlayer.cs

using System;

public class DVDPlayer {
  public void TurnOn() {
    Console.WriteLine("DVD Player is ON.");
  }

  public void TurnOff() {
    Console.WriteLine("DVD Player is OFF.");
  }

  public void Play(string movie) {
    Console.WriteLine($"Playing movie: {movie}");
  }
}
