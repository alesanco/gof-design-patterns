// homeTheaterFacade.js

const DVDPlayer = require("./dvdPlayer");
const Projector = require("./projector");
const SoundSystem = require("./soundSystem");
const Screen = require("./screen");

class HomeTheaterFacade {
  constructor(dvdPlayer, projector, soundSystem, screen) {
    this.dvdPlayer = dvdPlayer;
    this.projector = projector;
    this.soundSystem = soundSystem;
    this.screen = screen;
  }

  watchMovie(movie) {
    console.log("\nGetting ready to watch a movie...");
    this.screen.lower();
    this.projector.turnOn();
    this.projector.setInput("DVD");
    this.soundSystem.turnOn();
    this.soundSystem.setVolume(10);
    this.dvdPlayer.turnOn();
    this.dvdPlayer.play(movie);
  }

  endMovie() {
    console.log("\nShutting down home theater...");
    this.dvdPlayer.turnOff();
    this.soundSystem.turnOff();
    this.projector.turnOff();
    this.screen.raise();
  }
}

module.exports = HomeTheaterFacade;
