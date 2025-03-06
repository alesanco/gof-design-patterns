// MP3Player.java
public class MP3Player implements MediaPlayer {
  private MediaAdapter mediaAdapter;

  @Override
  public void play(String audioType, String fileName) {
    if (audioType.equalsIgnoreCase("MP3")) {
      System.out.println("Playing MP3 file: " + fileName);
    } else if (audioType.equalsIgnoreCase("MP4") || audioType.equalsIgnoreCase("VLC")) {
      mediaAdapter = new MediaAdapter(audioType);
      mediaAdapter.play(audioType, fileName);
    } else {
      System.out.println("Invalid media type: " + audioType);
    }
  }
}
