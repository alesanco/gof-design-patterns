// main.js

const DVDPlayer = require("./dvdPlayer");
const Projector = require("./projector");
const SoundSystem = require("./soundSystem");
const Screen = require("./screen");
const HomeTheaterFacade = require("./homeTheaterFacade");

const dvdPlayer = new DVDPlayer();
const projector = new Projector();
const soundSystem = new SoundSystem();
const screen = new Screen();

const homeTheater = new HomeTheaterFacade(dvdPlayer, projector, soundSystem, screen);

homeTheater.watchMovie("Inception");
homeTheater.endMovie();
