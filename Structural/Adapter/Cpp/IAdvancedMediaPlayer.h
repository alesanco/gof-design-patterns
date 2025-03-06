// IAdvancedMediaPlayer.h
#ifndef IADVANCEDMEDIAPLAYER_H
#define IADVANCEDMEDIAPLAYER_H

#include <string>

class IAdvancedMediaPlayer {
public:
  virtual ~IAdvancedMediaPlayer() = default;
  virtual void playMP4(const std::string& fileName) = 0;
  virtual void playVLC(const std::string& fileName) = 0;
};

#endif // IADVANCEDMEDIAPLAYER_H
