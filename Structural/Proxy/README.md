# Proxy Pattern

## 📌 What is the Proxy Pattern?
The **Proxy Pattern** is a structural design pattern that **acts as an intermediary** between a client and an actual object. It controls access, enhances security, or optimizes performance by introducing an additional layer between the client and the real service.

## 📌 When to Use Proxy
Use the **Proxy pattern** when:

- You need to **control access** to an object.
- An object is **resource-intensive** and should be **loaded only when needed**.
- You want to **add logging, security checks, caching, or lazy initialization** before interacting with the real object.

## 📌 Example: Video Streaming Service
A **video streaming service** loads videos when requested. To optimize performance, a **proxy caches videos**, ensuring that previously loaded videos are retrieved instantly instead of reloading them.

## 📌 Implementation in Different Languages
Each language implements the **Proxy pattern** differently based on its capabilities.

### **Java Implementation**
```java
// VideoService.java

public interface VideoService {
  void loadVideo(String videoName);
}
```
```java
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
```
```java
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
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    VideoService proxy = new VideoProxy();

    proxy.loadVideo("movie1.mp4"); // First-time loading
    proxy.loadVideo("movie2.mp4"); // First-time loading
    proxy.loadVideo("movie1.mp4"); // Retrieved from cache
  }
}
```

### **C# Implementation**
```csharp
// IVideoService.cs

public interface IVideoService {
  void LoadVideo(string videoName);
}
```
```csharp
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
```
```csharp
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
```
```csharp
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
```

### **C++ Implementation**
```cpp
// IVideoService.h

#ifndef IVIDEOSERVICE_H
#define IVIDEOSERVICE_H

#include <string>

class IVideoService {
public:
  virtual void loadVideo(const std::string& videoName) = 0;
  virtual ~IVideoService() = default;
};

#endif // IVIDEOSERVICE_H
```
```cpp
// RealVideoService.h

#ifndef REALVIDEOSERVICE_H
#define REALVIDEOSERVICE_H

#include "IVideoService.h"
#include <iostream>
#include <thread>
#include <chrono>

class RealVideoService : public IVideoService {
public:
  void loadVideo(const std::string& videoName) override;
};

#endif // REALVIDEOSERVICE_H
```
```cpp
// RealVideoService.cpp

#include "RealVideoService.h"

void RealVideoService::loadVideo(const std::string& videoName) {
  std::cout << "Loading video: " << videoName << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulating video loading delay
  std::cout << "Playing video: " << videoName << std::endl;
}
```
```cpp
// VideoProxy.h

#ifndef VIDEOPROXY_H
#define VIDEOPROXY_H

#include "IVideoService.h"
#include "RealVideoService.h"
#include <unordered_map>

class VideoProxy : public IVideoService {
private:
  RealVideoService realVideoService;
  std::unordered_map<std::string, bool> cache;

public:
  void loadVideo(const std::string& videoName) override;
};

#endif // VIDEOPROXY_H
```
```cpp
// VideoProxy.cpp

#include "VideoProxy.h"
#include <iostream>

void VideoProxy::loadVideo(const std::string& videoName) {
  if (cache.find(videoName) != cache.end()) {
    std::cout << "Retrieving cached video: " << videoName << std::endl;
    std::cout << "Playing video: " << videoName << std::endl;
  } else {
    realVideoService.loadVideo(videoName);
    cache[videoName] = true;
  }
}
```
```cpp
// Main.cpp

#include "VideoProxy.h"

int main() {
  VideoProxy proxy;

  proxy.loadVideo("movie1.mp4"); // First-time loading
  proxy.loadVideo("movie2.mp4"); // First-time loading
  proxy.loadVideo("movie1.mp4"); // Retrieved from cache

  return 0;
}
```

### **Python Implementation**
```python
# video_service.py

from abc import ABC, abstractmethod

class VideoService(ABC):
  @abstractmethod
  def load_video(self, video_name: str):
    pass
```
```python
# real_video_service.py

import time
from video_service import VideoService

class RealVideoService(VideoService):
  def load_video(self, video_name: str):
    print(f"Loading video: {video_name}")
    time.sleep(2)  # Simulating video loading delay
    print(f"Playing video: {video_name}")
```
```python
# video_proxy.py

from video_service import VideoService
from real_video_service import RealVideoService

class VideoProxy(VideoService):
  def __init__(self):
    self._real_video_service = RealVideoService()
    self._cache = {}

  def load_video(self, video_name: str):
    if video_name in self._cache:
      print(f"Retrieving cached video: {video_name}")
      print(f"Playing video: {video_name}")
    else:
      self._real_video_service.load_video(video_name)
      self._cache[video_name] = True
```
```python
# main.py

from video_proxy import VideoProxy

if __name__ == "__main__":
  proxy = VideoProxy()

  proxy.load_video("movie1.mp4")  # First-time loading
  proxy.load_video("movie2.mp4")  # First-time loading
  proxy.load_video("movie1.mp4")  # Retrieved from cache
```

### **JavaScript Implementation**
```javascript
// videoService.js

class VideoService {
  loadVideo(videoName) {
    throw new Error("Method 'loadVideo(videoName)' must be implemented.");
  }
}

module.exports = VideoService;
```
```javascript
// realVideoService.js

const VideoService = require("./videoService");

class RealVideoService extends VideoService {
  async loadVideo(videoName) {
    console.log(`Loading video: ${videoName}`);
    await new Promise(resolve => setTimeout(resolve, 2000)); // Simulate delay
    console.log(`Playing video: ${videoName}`);
  }
}

module.exports = RealVideoService;
```
```javascript
// videoProxy.js

const VideoService = require("./videoService");
const RealVideoService = require("./realVideoService");

class VideoProxy extends VideoService {
  constructor() {
    super();
    this.realVideoService = new RealVideoService();
    this.cache = new Map();
  }

  async loadVideo(videoName) {
    if (this.cache.has(videoName)) {
      console.log(`Retrieving cached video: ${videoName}`);
      console.log(`Playing video: ${videoName}`);
    } else {
      await this.realVideoService.loadVideo(videoName);
      this.cache.set(videoName, true);
    }
  }
}

module.exports = VideoProxy;
```
```javascript
// main.js

const VideoProxy = require("./videoProxy");

async function main() {
  const proxy = new VideoProxy();

  await proxy.loadVideo("movie1.mp4"); // First-time loading
  await proxy.loadVideo("movie2.mp4"); // First-time loading
  await proxy.loadVideo("movie1.mp4"); // Retrieved from cache
}

main();
```

## 📌 Running the Code
To test the **Proxy pattern**, run the following commands:

### **Java**
```sh
cd Structural/Proxy/Java
javac *.java
java Main
```

### **C#**
```sh
cd Structural/Proxy/CSharp
dotnet build
dotnet run
```

### **C++**
```sh
cd Structural/Proxy/Cpp
g++ *.cpp -o proxy -pthread
./proxy
```

### **Python**
```sh
cd Structural/Proxy/Python
python3 main.py
```

### **JavaScript**
```sh
cd Structural/Proxy/JavaScript
node main.js
```

## 📌 Expected Output
```
Loading video: movie1.mp4
Playing video: movie1.mp4
Loading video: movie2.mp4
Playing video: movie2.mp4
Retrieving cached video: movie1.mp4
Playing video: movie1.mp4
```

## 📌 Summary
- Controls access to an object, adding caching, logging, or security.
- Optimizes performance by delaying expensive operations until necessary.
- Provides a surrogate for complex or resource-heavy objects.