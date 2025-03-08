// editor.js

const EditorMemento = require("./editorMemento");

class Editor {
  constructor() {
    this._content = "";
  }

  type(words) {
    this._content = words;
  }

  save() {
    return new EditorMemento(this._content);
  }

  restore(memento) {
    if (memento) {
      this._content = memento.getContent();
    }
  }

  getContent() {
    return this._content;
  }
}

module.exports = Editor;
