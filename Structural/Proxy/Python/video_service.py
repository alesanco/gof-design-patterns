# video_service.py

from abc import ABC, abstractmethod

class VideoService(ABC):
  @abstractmethod
  def load_video(self, video_name: str):
    pass
