// tv.js

const Device = require("./device");

class TV extends Device {
  constructor() {
    super();
    this.on = false;
    this.volume = 50;
  }

  turnOn() {
    this.on = true;
    console.log("TV is now ON.");
  }

  turnOff() {
    this.on = false;
    console.log("TV is now OFF.");
  }

  setVolume(volume) {
    this.volume = volume;
    console.log(`TV volume set to ${volume}`);
  }

  getVolume() {
    return this.volume;
  }

  isOn() {
    return this.on;
  }
}

module.exports = TV;
