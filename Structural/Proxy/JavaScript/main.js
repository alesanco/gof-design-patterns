// main.js

const VideoProxy = require("./videoProxy");

async function main() {
  const proxy = new VideoProxy();

  await proxy.loadVideo("movie1.mp4"); // First-time loading
  await proxy.loadVideo("movie2.mp4"); // First-time loading
  await proxy.loadVideo("movie1.mp4"); // Retrieved from cache
}

main();
