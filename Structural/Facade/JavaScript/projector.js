// projector.js

class Projector {
  turnOn() {
    console.log("Projector is ON.");
  }

  turnOff() {
    console.log("Projector is OFF.");
  }

  setInput(inputSource) {
    console.log(`Projector input set to: ${inputSource}`);
  }
}

module.exports = Projector;
