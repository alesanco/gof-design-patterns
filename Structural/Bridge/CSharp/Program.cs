// Program.cs

using System;

class Program {
  static void Main() {
    IDevice tv = new TV();
    IRemote basicRemote = new BasicRemote(tv);

    basicRemote.TogglePower();
    basicRemote.VolumeUp();
    basicRemote.VolumeDown();

    IDevice radio = new Radio();
    AdvancedRemote advancedRemote = new AdvancedRemote(radio);

    advancedRemote.TogglePower();
    advancedRemote.VolumeUp();
    advancedRemote.Mute();
  }
}
