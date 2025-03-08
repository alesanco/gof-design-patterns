# sms_subscriber.py

from subscriber import Subscriber

class SMSSubscriber(Subscriber):
  def update(self, news):
    print(f"{self._name} (SMS) received: {news}")
