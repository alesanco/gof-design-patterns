# logger.py

import threading

class Logger:
  _instance = None
  _lock = threading.Lock()  # Ensures thread safety

  def __new__(cls):
    with cls._lock:  # Thread-safe singleton
      if cls._instance is None:
        cls._instance = super(Logger, cls).__new__(cls)
        print("Logger instance created.")
      return cls._instance

  def log(self, message: str):
    print(f"[LOG]: {message}")
