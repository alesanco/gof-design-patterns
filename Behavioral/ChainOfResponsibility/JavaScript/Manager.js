// Manager.js

const SupportHandler = require("./SupportHandler");

class Manager extends SupportHandler {
  handleRequest(request) {
    if (request === "Advanced Issue") {
      console.log(`Manager: Handling request - ${request}`);
    } else {
      console.log(`No handler available for - ${request}`);
    }
  }
}

module.exports = Manager;
