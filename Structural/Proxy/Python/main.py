# main.py

from video_proxy import VideoProxy

if __name__ == "__main__":
  proxy = VideoProxy()

  proxy.load_video("movie1.mp4")  # First-time loading
  proxy.load_video("movie2.mp4")  # First-time loading
  proxy.load_video("movie1.mp4")  # Retrieved from cache
