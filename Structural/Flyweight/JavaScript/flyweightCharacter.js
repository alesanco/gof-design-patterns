// flyweightCharacter.js

class FlyweightCharacter {
  constructor(symbol) {
    this.symbol = symbol;
  }

  display() {
    console.log(`Character: ${this.symbol}`);
  }
}

module.exports = FlyweightCharacter;
