// Remote.java

public abstract class Remote {
  protected Device device;

  public Remote(Device device) {
    this.device = device;
  }

  public void togglePower() {
    if (device.isOn()) {
      device.turnOff();
    } else {
      device.turnOn();
    }
  }

  public abstract void volumeUp();
  public abstract void volumeDown();
}
