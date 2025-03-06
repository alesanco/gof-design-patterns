// MP3Player.cpp
#include "MP3Player.h"

void MP3Player::play(const std::string& audioType, const std::string& fileName) {
  if (audioType == "MP3") {
    std::cout << "Playing MP3 file: " << fileName << std::endl;
  } else if (audioType == "MP4" || audioType == "VLC") {
    mediaAdapter = std::make_unique<MediaAdapter>(audioType);
    mediaAdapter->play(audioType, fileName);
  } else {
    std::cout << "Invalid media type: " << audioType << std::endl;
  }
}
