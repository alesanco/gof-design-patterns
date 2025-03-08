// song_iterator.js

const Iterator = require("./iterator");

class SongIterator extends Iterator {
  constructor(songs) {
    super();
    this.songs = songs;
    this.position = 0;
  }

  hasNext() {
    return this.position < this.songs.length;
  }

  next() {
    return this.hasNext() ? this.songs[this.position++] : null;
  }
}

module.exports = SongIterator;
