// ShapeVisitor.h

#ifndef SHAPEVISITOR_H
#define SHAPEVISITOR_H

class Circle;
class Square;

class ShapeVisitor {
public:
  virtual void visit(Circle& circle) = 0;
  virtual void visit(Square& square) = 0;
  virtual ~ShapeVisitor() = default;
};

#endif // SHAPEVISITOR_H
