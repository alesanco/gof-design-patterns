// main.js

const NewsAgency = require("./newsAgency");
const EmailSubscriber = require("./emailSubscriber");
const SMSSubscriber = require("./smsSubscriber");

const agency = new NewsAgency();

const subscriber1 = new EmailSubscriber("Alice");
const subscriber2 = new SMSSubscriber("Bob");
const subscriber3 = new EmailSubscriber("Charlie");

agency.addObserver(subscriber1);
agency.addObserver(subscriber2);
agency.addObserver(subscriber3);

agency.notifyObservers("Breaking News: Observer Pattern Implemented!");

agency.removeObserver(subscriber2);

agency.notifyObservers("Update: JavaScript Observer Example Completed!");
