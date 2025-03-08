// Song.cpp

#include "Song.h"

Song::Song(std::string title, std::string artist) : title(std::move(title)), artist(std::move(artist)) {}

std::ostream& operator<<(std::ostream& os, const Song& song) {
  os << "\"" << song.title << "\" by " << song.artist;
  return os;
}
