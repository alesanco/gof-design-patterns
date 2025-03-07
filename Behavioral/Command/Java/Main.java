// Main.java

public class Main {
  public static void main(String[] args) {
    Light light = new Light();
    Command turnOn = new TurnOnCommand(light);
    Command turnOff = new TurnOffCommand(light);

    RemoteControl remote = new RemoteControl();

    remote.setCommand(turnOn);
    remote.pressButton(); // The light is ON.

    remote.setCommand(turnOff);
    remote.pressButton(); // The light is OFF.
  }
}
