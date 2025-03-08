# main.py

from news_agency import NewsAgency
from email_subscriber import EmailSubscriber
from sms_subscriber import SMSSubscriber

if __name__ == "__main__":
  agency = NewsAgency()

  subscriber1 = EmailSubscriber("Alice")
  subscriber2 = SMSSubscriber("Bob")
  subscriber3 = EmailSubscriber("Charlie")

  agency.add_observer(subscriber1)
  agency.add_observer(subscriber2)
  agency.add_observer(subscriber3)

  agency.notify_observers("Breaking News: Observer Pattern Implemented!")

  agency.remove_observer(subscriber2)

  agency.notify_observers("Update: Python Observer Example Completed!")
