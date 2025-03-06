// Radio.h

#ifndef RADIO_H
#define RADIO_H

#include "IDevice.h"
#include <iostream>

class Radio : public IDevice {
private:
  bool on = false;
  int volume = 30;

public:
  void turnOn() override;
  void turnOff() override;
  void setVolume(int volume) override;
  int getVolume() const override;
  bool isOn() const override;
};

#endif // RADIO_H
