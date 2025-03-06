// MP4Player.h
#ifndef MP4PLAYER_H
#define MP4PLAYER_H

#include "IAdvancedMediaPlayer.h"
#include <iostream>

class MP4Player : public IAdvancedMediaPlayer {
public:
  void playMP4(const std::string& fileName) override;
  void playVLC(const std::string& fileName) override {}
};

#endif // MP4PLAYER_H
