const Singleton = require("./singleton");

const s1 = new Singleton();
const s2 = new Singleton();
console.log(s1 === s2); // Should print: true
