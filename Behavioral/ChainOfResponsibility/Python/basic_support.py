# basic_support.py

from support_handler import SupportHandler

class BasicSupport(SupportHandler):
  def handle_request(self, request):
    if request == "Basic Issue":
      print(f"BasicSupport: Handling request - {request}")
    elif self._next_handler:
      self._next_handler.handle_request(request)
    else:
      print(f"No handler available for - {request}")
