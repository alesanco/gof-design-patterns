// MP4Player.cs
using System;

public class MP4Player : IAdvancedMediaPlayer {
  public void PlayMP4(string fileName) {
    Console.WriteLine("Playing MP4 file: " + fileName);
  }

  public void PlayVLC(string fileName) {
    // Do nothing, MP4Player does not support VLC
  }
}
