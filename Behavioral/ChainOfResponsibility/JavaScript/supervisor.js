// Supervisor.js

const SupportHandler = require("./supportHandler");

class Supervisor extends SupportHandler {
  handleRequest(request) {
    if (request === "Intermediate Issue") {
      console.log(`Supervisor: Handling request - ${request}`);
    } else if (this.nextHandler) {
      this.nextHandler.handleRequest(request);
    } else {
      console.log(`No handler available for - ${request}`);
    }
  }
}

module.exports = Supervisor;
