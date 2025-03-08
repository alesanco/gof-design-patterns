// Main.cpp

#include "NewsAgency.h"
#include "EmailSubscriber.h"
#include "SMSSubscriber.h"

int main() {
  NewsAgency agency;

  Observer* subscriber1 = new EmailSubscriber("Alice");
  Observer* subscriber2 = new SMSSubscriber("Bob");
  Observer* subscriber3 = new EmailSubscriber("Charlie");

  agency.addObserver(subscriber1);
  agency.addObserver(subscriber2);
  agency.addObserver(subscriber3);

  agency.notifyObservers("Breaking News: Observer Pattern Implemented!");

  agency.removeObserver(subscriber2);

  agency.notifyObservers("Update: C++ Observer Example Completed!");

  delete subscriber1;
  delete subscriber2;
  delete subscriber3;

  return 0;
}
