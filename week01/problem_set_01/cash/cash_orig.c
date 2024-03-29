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
        change = get_int("Enter change amount (positive integer): ");
    }
    while (change < 0);

    printf("Received required change amount: %i\n", change);

    int change_left = change;

    /*
    // Calculate the number of quarters
    int quarters = 0;
    if (change_left > 24)
    {
        quarters = change_left / 25;
        change_left = change_left % 25;
    }
    printf("Quarters: %i\n", quarters);
    printf("Change left: %i\n", change_left);
    */

    // Calculate the number of quarters
    int quarters = 0;
    calc_change(25, &change_left, &quarters);
    printf("Quarters: %i\n", quarters);
    printf("Change left: %i\n", change_left);

    // Calculate the number of dimes
    int dimes = 0;
    calc_change(10, &change_left, &dimes);
    printf("Dimes: %i\n", dimes);
    printf("Change left: %i\n", change_left);

    // Calculate the number of nickels
    int nickels = 0;
    calc_change(5, &change_left, &nickels);
    printf("Nickels: %i\n", nickels);
    printf("Change left: %i\n", change_left);

    // Calculate the number of pennies
    int pennies = 0;
    calc_change(1, &change_left, &pennies);
    printf("Pennies: %i\n", pennies);
    printf("Change left: %i\n", change_left);

    // Check result
    int n_coins_total = quarters + dimes + nickels + pennies;
    int change_given = quarters * 25 + dimes * 10 + nickels * 5 + pennies * 1;
    if (change_given == change)
    {
        printf("Total number of coins: %i\n", n_coins_total);
    }
    else
    {
        printf("An error has occured! Please check the program.");
    }
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
