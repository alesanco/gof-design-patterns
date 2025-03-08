// dataProcessor.js

class DataProcessor {
  // Template method defining the structure of the algorithm
  process() {
    this.readData();
    this.processData();
    this.saveData();
  }

  // Abstract method to be implemented by subclasses
  readData() {
    throw new Error("Method 'readData()' must be implemented.");
  }

  // Concrete method with common behavior
  processData() {
    console.log("Processing data...");
  }

  // Concrete method with common behavior
  saveData() {
    console.log("Data saved successfully.");
  }
}

module.exports = DataProcessor;
