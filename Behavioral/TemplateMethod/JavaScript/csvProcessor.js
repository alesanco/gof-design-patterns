// csvProcessor.js

const DataProcessor = require("./dataProcessor");

class CSVProcessor extends DataProcessor {
  readData() {
    console.log("Reading data from CSV file...");
  }
}

module.exports = CSVProcessor;
