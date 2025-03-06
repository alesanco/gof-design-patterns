# main.py

from logger import Logger

if __name__ == "__main__":
  logger1 = Logger()
  logger1.log("Initializing the system...")

  logger2 = Logger()
  logger2.log("System running.")

  # Verify if both instances are the same
  print(f"Logger instances are the same: {logger1 is logger2}")
