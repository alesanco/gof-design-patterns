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
