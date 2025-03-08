// yellowLight.js

const TrafficLightState = require("./trafficLightState");

class YellowLight extends TrafficLightState {
  handle(trafficLight) {
    console.log("Yellow Light - PREPARE!");
    
    // FIX: Require inside the method to avoid circular dependency
    const RedLight = require("./redLight");
    trafficLight.setState(new RedLight()); // Transition to Red
  }
}

module.exports = YellowLight;
