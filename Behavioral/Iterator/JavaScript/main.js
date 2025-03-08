// main.js

const SongCollection = require("./song_collection");
const Song = require("./song");

const playlist = new SongCollection();
playlist.addSong(new Song("Bohemian Rhapsody", "Queen"));
playlist.addSong(new Song("Imagine", "John Lennon"));
playlist.addSong(new Song("Hotel California", "Eagles"));

const iterator = playlist.getIterator();
while (iterator.hasNext()) {
  console.log(iterator.next().toString());
}
