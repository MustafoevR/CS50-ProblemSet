# Prompt the user for the amount of change
# Use the largest coins possible, keeping of coins used
# Print the number of coins
# Computing coins
# Keep track of remaining change owed
# Keep track of how many coins used

from cs50 import get_float

while True:
    n = get_float("Change owed: ")
    if n > 0:
        break
cents = round(n * 100)
coins_used = 0
while cents != 0:
    # For 25
    coins_used += cents // 25
    cents %= 25
    # For 10
    coins_used += cents // 10
    cents %= 10
    # For 5
    coins_used += cents // 5
    cents %= 5
    # For 1
    coins_used += cents // 1
    cents %= 1

print(coins_used)


