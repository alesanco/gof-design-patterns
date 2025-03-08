// history.js

class History {
  constructor() {
    this._history = [];
  }

  save(memento) {
    if (memento) {
      this._history.push(memento);
    }
  }

  undo() {
    if (this._history.length > 1) {
      this._history.pop(); // Remove the latest state
    }
    return this._history.length > 0 ? this._history[this._history.length - 1] : null;
  }
}

module.exports = History;
