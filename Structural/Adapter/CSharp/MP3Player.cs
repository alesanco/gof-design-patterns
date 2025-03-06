// MP3Player.cs
using System;

public class MP3Player : IMediaPlayer {
  private MediaAdapter? mediaAdapter;

  public void Play(string audioType, string fileName) {
    if (audioType.Equals("MP3", StringComparison.OrdinalIgnoreCase)) {
      Console.WriteLine("Playing MP3 file: " + fileName);
    } else if (audioType.Equals("MP4", StringComparison.OrdinalIgnoreCase) || 
              audioType.Equals("VLC", StringComparison.OrdinalIgnoreCase)) {
      mediaAdapter = new MediaAdapter(audioType);
      mediaAdapter.Play(audioType, fileName);
    } else {
      Console.WriteLine("Invalid media type: " + audioType);
    }
  }
}
