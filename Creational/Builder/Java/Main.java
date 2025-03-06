// Main.java

public class Main {
  public static void main(String[] args) {
    CarDirector director = new CarDirector();

    // Build a Luxury Car
    Car luxuryCar = director.buildLuxuryCar();
    System.out.println("\nLuxury Car:");
    luxuryCar.showSpecifications();

    // Build an Economy Car
    Car economyCar = director.buildEconomyCar();
    System.out.println("\nEconomy Car:");
    economyCar.showSpecifications();
  }
}
