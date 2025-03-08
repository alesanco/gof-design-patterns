// SongIterator.cs

using System.Collections.Generic;

public class SongIterator : IIterator<Song> {
  private readonly List<Song> _songs;
  private int _position = 0;

  public SongIterator(List<Song> songs) {
    _songs = songs;
  }

  public bool HasNext() {
    return _position < _songs.Count;
  }

  public Song? Next() {
    return HasNext() ? _songs[_position++] : null;
  }
}
