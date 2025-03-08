// NewsAgency.cpp

#include "NewsAgency.h"

void NewsAgency::addObserver(Observer* observer) {
  observers.push_back(observer);
}

void NewsAgency::removeObserver(Observer* observer) {
  observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void NewsAgency::notifyObservers(const std::string& news) {
  for (Observer* observer : observers) {
    observer->update(news);
  }
}
