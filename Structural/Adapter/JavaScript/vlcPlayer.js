// vlcPlayer.js
const AdvancedMediaPlayer = require("./advancedMediaPlayer");

class VLCPlayer extends AdvancedMediaPlayer {
  playMP4(fileName) {
    // VLCPlayer does not support MP4
  }

  playVLC(fileName) {
    console.log(`Playing VLC file: ${fileName}`);
  }
}

module.exports = VLCPlayer;
