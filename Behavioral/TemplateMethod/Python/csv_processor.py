# csv_processor.py

from data_processor import DataProcessor

class CSVProcessor(DataProcessor):
  def read_data(self):
    print("Reading data from CSV file...")
