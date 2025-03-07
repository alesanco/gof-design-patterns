// IVideoService.h

#ifndef IVIDEOSERVICE_H
#define IVIDEOSERVICE_H

#include <string>

class IVideoService {
public:
  virtual void loadVideo(const std::string& videoName) = 0;
  virtual ~IVideoService() = default;
};

#endif // IVIDEOSERVICE_H
