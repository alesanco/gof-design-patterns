# traffic_light.py

import red_light

class TrafficLight:
  def __init__(self):
    self._state = red_light.RedLight()  # Initial state

  def set_state(self, state):
    self._state = state

  def change(self):
    self._state.handle(self)
