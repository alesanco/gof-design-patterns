// mediaAdapter.js
const MediaPlayer = require("./mediaPlayer");
const MP4Player = require("./mp4Player");
const VLCPlayer = require("./vlcPlayer");

class MediaAdapter extends MediaPlayer {
  constructor(audioType) {
    super();
    if (audioType.toLowerCase() === "mp4") {
      this.advancedMediaPlayer = new MP4Player();
    } else if (audioType.toLowerCase() === "vlc") {
      this.advancedMediaPlayer = new VLCPlayer();
    } else {
      this.advancedMediaPlayer = null;
    }
  }

  play(audioType, fileName) {
    if (this.advancedMediaPlayer) {
      if (audioType.toLowerCase() === "mp4") {
        this.advancedMediaPlayer.playMP4(fileName);
      } else if (audioType.toLowerCase() === "vlc") {
        this.advancedMediaPlayer.playVLC(fileName);
      }
    }
  }
}

module.exports = MediaAdapter;
