// iterator.js

class Iterator {
  hasNext() {
    throw new Error("hasNext() must be implemented by subclasses");
  }

  next() {
    throw new Error("next() must be implemented by subclasses");
  }
}

module.exports = Iterator;
