text = input("Text: ")
text = text.strip()
print(text)
print(text.capitalize())
print(text.upper())

words = text.split()

for w in words:
    print(w)

for c in text[5:10]:
    print(c)
