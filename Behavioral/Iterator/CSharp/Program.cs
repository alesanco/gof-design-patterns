// Program.cs

using System;

class Program {
  static void Main() {
    SongCollection playlist = new SongCollection();
    playlist.AddSong(new Song("Bohemian Rhapsody", "Queen"));
    playlist.AddSong(new Song("Imagine", "John Lennon"));
    playlist.AddSong(new Song("Hotel California", "Eagles"));

    IIterator<Song> iterator = playlist.GetIterator();
    while (iterator.HasNext()) {
      Console.WriteLine(iterator.Next());
    }
  }
}
