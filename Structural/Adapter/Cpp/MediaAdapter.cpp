// MediaAdapter.cpp
#include "MediaAdapter.h"

MediaAdapter::MediaAdapter(const std::string& audioType) {
  if (audioType == "MP4") {
    advancedMediaPlayer = std::make_unique<MP4Player>();
  } else if (audioType == "VLC") {
    advancedMediaPlayer = std::make_unique<VLCPlayer>();
  }
}

void MediaAdapter::play(const std::string& audioType, const std::string& fileName) {
  if (audioType == "MP4") {
    advancedMediaPlayer->playMP4(fileName);
  } else if (audioType == "VLC") {
    advancedMediaPlayer->playVLC(fileName);
  }
}
