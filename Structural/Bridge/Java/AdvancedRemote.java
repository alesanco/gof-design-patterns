// AdvancedRemote.java

public class AdvancedRemote extends BasicRemote {
  public AdvancedRemote(Device device) {
    super(device);
  }

  public void mute() {
    device.setVolume(0);
    System.out.println("Device is muted.");
  }
}
