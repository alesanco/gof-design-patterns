// ExportVisitor.cpp

#include "ExportVisitor.h"
#include "Circle.h"
#include "Square.h"

void ExportVisitor::visit(Circle& circle) {
  std::cout << "Exporting a Circle to file." << std::endl;
}

void ExportVisitor::visit(Square& square) {
  std::cout << "Exporting a Square to file." << std::endl;
}
