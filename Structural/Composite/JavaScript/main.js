// main.js

const File = require("./file");
const Folder = require("./folder");

const file1 = new File("document.txt");
const file2 = new File("photo.jpg");

const folder1 = new Folder("My Documents");
folder1.addComponent(file1);
folder1.addComponent(file2);

const file3 = new File("video.mp4");
const folder2 = new Folder("Media");
folder2.addComponent(file3);
folder2.addComponent(folder1);

folder2.showDetails();
