# main.py

from csv_processor import CSVProcessor
from json_processor import JSONProcessor

if __name__ == "__main__":
  csv_processor = CSVProcessor()
  csv_processor.process()

  print("---------------------")

  json_processor = JSONProcessor()
  json_processor.process()
