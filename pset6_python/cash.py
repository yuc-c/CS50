# 作業3-1 cash

from cs50 import get_float

while True:
    cents = get_float("Change: ")
    if cents > 0:
        break
coins = 0
while True:
    while round(cents,2) >= 0.25:
        cents = round(cents,2) - 0.25
        coins += 1
    while round(cents,2) >= 0.1:
        cents = round(cents,2) - 0.1
        coins += 1
    while round(cents,2) >= 0.05:
        cents = round(cents,2) - 0.05
        coins += 1
    while round(cents,2) >= 0.01:
        cents = round(cents,2) - 0.01
        coins += 1
    if cents < 0.01:
        break
print(f"{int(coins)}")
