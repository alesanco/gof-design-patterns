// redLight.js

const TrafficLightState = require("./trafficLightState");

class RedLight extends TrafficLightState {
  handle(trafficLight) {
    console.log("Red Light - STOP!");
    
    // Lazy import to avoid circular dependency
    const GreenLight = require("./greenLight");
    trafficLight.setState(new GreenLight()); // Transition to Green
  }
}

module.exports = RedLight;
