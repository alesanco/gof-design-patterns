# yellow_light.py

from traffic_light_state import TrafficLightState
import red_light

class YellowLight(TrafficLightState):
  def handle(self, traffic_light):
    print("Yellow Light - PREPARE!")
    traffic_light.set_state(red_light.RedLight())  # Transition to Red
