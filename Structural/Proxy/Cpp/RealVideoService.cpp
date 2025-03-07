// RealVideoService.cpp

#include "RealVideoService.h"

void RealVideoService::loadVideo(const std::string& videoName) {
  std::cout << "Loading video: " << videoName << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulating video loading delay
  std::cout << "Playing video: " << videoName << std::endl;
}
