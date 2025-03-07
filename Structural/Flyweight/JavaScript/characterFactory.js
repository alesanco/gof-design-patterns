// characterFactory.js

const FlyweightCharacter = require("./flyweightCharacter");

class CharacterFactory {
  static characterPool = new Map();

  static getCharacter(symbol) {
    if (!this.characterPool.has(symbol)) {
      this.characterPool.set(symbol, new FlyweightCharacter(symbol));
    }
    return this.characterPool.get(symbol);
  }

  static getPoolSize() {
    return this.characterPool.size;
  }
}

module.exports = CharacterFactory;
