import csv

from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()

    for row in reader:
        favourite = row["language"]
        counts[favourite] += 1

for favourite, count in counts.most_common():
    print(f"{favourite}: {count}")
