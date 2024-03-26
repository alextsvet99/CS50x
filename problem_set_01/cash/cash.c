// Calculate the least number of coins to give change

#include <cs50.h>
#include <stdio.h>

void calc_change(int value, int *change_left, int *n_coins);

int main(void)
{
    // Prompt for change amount
    int change = 0;
    do
    {
        change = get_int("Enter change amount (cents, positive integer): ");
    }
    while (change < 0);

    int change_left = change;

    // Calculate the number of quarters
    int quarters = 0;
    calc_change(25, &change_left, &quarters);

    // Calculate the number of dimes
    int dimes = 0;
    calc_change(10, &change_left, &dimes);

    // Calculate the number of nickels
    int nickels = 0;
    calc_change(5, &change_left, &nickels);

    // Calculate the number of pennies
    int pennies = 0;
    calc_change(1, &change_left, &pennies);

    // Print result
    int n_coins_total = quarters + dimes + nickels + pennies;
    printf("%i\n", n_coins_total);
}

// Calculate change from change_left using coins of value value
void calc_change(int value, int *change_left, int *n_coins)
{
    if (*change_left >= value)
    {
        *n_coins = *change_left / value;
        *change_left = *change_left % value;
    }
}
