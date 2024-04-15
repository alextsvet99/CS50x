#!/usr/bin/env python3

PENNY = 1
NICKEL = 5
DIME = 10
QUARTER = 25

coins = [QUARTER, DIME, NICKEL, PENNY]


def main():
    change = int(get_change() * 100)
    print(give_change(change))


# Asks user for change amount
def get_change():
    while True:
        try:
            change = float(input("Change: "))

            if change < 0:
                print("Change must be a positive number.")
            else:
                return change

        except ValueError:
            print("Change must be a float.")


# Returns the number of coins for the specified change
def give_change(change):
    n_coins = 0

    for coin in coins:
        if change <= 0:
            break

        n_coins += int(change / coin)
        change = change % coin

    return n_coins


# Calls the main function
if __name__ == "__main__":
    main()
