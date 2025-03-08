# green_light.py

from traffic_light_state import TrafficLightState
import yellow_light

class GreenLight(TrafficLightState):
  def handle(self, traffic_light):
    print("Green Light - GO!")
    traffic_light.set_state(yellow_light.YellowLight())  # Transition to Yellow
