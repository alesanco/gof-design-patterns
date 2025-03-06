// Main.cpp
#include "MP3Player.h"

int main() {
  MP3Player player;

  player.play("MP3", "song.mp3");
  player.play("MP4", "video.mp4");
  player.play("VLC", "movie.vlc");
  player.play("AVI", "unsupported.avi");

  return 0;
}
