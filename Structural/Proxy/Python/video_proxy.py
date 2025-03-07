# video_proxy.py

from video_service import VideoService
from real_video_service import RealVideoService

class VideoProxy(VideoService):
  def __init__(self):
    self._real_video_service = RealVideoService()
    self._cache = {}

  def load_video(self, video_name: str):
    if video_name in self._cache:
      print(f"Retrieving cached video: {video_name}")
      print(f"Playing video: {video_name}")
    else:
      self._real_video_service.load_video(video_name)
      self._cache[video_name] = True
