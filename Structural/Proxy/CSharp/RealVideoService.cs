// RealVideoService.cs

using System;
using System.Threading;

public class RealVideoService : IVideoService {
  public void LoadVideo(string videoName) {
    Console.WriteLine($"Loading video: {videoName}");
    Thread.Sleep(2000); // Simulating video loading delay
    Console.WriteLine($"Playing video: {videoName}");
  }
}
