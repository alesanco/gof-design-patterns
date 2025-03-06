// MediaAdapter.h
#ifndef MEDIAADAPTER_H
#define MEDIAADAPTER_H

#include "IMediaPlayer.h"
#include "IAdvancedMediaPlayer.h"
#include "MP4Player.h"
#include "VLCPlayer.h"
#include <memory>

class MediaAdapter : public IMediaPlayer {
private:
  std::unique_ptr<IAdvancedMediaPlayer> advancedMediaPlayer;

public:
  MediaAdapter(const std::string& audioType);
  void play(const std::string& audioType, const std::string& fileName) override;
};

#endif // MEDIAADAPTER_H
