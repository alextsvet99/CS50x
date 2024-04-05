// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Prototypes
bool locate_word(char *word, node *node_ptr);
bool add_to_table(int i, char *word);
unsigned int node_length(node *node_ptr);
void free_node(node *node_ptr);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Implement search across the hash table
    // But first change the word to all lowercase caracters
    char *word_lc = malloc(sizeof(char) * (LENGTH + 1));
    // This part is sipposed to terminate the program,
    // but it won't because main expects boolean by default
    // if (word_lc == NULL)
    // {
    //     return false;
    // }

    int i = 0;
    while (word[i] != 0)
    {
        word_lc[i] = tolower(word[i]);
        i++;
    }
    word_lc[i] = 0;

    // Compare the word and the table node corresponding to the word hash

    bool result = locate_word(word_lc, table[hash(word)]);

    // Release memory
    free(word_lc);

    return result;
}

bool locate_word(char *word, node *node_ptr)
{
    // Base case
    if (node_ptr == NULL)
    {
        return false;
    }

    // Compare the words
    // I think there's room for making use of the fact that the words are stored
    // in a reverse-alphabetical order
    // If they are the same
    if (strcmp(word, node_ptr->word) == 0)
    {
        // Then return found
        return true;
    }
    // If the word should have come before the current word
    else if (strcmp(word, node_ptr->word) > 0)
    {
        // Then the word cannot be in the list
        return false;
    }
    // Else
    else
    {
        // Keep looking
        return locate_word(word, node_ptr->next);
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *d = fopen(dictionary, "r");
    if (d == NULL)
    {
        return false;
    }

    // Implementation detail: assumes every word has length LENGTH + 1
    char *word = malloc(sizeof(char) * (LENGTH + 1));
    if (word == NULL)
    {
        return false;
    }

    // Read the dictionary word by word
    while (fscanf(d, "%s\n", word) != EOF)
    {
        // Hash each word
        // Place it into a hash table
        if (!add_to_table(hash(word), word))
        {
            return false;
        }
    }

    // Release memory ?
    // Free word if was copied in add_to_table()
    free(word);

    // Close files
    fclose(d);

    return true;
}

// Adds a word to the hash table
bool add_to_table(int i, char *word)
{
    // Create a node for the word
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        return false;
    }

    // Do I really need to copy here? Can't I just assign the pointer to the word?
    strcpy(new->word, word);
    new->next = NULL;

    // Add the word to the hash table
    // If there is not a word at the index
    if (table[i] == NULL)
    {
        // Add the word directly
        table[i] = new;
    }
    // Otherwise add a word to a linked list
    else
    {
        new->next = table[i];
        table[i] = new;
    }

    // Release memory ?
    // Nothing to free because new was reassigned

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Calculate the capacity of the hash table
    unsigned int s = 0;

    // Loop over the table
    for (int i = 0; i < N; i++)
    {
        // Calculate the length of a list in that node
        s += node_length(table[i]);
    }
    return s;
}

// Returns the length of the list associated with the given node
unsigned int node_length(node *node_ptr)
{
    // Base case
    if (node_ptr == NULL)
    {
        return 0;
    }

    // Get length of the brancn and increment it by one
    return node_length(node_ptr->next) + 1;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Loop over the hash table
    for (int i = 0; i < N; i++)
    {
        // Clean up every node
        free_node(table[i]);
    }
    return true;
}

// Free a node of the hash table
void free_node(node *node_ptr)
{
    // Base case
    if (node_ptr == NULL)
    {
        return;
    }

    // Recursively clean the subsequent nodes
    free_node(node_ptr->next);

    // Clean the node itself
    free(node_ptr);

    return;
}
