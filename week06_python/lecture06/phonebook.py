# names = ["Carter", "David", "John"]

# name = input("Name: ")

# for n in names:
#     if name == n:
#         print("Found")
# else:
#     print("Not found")

# if name in names:
#     print("Found")
# else:
#     print("Not found")

people = [
    {"name": "Carter", "number": "123"},
    {"name": "David", "number": "123"},
    {"name": "John", "number": "456"},
]

people = {
    "Carter": "123",
    "David": "123",
    "John": "456",
}

name = input("Name: ")

# for person in people:
#     if person["name"] == name:
#         print(f"Found {person['number']}")
#         break
# else:
#     print("Not found")

if name in people:
    print(f"Found {people[name]}")
else:
    print("Not found")
