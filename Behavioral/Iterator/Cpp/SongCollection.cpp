// SongCollection.cpp

#include "SongCollection.h"

void SongCollection::addSong(const Song& song) {
  songs.push_back(song);
}

SongIterator SongCollection::getIterator() {
  return SongIterator(songs);
}
