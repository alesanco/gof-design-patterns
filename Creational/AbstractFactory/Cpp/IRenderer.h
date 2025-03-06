// IRenderer.h

#ifndef I_RENDERER_H
#define I_RENDERER_H

class IRenderer {
public:
  virtual void render() = 0;
  virtual ~IRenderer() = default;
};

#endif // I_RENDERER_H
