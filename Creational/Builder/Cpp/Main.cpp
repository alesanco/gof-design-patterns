// Main.cpp
#include <iostream>
#include "CarDirector.h"

int main() {
  CarDirector director;

  // Build a Luxury Car
  Car* luxuryCar = director.buildLuxuryCar();
  std::cout << "\nLuxury Car:\n";
  luxuryCar->showSpecifications();

  // Build an Economy Car
  Car* economyCar = director.buildEconomyCar();
  std::cout << "\nEconomy Car:\n";
  economyCar->showSpecifications();

  // Clean up memory
  delete luxuryCar;
  delete economyCar;

  return 0;
}
