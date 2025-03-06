// ThreeDRenderer.h

#ifndef THREE_D_RENDERER_H
#define THREE_D_RENDERER_H

#include "IRenderer.h"

class ThreeDRenderer : public IRenderer {
public:
  void render() override;
};

#endif // THREE_D_RENDERER_H
