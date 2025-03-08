// NewsAgency.h

#ifndef NEWSAGENCY_H
#define NEWSAGENCY_H

#include "Subject.h"
#include <vector>
#include <algorithm>

class NewsAgency : public Subject {
private:
  std::vector<Observer*> observers;

public:
  void addObserver(Observer* observer) override;
  void removeObserver(Observer* observer) override;
  void notifyObservers(const std::string& news) override;
};

#endif // NEWSAGENCY_H
