// Main.java

public class Main {
  public static void main(String[] args) {
    VideoService proxy = new VideoProxy();

    proxy.loadVideo("movie1.mp4"); // First-time loading
    proxy.loadVideo("movie2.mp4"); // First-time loading
    proxy.loadVideo("movie1.mp4"); // Retrieved from cache
  }
}
