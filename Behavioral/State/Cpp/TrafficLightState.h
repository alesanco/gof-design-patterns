// TrafficLightState.h

#ifndef TRAFFICLIGHTSTATE_H
#define TRAFFICLIGHTSTATE_H

class TrafficLight;

class TrafficLightState {
public:
  virtual void handle(TrafficLight* trafficLight) = 0;
  virtual ~TrafficLightState() = default;
};

#endif // TRAFFICLIGHTSTATE_H
