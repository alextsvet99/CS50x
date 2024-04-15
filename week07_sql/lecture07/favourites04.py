import csv

from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()

    for row in reader:
        favourite = row["problem"]
        counts[favourite] += 1

favourite = input("Favourite: ")
print(f"{favourite}: {counts[favourite]}")
