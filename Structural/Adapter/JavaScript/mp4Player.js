// mp4Player.js
const AdvancedMediaPlayer = require("./advancedMediaPlayer");

class MP4Player extends AdvancedMediaPlayer {
  playMP4(fileName) {
    console.log(`Playing MP4 file: ${fileName}`);
  }

  playVLC(fileName) {
    // MP4Player does not support VLC
  }
}

module.exports = MP4Player;
