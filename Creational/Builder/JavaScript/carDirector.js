// carDirector.js

const CarBuilder = require("./carBuilder");

class CarDirector {
  buildLuxuryCar() {
    return new CarBuilder()
            .setEngine("V8 Turbo")
            .setGPS(true)
            .setSunroof(true)
            .setSeats("Leather")
            .build();
  }

  buildEconomyCar() {
    return new CarBuilder()
            .setEngine("1.6L Petrol")
            .setGPS(false)
            .setSunroof(false)
            .setSeats("Standard")
            .build();
  }
}

module.exports = CarDirector;
