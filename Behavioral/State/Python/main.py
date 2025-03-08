# main.py

from traffic_light import TrafficLight

if __name__ == "__main__":
  traffic_light = TrafficLight()

  for _ in range(6):
    traffic_light.change()
