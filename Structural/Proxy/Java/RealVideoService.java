// RealVideoService.java

public class RealVideoService implements VideoService {
  @Override
  public void loadVideo(String videoName) {
    System.out.println("Loading video: " + videoName);
    try {
      Thread.sleep(2000); // Simulating video loading delay
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    System.out.println("Playing video: " + videoName);
  }
}
