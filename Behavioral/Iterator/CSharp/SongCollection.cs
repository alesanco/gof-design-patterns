// SongCollection.cs

using System.Collections.Generic;

public class SongCollection {
  private readonly List<Song> _songs = new List<Song>();

  public void AddSong(Song song) {
    _songs.Add(song);
  }

  public IIterator<Song> GetIterator() {
    return new SongIterator(_songs);
  }
}
