// Program.cs

using System;

class Program {
  static void Main() {
    Light light = new Light();
    ICommand turnOn = new TurnOnCommand(light);
    ICommand turnOff = new TurnOffCommand(light);

    RemoteControl remote = new RemoteControl();

    remote.SetCommand(turnOn);
    remote.PressButton(); // The light is ON.

    remote.SetCommand(turnOff);
    remote.PressButton(); // The light is OFF.
  }
}
