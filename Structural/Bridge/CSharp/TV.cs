// TV.cs

using System;

public class TV : IDevice {
  private bool isOn = false;
  private int volume = 50;

  public void TurnOn() {
    isOn = true;
    Console.WriteLine("TV is now ON.");
  }

  public void TurnOff() {
    isOn = false;
    Console.WriteLine("TV is now OFF.");
  }

  public void SetVolume(int volume) {
    this.volume = volume;
    Console.WriteLine($"TV volume set to {volume}");
  }

  public int GetVolume() {
    return volume;
  }

  public bool IsOn() {
    return isOn;
  }
}
