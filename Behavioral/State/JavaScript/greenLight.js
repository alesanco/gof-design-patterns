// greenLight.js

const TrafficLightState = require("./trafficLightState");

class GreenLight extends TrafficLightState {
  handle(trafficLight) {
    console.log("Green Light - GO!");
    
    // FIX: Lazy import to avoid circular dependency
    const YellowLight = require("./yellowLight");
    trafficLight.setState(new YellowLight()); // Transition to Yellow
  }
}

module.exports = GreenLight;
