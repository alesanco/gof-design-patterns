// main.js

const BasicSupport = require("./basicSupport");
const Supervisor = require("./supervisor");
const Manager = require("./manager");

const basic = new BasicSupport();
const supervisor = new Supervisor();
const manager = new Manager();

// Setting up the chain
basic.setNextHandler(supervisor);
supervisor.setNextHandler(manager);

// Sending requests
basic.handleRequest("Basic Issue");
basic.handleRequest("Intermediate Issue");
basic.handleRequest("Advanced Issue");
basic.handleRequest("Unknown Issue");
