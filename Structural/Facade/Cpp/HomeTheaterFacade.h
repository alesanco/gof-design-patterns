// HomeTheaterFacade.h

#ifndef HOMETHEATERFACADE_H
#define HOMETHEATERFACADE_H

#include "DVDPlayer.h"
#include "Projector.h"
#include "SoundSystem.h"
#include "Screen.h"
#include <string>

class HomeTheaterFacade {
private:
  DVDPlayer dvdPlayer;
  Projector projector;
  SoundSystem soundSystem;
  Screen screen;

public:
  HomeTheaterFacade(DVDPlayer dvd, Projector proj, SoundSystem sound, Screen scr);
  void watchMovie(const std::string& movie);
  void endMovie();
};

#endif // HOMETHEATERFACADE_H
