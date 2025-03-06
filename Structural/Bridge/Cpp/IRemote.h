// IRemote.h

#ifndef IREMOTE_H
#define IREMOTE_H

#include "IDevice.h"

class IRemote {
protected:
  IDevice* device;

public:
  IRemote(IDevice* device) : device(device) {}
  virtual ~IRemote() = default;
  virtual void togglePower() = 0;
  virtual void volumeUp() = 0;
  virtual void volumeDown() = 0;
};

#endif // IREMOTE_H
