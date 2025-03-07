// HomeTheaterFacade.cpp

#include "HomeTheaterFacade.h"
#include <iostream>

HomeTheaterFacade::HomeTheaterFacade(DVDPlayer dvd, Projector proj, SoundSystem sound, Screen scr)
    : dvdPlayer(dvd), projector(proj), soundSystem(sound), screen(scr) {}

void HomeTheaterFacade::watchMovie(const std::string& movie) {
  std::cout << "\nGetting ready to watch a movie..." << std::endl;
  screen.lower();
  projector.turnOn();
  projector.setInput("DVD");
  soundSystem.turnOn();
  soundSystem.setVolume(10);
  dvdPlayer.turnOn();
  dvdPlayer.play(movie);
}

void HomeTheaterFacade::endMovie() {
  std::cout << "\nShutting down home theater..." << std::endl;
  dvdPlayer.turnOff();
  soundSystem.turnOff();
  projector.turnOff();
  screen.raise();
}
