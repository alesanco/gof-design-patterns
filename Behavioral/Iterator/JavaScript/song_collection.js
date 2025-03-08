// song_collection.js

const SongIterator = require("./song_iterator");

class SongCollection {
  constructor() {
    this.songs = [];
  }

  addSong(song) {
    this.songs.push(song);
  }

  getIterator() {
    return new SongIterator(this.songs);
  }
}

module.exports = SongCollection;
