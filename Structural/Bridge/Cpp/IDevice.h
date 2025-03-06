// IDevice.h

#ifndef IDEVICE_H
#define IDEVICE_H

class IDevice {
public:
  virtual ~IDevice() = default;
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
  virtual void setVolume(int volume) = 0;
  virtual int getVolume() const = 0;
  virtual bool isOn() const = 0;
};

#endif // IDEVICE_H
