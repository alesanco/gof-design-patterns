// CarDirector.cs

public class CarDirector {
  public Car BuildLuxuryCar() {
    return new Car.CarBuilder()
            .SetEngine("V8 Turbo")
            .SetGPS(true)
            .SetSunroof(true)
            .SetSeats("Leather")
            .Build();
  }

  public Car BuildEconomyCar() {
    return new Car.CarBuilder()
            .SetEngine("1.6L Petrol")
            .SetGPS(false)
            .SetSunroof(false)
            .SetSeats("Standard")
            .Build();
  }
}
