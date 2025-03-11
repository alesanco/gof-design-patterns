# Adapter Pattern

## 📌 What is the Adapter Pattern?
The **Adapter pattern** is a **structural design pattern** used to allow **incompatible interfaces to work together**. It acts as a **bridge** between two existing components, converting one interface into another that the client expects.

## 📌 When to Use Adapter
Use the **Adapter pattern** when:

- You need to **reuse an existing class** that has an **incompatible interface**.
- You want to **convert the interface of an existing class** into one that the client expects.
- You need to **allow an existing class to work with other classes without modifying its source code**.

## 📌 Example: Media Player Adapter
Imagine we have a **Media Player** that only supports **MP3 files**, but we need it to also play **MP4 and VLC files**. Instead of modifying the existing player, we use an **Adapter** that allows it to support new formats.

### 📌 Implementation in Different Languages
Each language implements the **Adapter pattern** differently based on its capabilities.

#### **Java Implementation**
```java
// MediaPlayer.java
public interface MediaPlayer {
  void play(String audioType, String fileName);
}
```
```java
// AdvancedMediaPlayer.java
public interface AdvancedMediaPlayer {
  void playMP4(String fileName);
  void playVLC(String fileName);
}
```
```java
public class MP4Player implements AdvancedMediaPlayer {
  @Override
  public void playMP4(String fileName) {
    System.out.println("Playing MP4 file: " + fileName);
  }

  @Override
  public void playVLC(String fileName) {
    // Do nothing, MP4Player does not support VLC
  }
}
```
```java
// VLCPlayer.java
public class VLCPlayer implements AdvancedMediaPlayer {
  @Override
  public void playMP4(String fileName) {
    // Do nothing, VLCPlayer does not support MP4
  }

  @Override
  public void playVLC(String fileName) {
    System.out.println("Playing VLC file: " + fileName);
  }
}
```
```java
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
```
```java
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
```
```java
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
```

#### **C# Implementation**
```csharp
// IMediaPlayer.cs
public interface IMediaPlayer {
  void Play(string audioType, string fileName);
}
```
```csharp
// IMediaPlayer.cs
public interface IMediaPlayer {
  void Play(string audioType, string fileName);
}
```
```csharp
// MP4Player.cs
using System;

public class MP4Player : IAdvancedMediaPlayer {
  public void PlayMP4(string fileName) {
    Console.WriteLine("Playing MP4 file: " + fileName);
  }

  public void PlayVLC(string fileName) {
    // Do nothing, MP4Player does not support VLC
  }
}
```
```csharp
// VLCPlayer.cs
using System;

public class VLCPlayer : IAdvancedMediaPlayer {
  public void PlayMP4(string fileName) {
    // Do nothing, VLCPlayer does not support MP4
  }

  public void PlayVLC(string fileName) {
    Console.WriteLine("Playing VLC file: " + fileName);
  }
}
```
```csharp
// MediaAdapter.cs
using System;

public class MediaAdapter : IMediaPlayer {
  private readonly IAdvancedMediaPlayer advancedMediaPlayer;

  public MediaAdapter(string audioType) {
    if (audioType.Equals("MP4", StringComparison.OrdinalIgnoreCase)) {
      advancedMediaPlayer = new MP4Player();
    } else if (audioType.Equals("VLC", StringComparison.OrdinalIgnoreCase)) {
      advancedMediaPlayer = new VLCPlayer();
    } else {
      throw new ArgumentException("Unsupported media type: " + audioType);
    }
  }

  public void Play(string audioType, string fileName) {
    if (audioType.Equals("MP4", StringComparison.OrdinalIgnoreCase)) {
      advancedMediaPlayer.PlayMP4(fileName);
    } else if (audioType.Equals("VLC", StringComparison.OrdinalIgnoreCase)) {
      advancedMediaPlayer.PlayVLC(fileName);
    }
  }
}
```
```csharp
// MP3Player.cs
using System;

public class MP3Player : IMediaPlayer {
  private MediaAdapter? mediaAdapter;

  public void Play(string audioType, string fileName) {
    if (audioType.Equals("MP3", StringComparison.OrdinalIgnoreCase)) {
      Console.WriteLine("Playing MP3 file: " + fileName);
    } else if (audioType.Equals("MP4", StringComparison.OrdinalIgnoreCase) || 
              audioType.Equals("VLC", StringComparison.OrdinalIgnoreCase)) {
      mediaAdapter = new MediaAdapter(audioType);
      mediaAdapter.Play(audioType, fileName);
    } else {
      Console.WriteLine("Invalid media type: " + audioType);
    }
  }
}
```
```csharp
// Program.cs
using System;

class Program {
  static void Main() {
    IMediaPlayer player = new MP3Player();

    player.Play("MP3", "song.mp3");
    player.Play("MP4", "video.mp4");
    player.Play("VLC", "movie.vlc");
    player.Play("AVI", "unsupported.avi");
  }
}
```

#### **C++ Implementation**
```cpp
// IMediaPlayer.h
#ifndef IMEDIAPLAYER_H
#define IMEDIAPLAYER_H

#include <string>

class IMediaPlayer {
public:
  virtual ~IMediaPlayer() = default;
  virtual void play(const std::string& audioType, const std::string& fileName) = 0;
};

#endif // IMEDIAPLAYER_H
```
```cpp
// IAdvancedMediaPlayer.h
#ifndef IADVANCEDMEDIAPLAYER_H
#define IADVANCEDMEDIAPLAYER_H

#include <string>

class IAdvancedMediaPlayer {
public:
  virtual ~IAdvancedMediaPlayer() = default;
  virtual void playMP4(const std::string& fileName) = 0;
  virtual void playVLC(const std::string& fileName) = 0;
};

#endif // IADVANCEDMEDIAPLAYER_H
```
```cpp
// MP4Player.h
#ifndef MP4PLAYER_H
#define MP4PLAYER_H

#include "IAdvancedMediaPlayer.h"
#include <iostream>

class MP4Player : public IAdvancedMediaPlayer {
public:
  void playMP4(const std::string& fileName) override;
  void playVLC(const std::string& fileName) override {}
};

#endif // MP4PLAYER_H
```
```cpp
// MP4Player.cpp
#include "MP4Player.h"

void MP4Player::playMP4(const std::string& fileName) {
  std::cout << "Playing MP4 file: " << fileName << std::endl;
}
```
```cpp
// VLCPlayer.h
#ifndef VLCPLAYER_H
#define VLCPLAYER_H

#include "IAdvancedMediaPlayer.h"
#include <iostream>

class VLCPlayer : public IAdvancedMediaPlayer {
public:
  void playMP4(const std::string& fileName) override {}
  void playVLC(const std::string& fileName) override;
};

#endif // VLCPLAYER_H
```
```cpp
// VLCPlayer.cpp
#include "VLCPlayer.h"

void VLCPlayer::playVLC(const std::string& fileName) {
  std::cout << "Playing VLC file: " << fileName << std::endl;
}
```
```cpp
// MediaAdapter.h
#ifndef MEDIAADAPTER_H
#define MEDIAADAPTER_H

#include "IMediaPlayer.h"
#include "IAdvancedMediaPlayer.h"
#include "MP4Player.h"
#include "VLCPlayer.h"
#include <memory>

class MediaAdapter : public IMediaPlayer {
private:
  std::unique_ptr<IAdvancedMediaPlayer> advancedMediaPlayer;

public:
  MediaAdapter(const std::string& audioType);
  void play(const std::string& audioType, const std::string& fileName) override;
};

#endif // MEDIAADAPTER_H
```
```cpp
// MediaAdapter.cpp
#include "MediaAdapter.h"

MediaAdapter::MediaAdapter(const std::string& audioType) {
  if (audioType == "MP4") {
    advancedMediaPlayer = std::make_unique<MP4Player>();
  } else if (audioType == "VLC") {
    advancedMediaPlayer = std::make_unique<VLCPlayer>();
  }
}

void MediaAdapter::play(const std::string& audioType, const std::string& fileName) {
  if (audioType == "MP4") {
    advancedMediaPlayer->playMP4(fileName);
  } else if (audioType == "VLC") {
    advancedMediaPlayer->playVLC(fileName);
  }
}
```
```cpp
// MP3Player.h
#ifndef MP3PLAYER_H
#define MP3PLAYER_H

#include "IMediaPlayer.h"
#include "MediaAdapter.h"
#include <iostream>
#include <memory>

class MP3Player : public IMediaPlayer {
private:
  std::unique_ptr<MediaAdapter> mediaAdapter;

public:
  void play(const std::string& audioType, const std::string& fileName) override;
};

#endif // MP3PLAYER_H
```
```cpp
// MP3Player.cpp
#include "MP3Player.h"

void MP3Player::play(const std::string& audioType, const std::string& fileName) {
  if (audioType == "MP3") {
    std::cout << "Playing MP3 file: " << fileName << std::endl;
  } else if (audioType == "MP4" || audioType == "VLC") {
    mediaAdapter = std::make_unique<MediaAdapter>(audioType);
    mediaAdapter->play(audioType, fileName);
  } else {
    std::cout << "Invalid media type: " << audioType << std::endl;
  }
}
```
```cpp
// Main.cpp
#include "MP3Player.h"

int main() {
  MP3Player player;

  player.play("MP3", "song.mp3");
  player.play("MP4", "video.mp4");
  player.play("VLC", "movie.vlc");
  player.play("AVI", "unsupported.avi");

  return 0;
}
```

#### **Python Implementation**
```python
# media_player.py
from abc import ABC, abstractmethod

class MediaPlayer(ABC):
  @abstractmethod
  def play(self, audio_type: str, file_name: str):
    pass
```
```python
# advanced_media_player.py
from abc import ABC, abstractmethod

class AdvancedMediaPlayer(ABC):
  @abstractmethod
  def play_mp4(self, file_name: str):
    pass

  @abstractmethod
  def play_vlc(self, file_name: str):
    pass
```
```python
# mp4_player.py
from advanced_media_player import AdvancedMediaPlayer

class MP4Player(AdvancedMediaPlayer):
  def play_mp4(self, file_name: str):
    print(f"Playing MP4 file: {file_name}")

  def play_vlc(self, file_name: str):
    pass  # MP4Player does not support VLC
```
```python
# vlc_player.py
from advanced_media_player import AdvancedMediaPlayer

class VLCPlayer(AdvancedMediaPlayer):
  def play_mp4(self, file_name: str):
    pass  # VLCPlayer does not support MP4

  def play_vlc(self, file_name: str):
    print(f"Playing VLC file: {file_name}")
```
```python
# media_adapter.py
from media_player import MediaPlayer
from mp4_player import MP4Player
from vlc_player import VLCPlayer

class MediaAdapter(MediaPlayer):
  def __init__(self, audio_type: str):
    if audio_type.lower() == "mp4":
      self.advanced_media_player = MP4Player()
    elif audio_type.lower() == "vlc":
      self.advanced_media_player = VLCPlayer()
    else:
      self.advanced_media_player = None

  def play(self, audio_type: str, file_name: str):
    if self.advanced_media_player:
      if audio_type.lower() == "mp4":
        self.advanced_media_player.play_mp4(file_name)
      elif audio_type.lower() == "vlc":
        self.advanced_media_player.play_vlc(file_name)
```
```python
# mp3_player.py
from media_player import MediaPlayer
from media_adapter import MediaAdapter

class MP3Player(MediaPlayer):
  def play(self, audio_type: str, file_name: str):
    if audio_type.lower() == "mp3":
      print(f"Playing MP3 file: {file_name}")
    elif audio_type.lower() in ["mp4", "vlc"]:
      adapter = MediaAdapter(audio_type)
      adapter.play(audio_type, file_name)
    else:
      print(f"Invalid media type: {audio_type}")
```
```python
# main.py
from mp3_player import MP3Player

if __name__ == "__main__":
  player = MP3Player()

  player.play("MP3", "song.mp3")
  player.play("MP4", "video.mp4")
  player.play("VLC", "movie.vlc")
  player.play("AVI", "unsupported.avi")
```

#### **JavaScript Implementation**
```javascript
// mediaPlayer.js
class MediaPlayer {
  play(audioType, fileName) {
    throw new Error("Method 'play' must be implemented.");
  }
}

module.exports = MediaPlayer;
```
```javascript
// advancedMediaPlayer.js
class AdvancedMediaPlayer {
  playMP4(fileName) {
    throw new Error("Method 'playMP4' must be implemented.");
  }

  playVLC(fileName) {
    throw new Error("Method 'playVLC' must be implemented.");
  }
}

module.exports = AdvancedMediaPlayer;
```
```javascript
// mp4Player.js
const AdvancedMediaPlayer = require("./advancedMediaPlayer");

class MP4Player extends AdvancedMediaPlayer {
  playMP4(fileName) {
    console.log(`Playing MP4 file: ${fileName}`);
  }

  playVLC(fileName) {
    // MP4Player does not support VLC
  }
}

module.exports = MP4Player;
```
```javascript
// vlcPlayer.js
const AdvancedMediaPlayer = require("./advancedMediaPlayer");

class VLCPlayer extends AdvancedMediaPlayer {
  playMP4(fileName) {
    // VLCPlayer does not support MP4
  }

  playVLC(fileName) {
    console.log(`Playing VLC file: ${fileName}`);
  }
}

module.exports = VLCPlayer;
```
```javascript
// mediaAdapter.js
const MediaPlayer = require("./mediaPlayer");
const MP4Player = require("./mp4Player");
const VLCPlayer = require("./vlcPlayer");

class MediaAdapter extends MediaPlayer {
  constructor(audioType) {
    super();
    if (audioType.toLowerCase() === "mp4") {
      this.advancedMediaPlayer = new MP4Player();
    } else if (audioType.toLowerCase() === "vlc") {
      this.advancedMediaPlayer = new VLCPlayer();
    } else {
      this.advancedMediaPlayer = null;
    }
  }

  play(audioType, fileName) {
    if (this.advancedMediaPlayer) {
      if (audioType.toLowerCase() === "mp4") {
        this.advancedMediaPlayer.playMP4(fileName);
      } else if (audioType.toLowerCase() === "vlc") {
        this.advancedMediaPlayer.playVLC(fileName);
      }
    }
  }
}

module.exports = MediaAdapter;
```
```javascript
// mp3Player.js
const MediaPlayer = require("./mediaPlayer");
const MediaAdapter = require("./mediaAdapter");

class MP3Player extends MediaPlayer {
  play(audioType, fileName) {
    if (audioType.toLowerCase() === "mp3") {
      console.log(`Playing MP3 file: ${fileName}`);
    } else if (audioType.toLowerCase() === "mp4" || audioType.toLowerCase() === "vlc") {
      const adapter = new MediaAdapter(audioType);
      adapter.play(audioType, fileName);
    } else {
      console.log(`Invalid media type: ${audioType}`);
    }
  }
}

module.exports = MP3Player;
```
```javascript
// main.js
const MP3Player = require("./mp3Player");

const player = new MP3Player();

player.play("MP3", "song.mp3");
player.play("MP4", "video.mp4");
player.play("VLC", "movie.vlc");
player.play("AVI", "unsupported.avi");
```

### 📌 Running the Code
To test the **Adapter pattern**, run the following commands:

#### **Java**
```sh
cd Structural/Adapter/Java
javac *.java
java Main
```

#### **C#**
```sh
cd Structural/Adapter/CSharp
dotnet build
dotnet run
```

#### **C++**
```sh
cd Structural/Adapter/Cpp
g++ *.cpp -o adapter
./adapter
```

#### **Python**
```sh
cd Structural/Adapter/Python
python3 main.py
```

#### **JavaScript**
```sh
cd Structural/Adapter/JavaScript
node main.js
```

### 📌 Expected Output
```
Playing MP3 file: song.mp3
Playing MP4 file: video.mp4
Playing VLC file: movie.vlc
Invalid media type: AVI
```

## 📌 Summary
- Adapter pattern allows incompatible interfaces to work together.
- Avoids modifying existing code by introducing an adapter.
- Improves code reusability and follows Open/Closed Principle.