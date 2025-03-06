// IMediaPlayer.h
#ifndef IMEDIAPLAYER_H
#define IMEDIAPLAYER_H

#include <string>

class IMediaPlayer {
public:
  virtual ~IMediaPlayer() = default;
  virtual void play(const std::string& audioType, const std::string& fileName) = 0;
};

#endif // IMEDIAPLAYER_H
