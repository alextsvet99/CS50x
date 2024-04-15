from csv import DictReader
from sys import argv, exit

if len(argv) == 1:
    print("Usage: python library.py FILE")
    exit()

books = list()

with open(argv[1]) as file:
    file_reader = DictReader(file)
    for book in file_reader:
        books.append(book)

for book in books:
    print(f"{book['author']} wrote {book['title']}")
