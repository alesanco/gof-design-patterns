# news_agency.py

from subject import Subject

class NewsAgency(Subject):
  def __init__(self):
    self._observers = []

  def add_observer(self, observer):
    self._observers.append(observer)

  def remove_observer(self, observer):
    self._observers.remove(observer)

  def notify_observers(self, news):
    for observer in self._observers:
      observer.update(news)
