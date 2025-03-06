// MP3Player.h
#ifndef MP3PLAYER_H
#define MP3PLAYER_H

#include "IMediaPlayer.h"
#include "MediaAdapter.h"
#include <iostream>
#include <memory>

class MP3Player : public IMediaPlayer {
private:
  std::unique_ptr<MediaAdapter> mediaAdapter;

public:
  void play(const std::string& audioType, const std::string& fileName) override;
};

#endif // MP3PLAYER_H
