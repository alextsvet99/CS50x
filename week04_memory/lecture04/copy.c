#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    // NULL is "address zero"
    if (s == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1);
    // Check that there was enough memory to allocate
    if (t == NULL)
    {
        return 1;
    }

    // for (int i = 0, l = strlen(s); i <= l; i++)
    // {
    //     t[i] = s[i];
    // }
    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);
    // printf("%p\n", s);
    // printf("%p\n", t);

    free(t);
    return 0;
}
