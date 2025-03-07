// realVideoService.js

const VideoService = require("./videoService");

class RealVideoService extends VideoService {
  async loadVideo(videoName) {
    console.log(`Loading video: ${videoName}`);
    await new Promise(resolve => setTimeout(resolve, 2000)); // Simulate delay
    console.log(`Playing video: ${videoName}`);
  }
}

module.exports = RealVideoService;
