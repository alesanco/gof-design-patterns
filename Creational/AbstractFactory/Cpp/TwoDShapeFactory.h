// TwoDShapeFactory.h
#ifndef TWO_D_SHAPE_FACTORY_H
#define TWO_D_SHAPE_FACTORY_H

#include "IShapeFactory.h"

class TwoDShapeFactory : public IShapeFactory {
public:
  IShape* createShape(ShapeType type) override;
  IRenderer* createRenderer() override;
};

#endif // TWO_D_SHAPE_FACTORY_H
