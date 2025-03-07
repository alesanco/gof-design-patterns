// turnOnCommand.js

const Command = require("./command");

class TurnOnCommand extends Command {
  constructor(light) {
    super();
    this.light = light;
  }

  execute() {
    this.light.turnOn();
  }
}

module.exports = TurnOnCommand;
