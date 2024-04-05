#include <stdio.h>
#include <stdlib.h>

// Define a node
typedef struct node
{
    char *phrase;
    struct node *next;
} node;

int main(void)
{
    // Start building a list
    node *list = NULL;

    // Create the first node
    node *n = malloc(sizeof(node));
    n->phrase = "Hi!";
    n->next = NULL;

    // Update the list
    list = n;

    // Inserting new nodes
    n = malloc(sizeof(node));
    n->phrase = "Hey!";
    n->next = list;
    list = n;

    // Releasing memory
    node *ptr = list->next;
    free(list);

    list = ptr;
    ptr = list->next;
    free(list);

    list = ptr;
    // Is NULL actually: try running valgrind ./list
}
