#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./cla number\n");
        return 1;
    }
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%i] is %i\n", i, atoi(argv[i]));
    }
}
