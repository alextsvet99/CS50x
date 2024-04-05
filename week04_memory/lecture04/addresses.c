// #include <cs50.h>
#include <stdio.h>

int main(void)
{
    // int n = 50;
    // int *p = &n; // declaring a pointer

    // printf("%i\n", n);
    // printf("%p\n", &n);
    // printf("%p\n", p);
    // printf("%i\n", *p); // going to the pointer

    // string s = "Hi!";
    // printf("%s\n", s);
    // printf("%p\n", s);
    // printf("%p\n", &s[0]);
    // printf("%p\n", &s[1]);
    // printf("%p\n", &s[2]);

    char *s = "Hi!";
    printf("%s\n", s);
    // printf("%c\n", s[0]); // "syntactic sugar"
    // printf("%c\n", s[1]);
    // printf("%c\n", s[2]);
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}
