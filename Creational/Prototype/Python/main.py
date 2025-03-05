# main.py
from circle import Circle
from square import Square

if __name__ == "__main__":
  # Create an original Circle and Square
  original_circle = Circle("Red", 10)
  original_square = Square("Blue", 5)

  # Clone the objects
  cloned_circle = original_circle.clone()
  cloned_square = original_square.clone()

  # Modify cloned objects
  cloned_circle.set_color("Green")
  cloned_circle.set_radius(20)

  cloned_square.set_color("Yellow")
  cloned_square.set_side_length(10)

  # Display original and cloned objects
  print("Original Objects:")
  original_circle.draw()
  original_square.draw()

  print("\nCloned Objects:")
  cloned_circle.draw()
  cloned_square.draw()
