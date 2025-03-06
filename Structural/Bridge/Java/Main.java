// Main.java

public class Main {
  public static void main(String[] args) {
    Device tv = new TV();
    Remote basicRemote = new BasicRemote(tv);

    basicRemote.togglePower();
    basicRemote.volumeUp();
    basicRemote.volumeDown();

    Device radio = new Radio();
    AdvancedRemote advancedRemote = new AdvancedRemote(radio);

    advancedRemote.togglePower();
    advancedRemote.volumeUp();
    advancedRemote.mute();
  }
}
