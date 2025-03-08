// trafficLight.js

const RedLight = require("./redLight");

class TrafficLight {
  constructor() {
    this.state = new RedLight(); // Initial state
  }

  setState(state) {
    this.state = state;
  }

  change() {
    this.state.handle(this);
  }
}

module.exports = TrafficLight;
