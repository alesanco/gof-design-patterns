// chatUser.js

const User = require("./user");

class ChatUser extends User {
  constructor(mediator, name) {
    super(mediator, name);
  }

  sendMessage(message) {
    console.log(`${this.name} sends: ${message}`);
    this.mediator.sendMessage(message, this);
  }

  receiveMessage(message) {
    console.log(`${this.name} receives: ${message}`);
  }
}

module.exports = ChatUser;
