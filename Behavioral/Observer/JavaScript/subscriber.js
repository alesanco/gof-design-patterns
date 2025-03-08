// subscriber.js

const Observer = require("./observer");

class Subscriber extends Observer {
  constructor(name) {
    super();
    this.name = name;
  }

  update(news) {
    console.log(`${this.name} received news update: ${news}`);
  }
}

module.exports = Subscriber;
