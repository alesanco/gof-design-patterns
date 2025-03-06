// VLCPlayer.h
#ifndef VLCPLAYER_H
#define VLCPLAYER_H

#include "IAdvancedMediaPlayer.h"
#include <iostream>

class VLCPlayer : public IAdvancedMediaPlayer {
public:
  void playMP4(const std::string& fileName) override {}
  void playVLC(const std::string& fileName) override;
};

#endif // VLCPLAYER_H
