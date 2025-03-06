// Program.cs

using System;

class Program {
  static void Main() {
    CarDirector director = new CarDirector();

    // Build a Luxury Car
    Car luxuryCar = director.BuildLuxuryCar();
    Console.WriteLine("\nLuxury Car:");
    luxuryCar.ShowSpecifications();

    // Build an Economy Car
    Car economyCar = director.BuildEconomyCar();
    Console.WriteLine("\nEconomy Car:");
    economyCar.ShowSpecifications();
  }
}
