// BasicRemote.cs

public class BasicRemote : IRemote {
  protected IDevice device;

  public BasicRemote(IDevice device) {
    this.device = device;
  }

  public void TogglePower() {
    if (device.IsOn()) {
      device.TurnOff();
    } else {
      device.TurnOn();
    }
  }

  public void VolumeUp() {
    device.SetVolume(device.GetVolume() + 10);
  }

  public void VolumeDown() {
    device.SetVolume(device.GetVolume() - 10);
  }
}
