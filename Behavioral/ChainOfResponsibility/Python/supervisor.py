# supervisor.py

from support_handler import SupportHandler

class Supervisor(SupportHandler):
  def handle_request(self, request):
    if request == "Intermediate Issue":
      print(f"Supervisor: Handling request - {request}")
    elif self._next_handler:
      self._next_handler.handle_request(request)
    else:
      print(f"No handler available for - {request}")
