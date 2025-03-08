// emailSubscriber.js

const Subscriber = require("./subscriber");

class EmailSubscriber extends Subscriber {
  update(news) {
    console.log(`${this.name} (Email) received: ${news}`);
  }
}

module.exports = EmailSubscriber;
