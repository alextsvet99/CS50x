#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[3];

    people[0].name = "Carter";
    people[0].number = "123";

    people[1].name = "Dave";
    people[1].number = "123";

    people[2].name = "John";
    people[2].number = "567";

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s %s\n", name, people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
