// SongIterator.cpp

#include "SongIterator.h"

SongIterator::SongIterator(const std::vector<Song>& songs) : songs(songs) {}

bool SongIterator::hasNext() {
  return position < songs.size();
}

Song SongIterator::next() {
  return hasNext() ? songs[position++] : Song("", "");
}
