// chatMediator.js

const Mediator = require("./mediator");

class ChatMediator extends Mediator {
  constructor() {
    super();
    this.users = [];
  }

  addUser(user) {
    this.users.push(user);
  }

  sendMessage(message, sender) {
    this.users.forEach(user => {
      if (user !== sender) {
        user.receiveMessage(message);
      }
    });
  }
}

module.exports = ChatMediator;
