// Subject.h

#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>

class Subject {
public:
  virtual void addObserver(Observer* observer) = 0;
  virtual void removeObserver(Observer* observer) = 0;
  virtual void notifyObservers(const std::string& news) = 0;
  virtual ~Subject() = default;
};

#endif // SUBJECT_H
