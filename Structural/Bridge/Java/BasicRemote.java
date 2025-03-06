// BasicRemote.java

public class BasicRemote extends Remote {
  public BasicRemote(Device device) {
    super(device);
  }

  @Override
  public void volumeUp() {
    device.setVolume(device.getVolume() + 10);
  }

  @Override
  public void volumeDown() {
    device.setVolume(device.getVolume() - 10);
  }
}
