# email_subscriber.py

from subscriber import Subscriber

class EmailSubscriber(Subscriber):
  def update(self, news):
    print(f"{self._name} (Email) received: {news}")
