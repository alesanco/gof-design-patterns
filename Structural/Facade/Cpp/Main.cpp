// Main.cpp

#include "HomeTheaterFacade.h"

int main() {
  DVDPlayer dvdPlayer;
  Projector projector;
  SoundSystem soundSystem;
  Screen screen;

  HomeTheaterFacade homeTheater(dvdPlayer, projector, soundSystem, screen);

  homeTheater.watchMovie("Inception");
  homeTheater.endMovie();

  return 0;
}
