// Main.java

public class Main {
  public static void main(String[] args) {
    SongCollection playlist = new SongCollection();
    playlist.addSong(new Song("Bohemian Rhapsody", "Queen"));
    playlist.addSong(new Song("Imagine", "John Lennon"));
    playlist.addSong(new Song("Hotel California", "Eagles"));

    Iterator<Song> iterator = playlist.iterator();
    while (iterator.hasNext()) {
      System.out.println(iterator.next());
    }
  }
}
