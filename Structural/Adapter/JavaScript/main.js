// main.js
const MP3Player = require("./mp3Player");

const player = new MP3Player();

player.play("MP3", "song.mp3");
player.play("MP4", "video.mp4");
player.play("VLC", "movie.vlc");
player.play("AVI", "unsupported.avi");
