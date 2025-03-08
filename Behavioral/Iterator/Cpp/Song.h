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
