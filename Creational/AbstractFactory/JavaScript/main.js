// main.js
const RenderMode = require("./renderMode");
const ShapeType = require("./shapeType");
const TwoDShapeFactory = require("./twoDShapeFactory");
const ThreeDShapeFactory = require("./threeDShapeFactory");

for (const mode of Object.values(RenderMode)) {
  let factory;
  
  switch (mode) {
    case RenderMode.TWO_D:
      factory = new TwoDShapeFactory();
      break;
    case RenderMode.THREE_D:
      factory = new ThreeDShapeFactory();
      break;
    default:
      throw new Error(`Unknown render mode: ${mode}`);
  }

  for (const shapeType of Object.values(ShapeType)) {
    console.log(`\n=== Mode: ${mode}, Shape: ${shapeType} ===`);
    
    const shape = factory.createShape(shapeType);
    const renderer = factory.createRenderer();

    shape.draw();
    renderer.render();
  }
}
