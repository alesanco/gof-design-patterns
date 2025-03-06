// radio.js

const Device = require("./device");

class Radio extends Device {
  constructor() {
    super();
    this.on = false;
    this.volume = 30;
  }

  turnOn() {
    this.on = true;
    console.log("Radio is now ON.");
  }

  turnOff() {
    this.on = false;
    console.log("Radio is now OFF.");
  }

  setVolume(volume) {
    this.volume = volume;
    console.log(`Radio volume set to ${volume}`);
  }

  getVolume() {
    return this.volume;
  }

  isOn() {
    return this.on;
  }
}

module.exports = Radio;
