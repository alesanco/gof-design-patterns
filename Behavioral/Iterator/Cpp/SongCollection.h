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
