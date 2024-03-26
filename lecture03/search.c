#include <cs50.h>
#include <stdio.h>
#include <string.h>

/*int main(void)
{
    int numbers[] = {20, 500, 10, 5, 500, 1, 50};

    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (n == numbers[i])
        {
            printf("Found at %i\n", i);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}*/

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thinmble", "top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
