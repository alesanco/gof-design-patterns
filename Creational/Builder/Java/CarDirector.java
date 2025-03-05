// CarDirector.java
public class CarDirector {
  public Car buildLuxuryCar() {
    return new Car.CarBuilder()
            .setEngine("V8 Turbo")
            .setGPS(true)
            .setSunroof(true)
            .setSeats("Leather")
            .build();
  }

  public Car buildEconomyCar() {
    return new Car.CarBuilder()
            .setEngine("1.6L Petrol")
            .setGPS(false)
            .setSunroof(false)
            .setSeats("Standard")
            .build();
  }
}
