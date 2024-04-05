#include <cs50.h>
#include <stdio.h>

int factorial(int n);

int main(void)
{
    int n = -1;
    do
    {
        n = get_int("n: ");
    }
    while (n < 0);

    printf("!%i = %i\n", n, factorial(n));
}

int factorial(int n)
{
    if (n <= 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}
