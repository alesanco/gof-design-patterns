// main.js

const Circle = require("./circle");
const Square = require("./square");
const RenderVisitor = require("./renderVisitor");
const ExportVisitor = require("./exportVisitor");

const shapes = [new Circle(), new Square()];

const renderVisitor = new RenderVisitor();
const exportVisitor = new ExportVisitor();

console.log("Applying Render Visitor:");
shapes.forEach(shape => shape.accept(renderVisitor));

console.log("\nApplying Export Visitor:");
shapes.forEach(shape => shape.accept(exportVisitor));
