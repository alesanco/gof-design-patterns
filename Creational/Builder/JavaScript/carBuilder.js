// carBuilder.js

const Car = require("./car");

class CarBuilder {
  constructor() {
    this.engine = "Unknown Engine";
    this.hasGPS = false;
    this.hasSunroof = false;
    this.seats = "Standard";
  }

  setEngine(engine) {
    this.engine = engine;
    return this;
  }

  setGPS(hasGPS) {
    this.hasGPS = hasGPS;
    return this;
  }

  setSunroof(hasSunroof) {
    this.hasSunroof = hasSunroof;
    return this;
  }

  setSeats(seats) {
    this.seats = seats;
    return this;
  }

  build() {
    return new Car(this.engine, this.hasGPS, this.hasSunroof, this.seats);
  }
}

module.exports = CarBuilder;
