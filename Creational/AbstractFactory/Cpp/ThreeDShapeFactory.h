// ThreeDShapeFactory.h
#ifndef THREE_D_SHAPE_FACTORY_H
#define THREE_D_SHAPE_FACTORY_H

#include "IShapeFactory.h"

class ThreeDShapeFactory : public IShapeFactory {
public:
  IShape* createShape(ShapeType type) override;
  IRenderer* createRenderer() override;
};

#endif // THREE_D_SHAPE_FACTORY_H
