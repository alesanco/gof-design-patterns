// Main.cpp

#include "TV.h"
#include "Radio.h"
#include "BasicRemote.h"
#include "AdvancedRemote.h"

int main() {
  IDevice* tv = new TV();
  BasicRemote basicRemote(tv);

  basicRemote.togglePower();
  basicRemote.volumeUp();
  basicRemote.volumeDown();

  IDevice* radio = new Radio();
  AdvancedRemote advancedRemote(radio);

  advancedRemote.togglePower();
  advancedRemote.volumeUp();
  advancedRemote.mute();

  delete tv;
  delete radio;

  return 0;
}
