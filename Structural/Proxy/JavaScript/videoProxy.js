// videoProxy.js

const VideoService = require("./videoService");
const RealVideoService = require("./realVideoService");

class VideoProxy extends VideoService {
  constructor() {
    super();
    this.realVideoService = new RealVideoService();
    this.cache = new Map();
  }

  async loadVideo(videoName) {
    if (this.cache.has(videoName)) {
      console.log(`Retrieving cached video: ${videoName}`);
      console.log(`Playing video: ${videoName}`);
    } else {
      await this.realVideoService.loadVideo(videoName);
      this.cache.set(videoName, true);
    }
  }
}

module.exports = VideoProxy;
