// RenderVisitor.cpp

#include "RenderVisitor.h"
#include "Circle.h"
#include "Square.h"

void RenderVisitor::visit(Circle& circle) {
  std::cout << "Rendering a Circle." << std::endl;
}

void RenderVisitor::visit(Square& square) {
  std::cout << "Rendering a Square." << std::endl;
}
