// Car.cs
using System;

public class Car {
  public string Engine { get; private set; }
  public bool HasGPS { get; private set; }
  public bool HasSunroof { get; private set; }
  public string Seats { get; private set; }

  private Car(CarBuilder builder) {
    Engine = builder.Engine ?? "Unknown Engine";
    HasGPS = builder.HasGPS;
    HasSunroof = builder.HasSunroof;
    Seats = builder.Seats ?? "Standard";
  }

  public void ShowSpecifications() {
    Console.WriteLine("Car Specifications:");
    Console.WriteLine($"Engine: {Engine}");
    Console.WriteLine($"GPS: {(HasGPS ? "Yes" : "No")}");
    Console.WriteLine($"Sunroof: {(HasSunroof ? "Yes" : "No")}");
    Console.WriteLine($"Seats: {Seats}");
  }

  // Builder Class
  public class CarBuilder {
    public string? Engine { get; private set; }
    public bool HasGPS { get; private set; }
    public bool HasSunroof { get; private set; }
    public string? Seats { get; private set; }

    public CarBuilder SetEngine(string engine) {
      Engine = engine;
      return this;
    }

    public CarBuilder SetGPS(bool hasGPS) {
      HasGPS = hasGPS;
      return this;
    }

    public CarBuilder SetSunroof(bool hasSunroof) {
      HasSunroof = hasSunroof;
      return this;
    }

    public CarBuilder SetSeats(string seats) {
      Seats = seats;
      return this;
    }

    public Car Build() {
      return new Car(this);
    }
  }
}
