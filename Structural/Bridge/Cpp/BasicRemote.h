// BasicRemote.h

#ifndef BASICREMOTE_H
#define BASICREMOTE_H

#include "IRemote.h"

class BasicRemote : public IRemote {
public:
  BasicRemote(IDevice* device);
  void togglePower() override;
  void volumeUp() override;
  void volumeDown() override;
};

#endif // BASICREMOTE_H
