from sys import argv, exit

if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("Missing command-line argument.")
    exit()
