// IShape.h
#ifndef I_SHAPE_H
#define I_SHAPE_H

class IShape {
public:
  virtual void draw() = 0;
  virtual ~IShape() = default;
};

#endif // I_SHAPE_H
