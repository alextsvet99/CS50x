def main():
    x = get_int("x: ")
    y = get_int("y: ")

    z = x / y

    print(f"division: {z}")


def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            # pass
            print("Not an integer")


main()
