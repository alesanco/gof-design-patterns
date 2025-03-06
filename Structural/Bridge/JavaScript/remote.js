// remote.js

class Remote {
  constructor(device) {
    this.device = device;
  }

  togglePower() {
    if (this.device.isOn()) {
      this.device.turnOff();
    } else {
      this.device.turnOn();
    }
  }
}

module.exports = Remote;
