// main.js

const Editor = require("./editor");
const History = require("./history");

const editor = new Editor();
const history = new History();

// Always save the initial empty state
history.save(editor.save());

// Save before making any changes
editor.type("Hello, World!");
history.save(editor.save());

editor.type("New content added.");
history.save(editor.save());

console.log("Current content:", editor.getContent());

editor.restore(history.undo());
console.log("After undo:", editor.getContent());

editor.restore(history.undo());
console.log("After second undo:", editor.getContent());
