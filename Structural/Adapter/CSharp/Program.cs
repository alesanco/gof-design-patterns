// Program.cs
using System;

class Program {
  static void Main() {
    IMediaPlayer player = new MP3Player();

    player.Play("MP3", "song.mp3");
    player.Play("MP4", "video.mp4");
    player.Play("VLC", "movie.vlc");
    player.Play("AVI", "unsupported.avi");
  }
}
