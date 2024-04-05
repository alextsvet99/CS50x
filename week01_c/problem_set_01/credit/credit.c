// Checks validity of a credit card number

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int check_input(long card_number);
bool check_number(long card_number, int n_digits);
string check_vendor(long card_number, int n_digits);

int main(void)
{
    // Prompt user for card number
    long card_number = 0;
    int n_digits = 0;

    /*
    do
    {
        card_number = get_long("Enter card number: ");
        n_digits = check_input(card_number);
    }
    while (!n_digits);
    */

    card_number = get_long("Enter card number: ");
    n_digits = check_input(card_number);

    // printf("Received card number: %li\n", card_number);
    // printf("Number of digits: %i\n", n_digits);

    // Check card number validity
    if (check_number(card_number, n_digits))
    {
        // Determine vendor
        printf("%s\n", check_vendor(card_number, n_digits));
    }
    else
    {
        printf("INVALID\n");
    }
}

// Returns the number of digits
int check_input(long card_number)
{
    int mod12 = card_number / pow(10, 12);
    // printf("mod12 = %i\n", mod12);

    if (mod12 > 0 && mod12 < 10)
    {
        return 13;
    }
    else if (mod12 > 99 && mod12 < 1000)
    {
        return 15;
    }
    else if (mod12 > 999 && mod12 < 10000)
    {
        return 16;
    }
    else
    {
        return 0;
    }
}

// Checks if the card number is valid
bool check_number(long card_number, int n_digits)
{
    int odd_digits, even_digits;
    int summ_odd_digits = 0;
    int summ_even_digits = 0;
    for (int i = 0; i < n_digits; i += 2)
    {
        odd_digits = card_number % (long) pow(10, i + 1) / (long) pow(10, i);
        even_digits = card_number % (long) pow(10, i + 2) / (long) pow(10, i + 1);
        // printf("%i     %i\n", odd_digits, even_digits);
        // printf("%i: ", even_digits * 2);
        // printf("%i %i\n", (2 * even_digits) / 10, (2 * even_digits) % 10);

        summ_odd_digits += odd_digits;
        summ_even_digits += (even_digits * 2) / 10 + (even_digits * 2) % 10;
        // printf("%i     %i\n", summ_odd_digits, summ_even_digits);
    }

    int summ = summ_odd_digits + summ_even_digits;
    // printf("%i\n", summ);

    if (summ % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Returns the vendor of the card
string check_vendor(long card_number, int n_digits)
{
    int starting_dig = 0;
    string answer = "INVALID";

    switch (n_digits)
    {
        case 13:
            starting_dig = card_number / pow(10, 12);
            // printf("Starting digits: %i\n", starting_dig);
            if (starting_dig == 4)
                answer = "VISA";
            break;

        case 15:
            starting_dig = card_number / pow(10, 13);
            // printf("Starting digits: %i\n", starting_dig);
            if (starting_dig == 34 || starting_dig == 37)
                answer = "AMEX";
            break;

        case 16:
            starting_dig = card_number / pow(10, 14);
            // printf("Starting digits: %i\n", starting_dig);
            if (starting_dig >= 51 && starting_dig <= 55)
            {
                answer = "MASTERCARD";
            }
            else if (starting_dig / 10 == 4)
            {
                answer = "VISA";
            }
            break;

        default:
            break;
    }

    return answer;
}
