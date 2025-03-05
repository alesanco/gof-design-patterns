// IShapeFactory.h
#ifndef I_SHAPE_FACTORY_H
#define I_SHAPE_FACTORY_H

#include "IShape.h"
#include "IRenderer.h"
#include "ShapeType.h"

class IShapeFactory {
public:
  virtual IShape* createShape(ShapeType type) = 0;
  virtual IRenderer* createRenderer() = 0;
  virtual ~IShapeFactory() = default;
};

#endif // I_SHAPE_FACTORY_H
