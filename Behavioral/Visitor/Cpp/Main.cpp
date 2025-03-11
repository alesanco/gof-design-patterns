// Main.cpp

#include "Circle.h"
#include "Square.h"
#include "RenderVisitor.h"
#include "ExportVisitor.h"
#include <vector>
#include <memory>

int main() {
  std::vector<std::unique_ptr<Shape>> shapes;
  shapes.push_back(std::make_unique<Circle>());
  shapes.push_back(std::make_unique<Square>());

  RenderVisitor renderVisitor;
  ExportVisitor exportVisitor;

  std::cout << "Applying Render Visitor:" << std::endl;
  for (const auto& shape : shapes) {
    shape->accept(renderVisitor);
  }

  std::cout << "\nApplying Export Visitor:" << std::endl;
  for (const auto& shape : shapes) {
    shape->accept(exportVisitor);
  }

  return 0;
}
