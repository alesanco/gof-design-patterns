// VideoProxy.cs

using System;
using System.Collections.Generic;

public class VideoProxy : IVideoService {
  private readonly RealVideoService realVideoService = new RealVideoService();
  private readonly Dictionary<string, string> cache = new Dictionary<string, string>();

  public void LoadVideo(string videoName) {
    if (cache.ContainsKey(videoName)) {
      Console.WriteLine($"Retrieving cached video: {videoName}");
      Console.WriteLine($"Playing video: {videoName}");
    } else {
      realVideoService.LoadVideo(videoName);
      cache[videoName] = "Cached";
    }
  }
}
