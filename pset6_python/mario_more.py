# 作業2-2 mario-more

while True:
    n = input("Height: ")
    if n.isdigit():
        n = int(n)
        if 0 < n < 9:
            break

for i in range(n):
    for j in range(n - i - 1):
        print(" ", end = "")
    for j in range(i + 1):
        print("#", end = "")
    print("  ", end = "")
    for j in range(i + 1):
        print("#", end = "")
    print("")
