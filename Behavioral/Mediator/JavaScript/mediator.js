// mediator.js

class Mediator {
  sendMessage(message, sender) {
    throw new Error("sendMessage() must be implemented by subclasses");
  }
}

module.exports = Mediator;
