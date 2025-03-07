// SupportHandler.js

class SupportHandler {
  constructor() {
    this.nextHandler = null;
  }

  setNextHandler(handler) {
    this.nextHandler = handler;
  }

  handleRequest(request) {
    throw new Error("handleRequest() must be implemented by subclasses");
  }
}

module.exports = SupportHandler;
