// main.js

const CSVProcessor = require("./csvProcessor");
const JSONProcessor = require("./jsonProcessor");

const csvProcessor = new CSVProcessor();
csvProcessor.process();

console.log("---------------------");

const jsonProcessor = new JSONProcessor();
jsonProcessor.process();
