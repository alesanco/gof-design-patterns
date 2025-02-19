from singleton import Singleton

s1 = Singleton()
s2 = Singleton()
print(s1 is s2)  # Should print: True
