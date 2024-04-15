import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = dict()

    for row in reader:
        favourite = row["language"]
        if favourite in counts:
            counts[favourite] += 1
        else:
            counts[favourite] = 1

for favourite in sorted(counts, key=counts.get, reverse=True):
    print(f"{favourite}: {counts[favourite]}")
