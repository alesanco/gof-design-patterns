// main.js

const TV = require("./tv");
const Radio = require("./radio");
const BasicRemote = require("./basicRemote");
const AdvancedRemote = require("./advancedRemote");

const tv = new TV();
const basicRemote = new BasicRemote(tv);

basicRemote.togglePower();
basicRemote.volumeUp();
basicRemote.volumeDown();

const radio = new Radio();
const advancedRemote = new AdvancedRemote(radio);

advancedRemote.togglePower();
advancedRemote.volumeUp();
advancedRemote.mute();
