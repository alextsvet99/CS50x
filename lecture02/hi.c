#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // char c1 = 'H';
    // char c2 = 'i';
    // char c3 = '!';

    // string s = "Hi!";
    // printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);

    // string t = "Bye!";

    string words[2];
    words[0] = "Hi!";
    words[1] = "Bye!";

    printf("%s\n", words[0]);
    printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);
}
