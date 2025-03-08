// smsSubscriber.js

const Subscriber = require("./subscriber");

class SMSSubscriber extends Subscriber {
  update(news) {
    console.log(`${this.name} (SMS) received: ${news}`);
  }
}

module.exports = SMSSubscriber;
