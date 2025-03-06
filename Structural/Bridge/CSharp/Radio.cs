// Radio.cs

using System;

public class Radio : IDevice {
  private bool isOn = false;
  private int volume = 30;

  public void TurnOn() {
    isOn = true;
    Console.WriteLine("Radio is now ON.");
  }

  public void TurnOff() {
    isOn = false;
    Console.WriteLine("Radio is now OFF.");
  }

  public void SetVolume(int volume) {
    this.volume = volume;
    Console.WriteLine($"Radio volume set to {volume}");
  }

  public int GetVolume() {
    return volume;
  }

  public bool IsOn() {
    return isOn;
  }
}
