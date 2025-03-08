# data_processor.py

from abc import ABC, abstractmethod

class DataProcessor(ABC):
  # Template method defining the structure of the algorithm
  def process(self):
    self.read_data()
    self.process_data()
    self.save_data()

  # Abstract method to be implemented by subclasses
  @abstractmethod
  def read_data(self):
    pass

  # Concrete method with common behavior
  def process_data(self):
    print("Processing data...")

  # Concrete method with common behavior
  def save_data(self):
    print("Data saved successfully.")
