#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int scores[1024];
    bool *addresses = malloc(1024);
    if (addresses == NULL)
    {
        return 1;
    }

    for (int i = 0; i < 1024; i++)
    {
        // printf("%i\n", scores[i]);
        // printf("%p\n", &scores[i]);
        printf("%i\n", addresses[i]);
        // printf("%p\n", &addresses[i]);
    }

    free(addresses);
}
