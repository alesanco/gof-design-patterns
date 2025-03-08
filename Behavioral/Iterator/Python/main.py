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
