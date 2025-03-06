// logger.js

class Logger {
  static instance = null;

  constructor() {
    if (Logger.instance) {
      return Logger.instance;
    }
    Logger.instance = this;
    console.log("Logger instance created.");
  }

  log(message) {
    console.log(`[LOG]: ${message}`);
  }
}

module.exports = new Logger();
