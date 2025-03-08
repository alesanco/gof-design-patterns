// jsonProcessor.js

const DataProcessor = require("./dataProcessor");

class JSONProcessor extends DataProcessor {
  readData() {
    console.log("Reading data from JSON file...");
  }
}

module.exports = JSONProcessor;
