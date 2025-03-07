// main.js

const Light = require("./light");
const TurnOnCommand = require("./turnOnCommand");
const TurnOffCommand = require("./turnOffCommand");
const RemoteControl = require("./remoteControl");

const light = new Light();
const turnOn = new TurnOnCommand(light);
const turnOff = new TurnOffCommand(light);

const remote = new RemoteControl();

remote.setCommand(turnOn);
remote.pressButton(); // The light is ON.

remote.setCommand(turnOff);
remote.pressButton(); // The light is OFF.
