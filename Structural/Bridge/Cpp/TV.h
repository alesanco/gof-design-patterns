// TV.h

#ifndef TV_H
#define TV_H

#include "IDevice.h"
#include <iostream>

class TV : public IDevice {
private:
  bool on = false;
  int volume = 50;

public:
  void turnOn() override;
  void turnOff() override;
  void setVolume(int volume) override;
  int getVolume() const override;
  bool isOn() const override;
};

#endif // TV_H
