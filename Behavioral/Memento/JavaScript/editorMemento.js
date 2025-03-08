// editorMemento.js

class EditorMemento {
  constructor(content) {
    this._content = content;
  }

  getContent() {
    return this._content;
  }
}

module.exports = EditorMemento;
