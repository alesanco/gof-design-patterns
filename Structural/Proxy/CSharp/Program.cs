// Program.cs

using System;

class Program {
  static void Main() {
    IVideoService proxy = new VideoProxy();

    proxy.LoadVideo("movie1.mp4"); // First-time loading
    proxy.LoadVideo("movie2.mp4"); // First-time loading
    proxy.LoadVideo("movie1.mp4"); // Retrieved from cache
  }
}
