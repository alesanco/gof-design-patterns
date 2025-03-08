// user.js

class User {
  constructor(mediator, name) {
    this.mediator = mediator;
    this.name = name;
  }

  sendMessage(message) {
    throw new Error("sendMessage() must be implemented by subclasses");
  }

  receiveMessage(message) {
    throw new Error("receiveMessage() must be implemented by subclasses");
  }
}

module.exports = User;
