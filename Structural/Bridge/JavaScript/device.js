// device.js

class Device {
  turnOn() {
    throw new Error("Method 'turnOn()' must be implemented.");
  }

  turnOff() {
    throw new Error("Method 'turnOff()' must be implemented.");
  }

  setVolume(volume) {
    throw new Error("Method 'setVolume()' must be implemented.");
  }

  getVolume() {
    throw new Error("Method 'getVolume()' must be implemented.");
  }

  isOn() {
    throw new Error("Method 'isOn()' must be implemented.");
  }
}

module.exports = Device;
