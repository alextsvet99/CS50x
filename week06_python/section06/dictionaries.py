book = dict()
book["title"] = "Coduroy"
book["author"] = "Don Freeman"
print(book)

library = list()
library.append(book)

while (True):
    book = dict()
    name = input("Title: ")
    if name == "":
        break
    book["title"] = name
    author = input("Author: ")
    if author == "":
        break
    book["author"] = author
    library.append(book)

for book in library:
    print(book)
