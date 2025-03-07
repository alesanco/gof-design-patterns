# main.py

from basic_support import BasicSupport
from supervisor import Supervisor
from manager import Manager

if __name__ == "__main__":
  basic = BasicSupport()
  supervisor = Supervisor()
  manager = Manager()

  # Setting up the chain
  basic.set_next_handler(supervisor)
  supervisor.set_next_handler(manager)

  # Sending requests
  basic.handle_request("Basic Issue")
  basic.handle_request("Intermediate Issue")
  basic.handle_request("Advanced Issue")
  basic.handle_request("Unknown Issue")
