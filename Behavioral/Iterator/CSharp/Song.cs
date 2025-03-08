// Song.cs

public class Song {
  public string Title { get; }
  public string Artist { get; }

  public Song(string title, string artist) {
    Title = title;
    Artist = artist;
  }

  public override string ToString() {
    return $"\"{Title}\" by {Artist}";
  }
}
