// dvdPlayer.js

class DVDPlayer {
  turnOn() {
    console.log("DVD Player is ON.");
  }

  turnOff() {
    console.log("DVD Player is OFF.");
  }

  play(movie) {
    console.log(`Playing movie: ${movie}`);
  }
}

module.exports = DVDPlayer;
