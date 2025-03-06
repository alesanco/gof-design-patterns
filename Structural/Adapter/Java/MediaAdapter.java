// MediaAdapter.java
public class MediaAdapter implements MediaPlayer {
  private AdvancedMediaPlayer advancedMediaPlayer;

  public MediaAdapter(String audioType) {
    if (audioType.equalsIgnoreCase("MP4")) {
      advancedMediaPlayer = new MP4Player();
    } else if (audioType.equalsIgnoreCase("VLC")) {
      advancedMediaPlayer = new VLCPlayer();
    }
  }

  @Override
  public void play(String audioType, String fileName) {
    if (audioType.equalsIgnoreCase("MP4")) {
      advancedMediaPlayer.playMP4(fileName);
    } else if (audioType.equalsIgnoreCase("VLC")) {
      advancedMediaPlayer.playVLC(fileName);
    }
  }
}
