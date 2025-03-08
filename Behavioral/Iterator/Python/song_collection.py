# song_collection.py

from song_iterator import SongIterator

class SongCollection:
  def __init__(self):
    self._songs = []

  def add_song(self, song):
    self._songs.append(song)

  def get_iterator(self):
    return SongIterator(self._songs)
