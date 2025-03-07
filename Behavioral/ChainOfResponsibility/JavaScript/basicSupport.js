// BasicSupport.js

const SupportHandler = require("./supportHandler");

class BasicSupport extends SupportHandler {
  handleRequest(request) {
    if (request === "Basic Issue") {
      console.log(`BasicSupport: Handling request - ${request}`);
    } else if (this.nextHandler) {
      this.nextHandler.handleRequest(request);
    } else {
      console.log(`No handler available for - ${request}`);
    }
  }
}

module.exports = BasicSupport;
