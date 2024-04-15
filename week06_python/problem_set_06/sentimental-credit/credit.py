#!/usr/bin/env python3

import re
from math import pow


def main():
    # Get the card number
    number = get_number()

    # Test for card validity
    if not test_luhn(int(number), len(number)):
        print("INVALID")
        return 1

    # Test for card vendor
    AMEX = re.compile(r"^3[47][0-9]{13}\Z")
    MASTERCARD = re.compile(r"^5[1-5][0-9]{14}\Z")
    VISA1 = re.compile(r"^4[0-9]{12}\Z")
    VISA2 = re.compile(r"^4[0-9]{15}\Z")

    if AMEX.match(number):
        print("AMEX")

    elif MASTERCARD.match(number):
        print("MASTERCARD")

    elif VISA1.match(number) or VISA2.match(number):
        print("VISA")

    else:
        print("INVALID")

    return 0


# Asks user for card number
def get_number():
    while True:
        s = input("Number: ")
        if s != "":
            return s


# Test a given number for satisfying the Luhn's algorithm
def test_luhn(number, length):
    odd_digits = even_digits = 0
    sum_odd_digits = sum_even_digits = 0

    for i in range(0, length, 2):
        odd_digits = int(number % pow(10, i + 1) / pow(10, i))
        even_digits = int(number % pow(10, i + 2) / pow(10, i + 1))

        sum_odd_digits += odd_digits
        sum_even_digits += int(even_digits * 2 / 10) + even_digits * 2 % 10

    if (sum_odd_digits + sum_even_digits) % 10 == 0:
        return True
    else:
        return False


# Calls main
if __name__ == "__main__":
    main()
