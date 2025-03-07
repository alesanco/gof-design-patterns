# manager.py

from support_handler import SupportHandler

class Manager(SupportHandler):
  def handle_request(self, request):
    if request == "Advanced Issue":
      print(f"Manager: Handling request - {request}")
    else:
      print(f"No handler available for - {request}")
