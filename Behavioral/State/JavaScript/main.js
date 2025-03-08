// main.js

const TrafficLight = require("./trafficLight");

const trafficLight = new TrafficLight();

for (let i = 0; i < 6; i++) {
  trafficLight.change();
}
