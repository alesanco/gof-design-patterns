// car.js
class Car {
  constructor(engine, hasGPS, hasSunroof, seats) {
    this.engine = engine;
    this.hasGPS = hasGPS;
    this.hasSunroof = hasSunroof;
    this.seats = seats;
  }

  showSpecifications() {
    console.log("Car Specifications:");
    console.log(`Engine: ${this.engine}`);
    console.log(`GPS: ${this.hasGPS ? "Yes" : "No"}`);
    console.log(`Sunroof: ${this.hasSunroof ? "Yes" : "No"}`);
    console.log(`Seats: ${this.seats}`);
  }
}

module.exports = Car;
