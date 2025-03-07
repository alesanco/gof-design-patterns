// Main.cpp

#include "VideoProxy.h"

int main() {
  VideoProxy proxy;

  proxy.loadVideo("movie1.mp4"); // First-time loading
  proxy.loadVideo("movie2.mp4"); // First-time loading
  proxy.loadVideo("movie1.mp4"); // Retrieved from cache

  return 0;
}
