// VLCPlayer.cs
using System;

public class VLCPlayer : IAdvancedMediaPlayer {
  public void PlayMP4(string fileName) {
    // Do nothing, VLCPlayer does not support MP4
  }

  public void PlayVLC(string fileName) {
    Console.WriteLine("Playing VLC file: " + fileName);
  }
}
