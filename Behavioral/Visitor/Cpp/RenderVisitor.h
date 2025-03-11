// RenderVisitor.h

#ifndef RENDERVISITOR_H
#define RENDERVISITOR_H

#include "ShapeVisitor.h"
#include <iostream>

class RenderVisitor : public ShapeVisitor {
public:
  void visit(Circle& circle) override;
  void visit(Square& square) override;
};

#endif // RENDERVISITOR_H
