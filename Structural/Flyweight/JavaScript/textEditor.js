// textEditor.js

const CharacterFactory = require("./characterFactory");

class TextEditor {
  constructor() {
    this.characters = [];
  }

  addCharacter(symbol) {
    this.characters.push(CharacterFactory.getCharacter(symbol));
  }

  displayCharacters() {
    this.characters.forEach(character => character.display());
    console.log(`Total unique characters in memory: ${CharacterFactory.getPoolSize()}`);
  }
}

module.exports = TextEditor;
