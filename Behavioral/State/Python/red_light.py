# red_light.py

from traffic_light_state import TrafficLightState
import green_light

class RedLight(TrafficLightState):
  def handle(self, traffic_light):
    print("Red Light - STOP!")
    traffic_light.set_state(green_light.GreenLight())  # Transition to Green
