// remoteControl.js

class RemoteControl {
  constructor() {
    this.command = null;
  }

  setCommand(command) {
    this.command = command;
  }

  pressButton() {
    if (this.command) {
      this.command.execute();
    } else {
      console.log("No command assigned to button.");
    }
  }
}

module.exports = RemoteControl;
