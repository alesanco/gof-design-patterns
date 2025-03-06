// basicRemote.js

const Remote = require("./remote");

class BasicRemote extends Remote {
  volumeUp() {
    this.device.setVolume(this.device.getVolume() + 10);
  }

  volumeDown() {
    this.device.setVolume(this.device.getVolume() - 10);
  }
}

module.exports = BasicRemote;
