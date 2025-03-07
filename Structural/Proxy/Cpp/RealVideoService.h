// RealVideoService.h

#ifndef REALVIDEOSERVICE_H
#define REALVIDEOSERVICE_H

#include "IVideoService.h"
#include <iostream>
#include <thread>
#include <chrono>

class RealVideoService : public IVideoService {
public:
  void loadVideo(const std::string& videoName) override;
};

#endif // REALVIDEOSERVICE_H
