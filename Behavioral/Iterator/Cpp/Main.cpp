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
