// advancedRemote.js

const BasicRemote = require("./basicRemote");

class AdvancedRemote extends BasicRemote {
  mute() {
    this.device.setVolume(0);
    console.log("Device is muted.");
  }
}

module.exports = AdvancedRemote;
