// command.js

class Command {
  execute() {
    throw new Error("execute() must be implemented by subclasses");
  }
}

module.exports = Command;
