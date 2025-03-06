// IDevice.cs

public interface IDevice {
  void TurnOn();
  void TurnOff();
  void SetVolume(int volume);
  int GetVolume();
  bool IsOn();
}
