import csv

# with open("favorites.csv", "r") as file:
#     reader = csv.reader(file)
#     next(reader)
#     for row in reader:
#         print(row[1])

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    scratch, c, python = 0, 0, 0

    for row in reader:
        favourite = row["language"]
        if favourite == "Scratch":
            scratch += 1
        elif favourite == "C":
            c += 1
        elif favourite == "Python":
            python += 1

print(f"Scratch: {scratch}")
print(f"C: {c}")
print(f"Python: {python}")
