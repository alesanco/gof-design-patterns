// file.js

const FileSystemComponent = require("./fileSystemComponent");

class File extends FileSystemComponent {
  constructor(name) {
    super();
    this.name = name;
  }

  showDetails() {
    console.log(`File: ${this.name}`);
  }
}

module.exports = File;
