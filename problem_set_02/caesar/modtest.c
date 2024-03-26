#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = get_int("int: ");
    printf("%i\n", a % 26);
}
