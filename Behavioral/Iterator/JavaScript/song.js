// song.js

class Song {
  constructor(title, artist) {
    this.title = title;
    this.artist = artist;
  }

  toString() {
    return `"${this.title}" by ${this.artist}`;
  }
}

module.exports = Song;
