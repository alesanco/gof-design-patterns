// TurnOffCommand.js

const Command = require("./command");

class TurnOffCommand extends Command {
  constructor(light) {
    super();
    this.light = light;
  }

  execute() {
    this.light.turnOff();
  }
}

module.exports = TurnOffCommand;
