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
