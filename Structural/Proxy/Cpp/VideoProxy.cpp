// VideoProxy.cpp

#include "VideoProxy.h"
#include <iostream>

void VideoProxy::loadVideo(const std::string& videoName) {
  if (cache.find(videoName) != cache.end()) {
    std::cout << "Retrieving cached video: " << videoName << std::endl;
    std::cout << "Playing video: " << videoName << std::endl;
  } else {
    realVideoService.loadVideo(videoName);
    cache[videoName] = true;
  }
}
