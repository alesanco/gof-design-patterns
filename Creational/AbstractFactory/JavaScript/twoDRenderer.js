// twoDRenderer.js
const Renderer = require("./renderer");

class TwoDRenderer extends Renderer {
  render() {
    console.log("Rendering in 2D mode");
  }
}

module.exports = TwoDRenderer;
