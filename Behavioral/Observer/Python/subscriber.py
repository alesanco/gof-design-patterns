# subscriber.py

from observer import Observer

class Subscriber(Observer):
  def __init__(self, name):
    self._name = name

  def update(self, news):
    print(f"{self._name} received news update: {news}")
