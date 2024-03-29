#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string phrase = get_string("Enter a phrase: ");
    // int length = strlen(phrase);
    for (int i = 0, length = strlen(phrase) - 1; i < length; i++)
    {
        // printf("%i\n", phrase[i]);
        if (phrase[i] > phrase[i + 1])
        {
            printf("Not in alphabetical order.\n");
            return 0;
        }
    }
    printf("In alphabetical order.\n");
    return 0;
}
