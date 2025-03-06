// Main.java
public class Main {
  public static void main(String[] args) {
    MediaPlayer player = new MP3Player();

    player.play("MP3", "song.mp3");
    player.play("MP4", "video.mp4");
    player.play("VLC", "movie.vlc");
    player.play("AVI", "unsupported.avi");
  }
}
