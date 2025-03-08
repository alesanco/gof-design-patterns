# traffic_light_state.py

from abc import ABC, abstractmethod

class TrafficLightState(ABC):
  @abstractmethod
  def handle(self, traffic_light):
    pass
