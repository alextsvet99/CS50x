#!/usr/bin/env python3

HEIGHT_MIN = 1
HEIGHT_MAX = 8


def main():
    height = get_height()
    print_pyramid(height, height)


# Asks user for pyramid height
def get_height():
    while True:
        try:
            height = int(input("Height: "))

            if height < HEIGHT_MIN or height > HEIGHT_MAX:
                print(f"Height must be between {HEIGHT_MIN} and {HEIGHT_MAX}.")
            else:
                return height

        except ValueError:
            print("Height must be an integer.")


# Print a right-aligned pyramid recursively
def print_pyramid(height, width):
    if width < 1:
        return

    print_pyramid(height, width-1)

    print(" " * (height - width) + "#" * width)


# Calls the main function
if __name__ == "__main__":
    main()
