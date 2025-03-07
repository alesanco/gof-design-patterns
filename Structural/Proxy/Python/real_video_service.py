# real_video_service.py

import time
from video_service import VideoService

class RealVideoService(VideoService):
  def load_video(self, video_name: str):
    print(f"Loading video: {video_name}")
    time.sleep(2)  # Simulating video loading delay
    print(f"Playing video: {video_name}")
