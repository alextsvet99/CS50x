#include <cs50.h>
#include <stdio.h>

void print_row(int length);

int main(void)
{
    int height = get_int("Enter pyramid height (int): ");

    printf("Entered pyramid height: %i\n", height);

    for (int i = 0; i < height; i++)
    {
        print_row(i+1);
    }
}

void print_row(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%s", "#");
    }
    printf("\n");
}
