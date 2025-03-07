// VideoProxy.h

#ifndef VIDEOPROXY_H
#define VIDEOPROXY_H

#include "IVideoService.h"
#include "RealVideoService.h"
#include <unordered_map>

class VideoProxy : public IVideoService {
private:
  RealVideoService realVideoService;
  std::unordered_map<std::string, bool> cache;

public:
  void loadVideo(const std::string& videoName) override;
};

#endif // VIDEOPROXY_H
