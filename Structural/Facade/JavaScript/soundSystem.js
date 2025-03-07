// soundSystem.js

class SoundSystem {
  turnOn() {
    console.log("Sound System is ON.");
  }

  turnOff() {
    console.log("Sound System is OFF.");
  }

  setVolume(level) {
    console.log(`Sound System volume set to: ${level}`);
  }
}

module.exports = SoundSystem;
