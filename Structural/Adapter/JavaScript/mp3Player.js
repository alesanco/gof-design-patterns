// mp3Player.js
const MediaPlayer = require("./mediaPlayer");
const MediaAdapter = require("./mediaAdapter");

class MP3Player extends MediaPlayer {
  play(audioType, fileName) {
    if (audioType.toLowerCase() === "mp3") {
      console.log(`Playing MP3 file: ${fileName}`);
    } else if (audioType.toLowerCase() === "mp4" || audioType.toLowerCase() === "vlc") {
      const adapter = new MediaAdapter(audioType);
      adapter.play(audioType, fileName);
    } else {
      console.log(`Invalid media type: ${audioType}`);
    }
  }
}

module.exports = MP3Player;
