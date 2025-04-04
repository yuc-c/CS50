# 作業2-1 mario-less
from cs50 import get_int

while True:
    n = get_int("Height: ")
    if 0 < n < 9:
        break

for i in range(n):
    for j in range(n - i - 1):
        print(" ", end = "")
    for j in range(i + 1):
        print("#", end = "")
    print("")
