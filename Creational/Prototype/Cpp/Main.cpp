// Main.cpp

#include <iostream>
#include "Circle.h"
#include "Square.h"

int main() {
  // Create an original Circle and Square
  Circle* originalCircle = new Circle("Red", 10);
  Square* originalSquare = new Square("Blue", 5);

  // Clone the objects
  Circle* clonedCircle = originalCircle->clone();
  Square* clonedSquare = originalSquare->clone();

  // Modify cloned objects
  clonedCircle->setColor("Green");
  clonedCircle->setRadius(20);

  clonedSquare->setColor("Yellow");
  clonedSquare->setSideLength(10);

  // Display original and cloned objects
  std::cout << "Original Objects:" << std::endl;
  originalCircle->draw();
  originalSquare->draw();

  std::cout << "\nCloned Objects:" << std::endl;
  clonedCircle->draw();
  clonedSquare->draw();

  // Clean up memory
  delete originalCircle;
  delete originalSquare;
  delete clonedCircle;
  delete clonedSquare;

  return 0;
}
