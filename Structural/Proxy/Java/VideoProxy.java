// VideoProxy.java

import java.util.HashMap;
import java.util.Map;

public class VideoProxy implements VideoService {
  private final RealVideoService realVideoService = new RealVideoService();
  private final Map<String, String> cache = new HashMap<>();

  @Override
  public void loadVideo(String videoName) {
    if (cache.containsKey(videoName)) {
      System.out.println("Retrieving cached video: " + videoName);
      System.out.println("Playing video: " + videoName);
    } else {
      realVideoService.loadVideo(videoName);
      cache.put(videoName, "Cached");
    }
  }
}
