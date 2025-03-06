// folder.js

const FileSystemComponent = require("./fileSystemComponent");

class Folder extends FileSystemComponent {
  constructor(name) {
    super();
    this.name = name;
    this.components = [];
  }

  addComponent(component) {
    this.components.push(component);
  }

  showDetails() {
    console.log(`Folder: ${this.name}`);
    this.components.forEach(component => component.showDetails());
  }
}

module.exports = Folder;
