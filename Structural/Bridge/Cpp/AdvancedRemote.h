// AdvancedRemote.h

#ifndef ADVANCEDREMOTE_H
#define ADVANCEDREMOTE_H

#include "BasicRemote.h"

class AdvancedRemote : public BasicRemote {
public:
  AdvancedRemote(IDevice* device);
  void mute();
};

#endif // ADVANCEDREMOTE_H
