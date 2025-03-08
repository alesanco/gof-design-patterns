// SongCollection.java

import java.util.ArrayList;
import java.util.List;

public class SongCollection {
  private List<Song> songs = new ArrayList<>();

  public void addSong(Song song) {
    songs.add(song);
  }

  public Iterator<Song> iterator() {
    return new SongIterator(songs);
  }
}
