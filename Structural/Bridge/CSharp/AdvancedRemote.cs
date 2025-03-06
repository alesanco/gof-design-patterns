// AdvancedRemote.cs

using System;

public class AdvancedRemote : BasicRemote {
  public AdvancedRemote(IDevice device) : base(device) {}

  public void Mute() {
    device.SetVolume(0);
    Console.WriteLine("Device is muted.");
  }
}
