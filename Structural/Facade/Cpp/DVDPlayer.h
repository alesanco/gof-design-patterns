// DVDPlayer.h

#ifndef DVDPLAYER_H
#define DVDPLAYER_H

#include <iostream>
#include <string>

class DVDPlayer {
public:
  void turnOn();
  void turnOff();
  void play(const std::string& movie);
};

#endif // DVDPLAYER_H
