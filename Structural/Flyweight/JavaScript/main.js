// main.js

const TextEditor = require("./textEditor");

const editor = new TextEditor();

const text = "Hello Flyweight!";
for (const char of text) {
  editor.addCharacter(char);
}

editor.displayCharacters();
