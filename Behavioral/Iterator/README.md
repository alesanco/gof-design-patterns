# Iterator Pattern

## 📌 What is the Iterator Pattern?
The **Iterator Pattern** is a behavioral design pattern that provides a way to access elements of a collection **sequentially without exposing its underlying structure**. It allows traversing collections **independently of their implementation**, promoting **encapsulation and separation of concerns**.

## 📌 When to Use Iterator
Use the **Iterator Iterator** when:
- When you need to **iterate through a collection** without exposing its internal representation.
- When a collection should provide **multiple ways to traverse** its elements.
- When you need a **uniform interface** for different types of collections.

## 📌 Example: Playlist Iterator
We implement a **music playlist system** where users can iterate over a collection of **songs** without directly accessing the internal list.

## 📌 Implementation in Different Languages
Each language implements the **Iterator pattern** differently based on its capabilities.

### **Java Implementation**
```java
// Iterator.java

public interface Iterator<T> {
  boolean hasNext();
  T next();
}
```
```java
// SongIterator.java

import java.util.List;

public class SongIterator implements Iterator<Song> {
  private List<Song> songs;
  private int position = 0;

  public SongIterator(List<Song> songs) {
    this.songs = songs;
  }

  @Override
  public boolean hasNext() {
    return position < songs.size();
  }

  @Override
  public Song next() {
    return hasNext() ? songs.get(position++) : null;
  }
}
```
```java
// SongCollection.java

import java.util.ArrayList;
import java.util.List;

public class SongCollection {
  private List<Song> songs = new ArrayList<>();

  public void addSong(Song song) {
    songs.add(song);
  }

  public Iterator<Song> iterator() {
    return new SongIterator(songs);
  }
}
```
```java
// Song.java

public class Song {
  private String title;
  private String artist;

  public Song(String title, String artist) {
    this.title = title;
    this.artist = artist;
  }

  @Override
  public String toString() {
    return "\"" + title + "\" by " + artist;
  }
}
```
```java
// Main.java

public class Main {
  public static void main(String[] args) {
    SongCollection playlist = new SongCollection();
    playlist.addSong(new Song("Bohemian Rhapsody", "Queen"));
    playlist.addSong(new Song("Imagine", "John Lennon"));
    playlist.addSong(new Song("Hotel California", "Eagles"));

    Iterator<Song> iterator = playlist.iterator();
    while (iterator.hasNext()) {
      System.out.println(iterator.next());
    }
  }
}
```

### **C# Implementation**
```csharp
// IIterator.cs

public interface IIterator<T> {
  bool HasNext();
  T? Next();
}
```
```csharp
// SongIterator.cs

using System.Collections.Generic;

public class SongIterator : IIterator<Song> {
  private readonly List<Song> _songs;
  private int _position = 0;

  public SongIterator(List<Song> songs) {
    _songs = songs;
  }

  public bool HasNext() {
    return _position < _songs.Count;
  }

  public Song? Next() {
    return HasNext() ? _songs[_position++] : null;
  }
}
```
```csharp
// SongCollection.cs

using System.Collections.Generic;

public class SongCollection {
  private readonly List<Song> _songs = new List<Song>();

  public void AddSong(Song song) {
    _songs.Add(song);
  }

  public IIterator<Song> GetIterator() {
    return new SongIterator(_songs);
  }
}
```
```csharp
// Song.cs

public class Song {
  public string Title { get; }
  public string Artist { get; }

  public Song(string title, string artist) {
    Title = title;
    Artist = artist;
  }

  public override string ToString() {
    return $"\"{Title}\" by {Artist}";
  }
}
```
```csharp
// Program.cs

using System;

class Program {
  static void Main() {
    SongCollection playlist = new SongCollection();
    playlist.AddSong(new Song("Bohemian Rhapsody", "Queen"));
    playlist.AddSong(new Song("Imagine", "John Lennon"));
    playlist.AddSong(new Song("Hotel California", "Eagles"));

    IIterator<Song> iterator = playlist.GetIterator();
    while (iterator.HasNext()) {
      Console.WriteLine(iterator.Next());
    }
  }
}
```

### **C++ Implementation**
```cpp
// Iterator.h

#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class Iterator {
public:
  virtual ~Iterator() = default;
  virtual bool hasNext() = 0;
  virtual T next() = 0;
};

#endif // ITERATOR_H
```
```cpp
// SongIterator.h

#ifndef SONG_ITERATOR_H
#define SONG_ITERATOR_H

#include "Iterator.h"
#include "Song.h"
#include <vector>

class SongIterator : public Iterator<Song> {
private:
  const std::vector<Song>& songs;
  size_t position = 0;

public:
  explicit SongIterator(const std::vector<Song>& songs);
  bool hasNext() override;
  Song next() override;
};

#endif // SONG_ITERATOR_H
```
```cpp
// SongIterator.cpp

#include "SongIterator.h"

SongIterator::SongIterator(const std::vector<Song>& songs) : songs(songs) {}

bool SongIterator::hasNext() {
  return position < songs.size();
}

Song SongIterator::next() {
  return hasNext() ? songs[position++] : Song("", "");
}
```
```cpp
// SongCollection.h

#ifndef SONG_COLLECTION_H
#define SONG_COLLECTION_H

#include "SongIterator.h"
#include <vector>

class SongCollection {
private:
  std::vector<Song> songs;

public:
  void addSong(const Song& song);
  SongIterator getIterator();
};

#endif // SONG_COLLECTION_H
```
```cpp
// SongCollection.cpp

#include "SongCollection.h"

void SongCollection::addSong(const Song& song) {
  songs.push_back(song);
}

SongIterator SongCollection::getIterator() {
  return SongIterator(songs);
}
```
```cpp
// Song.h

#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

class Song {
private:
  std::string title;
  std::string artist;

public:
  Song(std::string title, std::string artist);
  friend std::ostream& operator<<(std::ostream& os, const Song& song);
};

#endif // SONG_H
```
```cpp
// Song.cpp

#include "Song.h"

Song::Song(std::string title, std::string artist) : title(std::move(title)), artist(std::move(artist)) {}

std::ostream& operator<<(std::ostream& os, const Song& song) {
  os << "\"" << song.title << "\" by " << song.artist;
  return os;
}
```
```cpp
// Main.cpp

#include "SongCollection.h"
#include <iostream>

int main() {
  SongCollection playlist;
  playlist.addSong(Song("Bohemian Rhapsody", "Queen"));
  playlist.addSong(Song("Imagine", "John Lennon"));
  playlist.addSong(Song("Hotel California", "Eagles"));

  SongIterator iterator = playlist.getIterator();
  while (iterator.hasNext()) {
    std::cout << iterator.next() << std::endl;
  }

  return 0;
}
```

### **Python Implementation**
```python
# iterator.py

from abc import ABC, abstractmethod

class Iterator(ABC):
  @abstractmethod
  def has_next(self):
    pass

  @abstractmethod
  def next(self):
    pass
```
```python
# song_iterator.py

from iterator import Iterator

class SongIterator(Iterator):
  def __init__(self, songs):
    self._songs = songs
    self._position = 0

  def has_next(self):
    return self._position < len(self._songs)

  def next(self):
    if self.has_next():
      song = self._songs[self._position]
      self._position += 1
      return song
    return None
```
```python
# song_collection.py

from song_iterator import SongIterator

class SongCollection:
  def __init__(self):
    self._songs = []

  def add_song(self, song):
    self._songs.append(song)

  def get_iterator(self):
    return SongIterator(self._songs)
```
```python
# song.py

class Song:
  def __init__(self, title, artist):
    self.title = title
    self.artist = artist

  def __str__(self):
    return f'"{self.title}" by {self.artist}'
```
```python
# main.py

from song_collection import SongCollection
from song import Song

if __name__ == "__main__":
  playlist = SongCollection()
  playlist.add_song(Song("Bohemian Rhapsody", "Queen"))
  playlist.add_song(Song("Imagine", "John Lennon"))
  playlist.add_song(Song("Hotel California", "Eagles"))

  iterator = playlist.get_iterator()
  while iterator.has_next():
    print(iterator.next())
```

### **JavaScript Implementation**
```javascript
// iterator.js

class Iterator {
  hasNext() {
    throw new Error("hasNext() must be implemented by subclasses");
  }

  next() {
    throw new Error("next() must be implemented by subclasses");
  }
}

module.exports = Iterator;
```
```javascript
// song_iterator.js

const Iterator = require("./iterator");

class SongIterator extends Iterator {
  constructor(songs) {
    super();
    this.songs = songs;
    this.position = 0;
  }

  hasNext() {
    return this.position < this.songs.length;
  }

  next() {
    return this.hasNext() ? this.songs[this.position++] : null;
  }
}

module.exports = SongIterator;
```
```javascript
// song_collection.js

const SongIterator = require("./song_iterator");

class SongCollection {
  constructor() {
    this.songs = [];
  }

  addSong(song) {
    this.songs.push(song);
  }

  getIterator() {
    return new SongIterator(this.songs);
  }
}

module.exports = SongCollection;
```
```javascript
// song.js

class Song {
  constructor(title, artist) {
    this.title = title;
    this.artist = artist;
  }

  toString() {
    return `"${this.title}" by ${this.artist}`;
  }
}

module.exports = Song;
```
```javascript
// main.js

const SongCollection = require("./song_collection");
const Song = require("./song");

const playlist = new SongCollection();
playlist.addSong(new Song("Bohemian Rhapsody", "Queen"));
playlist.addSong(new Song("Imagine", "John Lennon"));
playlist.addSong(new Song("Hotel California", "Eagles"));

const iterator = playlist.getIterator();
while (iterator.hasNext()) {
  console.log(iterator.next().toString());
}
```

## 📌 Running the Code
To test the **Iterator pattern**, run the following commands:

### Java
```sh
cd Behavioral/Iterator/Java
javac *.java
java Main
```

### C#
```sh
cd Behavioral/Iterator/CSharp
dotnet build
dotnet run
```

### C++
```sh
cd Behavioral/Iterator/Cpp
g++ *.cpp -o iterator
./iterator
```

### Python
```sh
cd Behavioral/Iterator/Python
python3 main.py
```

### JavaScript
```sh
cd Behavioral/Iterator/JavaScript
node main.js
```

## 📌 Expected Output
```
"Bohemian Rhapsody" by Queen
"Imagine" by John Lennon
"Hotel California" by Eagles
```

## 📌 Summary
- Encapsulates iteration logic within a dedicated class.
- Separates traversal from collection structure, promoting maintainability.
- Supports various iteration strategies, such as reverse or filtered traversal.