// Car.java
public class Car {
  private final String engine;
  private final boolean hasGPS;
  private final boolean hasSunroof;
  private final String seats;

  private Car(CarBuilder builder) {
    this.engine = builder.engine;
    this.hasGPS = builder.hasGPS;
    this.hasSunroof = builder.hasSunroof;
    this.seats = builder.seats;
  }

  public void showSpecifications() {
    System.out.println("Car Specifications:");
    System.out.println("Engine: " + engine);
    System.out.println("GPS: " + (hasGPS ? "Yes" : "No"));
    System.out.println("Sunroof: " + (hasSunroof ? "Yes" : "No"));
    System.out.println("Seats: " + seats);
  }

  // Builder Class
  public static class CarBuilder {
    private String engine;
    private boolean hasGPS;
    private boolean hasSunroof;
    private String seats;

    public CarBuilder setEngine(String engine) {
      this.engine = engine;
      return this;
    }

    public CarBuilder setGPS(boolean hasGPS) {
      this.hasGPS = hasGPS;
      return this;
    }

    public CarBuilder setSunroof(boolean hasSunroof) {
      this.hasSunroof = hasSunroof;
      return this;
    }

    public CarBuilder setSeats(String seats) {
      this.seats = seats;
      return this;
    }

    public Car build() {
      return new Car(this);
    }
  }
}
