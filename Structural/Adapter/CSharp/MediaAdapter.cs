// MediaAdapter.cs
using System;

public class MediaAdapter : IMediaPlayer {
  private readonly IAdvancedMediaPlayer advancedMediaPlayer;

  public MediaAdapter(string audioType) {
    if (audioType.Equals("MP4", StringComparison.OrdinalIgnoreCase)) {
      advancedMediaPlayer = new MP4Player();
    } else if (audioType.Equals("VLC", StringComparison.OrdinalIgnoreCase)) {
      advancedMediaPlayer = new VLCPlayer();
    } else {
      throw new ArgumentException("Unsupported media type: " + audioType);
    }
  }

  public void Play(string audioType, string fileName) {
    if (audioType.Equals("MP4", StringComparison.OrdinalIgnoreCase)) {
      advancedMediaPlayer.PlayMP4(fileName);
    } else if (audioType.Equals("VLC", StringComparison.OrdinalIgnoreCase)) {
      advancedMediaPlayer.PlayVLC(fileName);
    }
  }
}
