// threeDRenderer.js
const Renderer = require("./renderer");

class ThreeDRenderer extends Renderer {
  render() {
    console.log("Rendering in 3D mode");
  }
}

module.exports = ThreeDRenderer;
