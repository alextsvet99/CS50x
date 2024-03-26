#include <stdio.h>
#include <cs50.h>

void pi(int n);

int main(void)
{
    printf("hello, world\n");

    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);

    int height = get_int("How tall are you (in cm), %s? ", name);
    if (height < 185)
    {
        printf("Wow, you're short!\n");
    }
    else if (height > 185)
    {
        printf("Wow, you're tall!\n");
    }
    else
    {
        printf("Wow, same as me!\n");
    }

    int counter = 0;
    printf("%i\n", counter);
    counter = counter + 1;
    printf("%i\n", counter);
    counter += 1;
    printf("%i\n", counter);
    counter++;
    printf("%i\n", counter);

    while (counter > 0)
    {
        printf("Meow!\n");
        counter -= 1;
    }

    while (counter <= 3)
    {
        printf("Woof!\n");
        counter++;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Caw!\n");
    }

    pi(5);

}

void pi(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Pi!\n");
    }
}
