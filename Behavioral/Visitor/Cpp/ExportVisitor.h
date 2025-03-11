// ExportVisitor.h

#ifndef EXPORTVISITOR_H
#define EXPORTVISITOR_H

#include "ShapeVisitor.h"
#include <iostream>

class ExportVisitor : public ShapeVisitor {
public:
  void visit(Circle& circle) override;
  void visit(Square& square) override;
};

#endif // EXPORTVISITOR_H
