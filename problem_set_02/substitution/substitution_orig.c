// Encrypt a message with a substitution method

// Includes
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Constants

// Global vars

// Function prototypes
string encrypt(string plaintext, int mapping_table[]);

// Main
int main(int argc, string argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./cesar key\n");
        return 1;
    }

    string key = argv[1];

    // Check the key
    if (strlen(key) != 26)
    {
        printf("The key must be 26 characters long.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("The key must contain letters only.\n");
            return 1;
        }
    }

    // Create mapping and appearence tables
    int mapping_table[26];
    int appearence_table[26];
    for (int i = 0; i < 26; i++)
    {
        mapping_table[i] = 0;
        appearence_table[i] = 0;
    }

    // Update mapping tabble
    for (int i = 0, c = key[0]; i < 26; i++)
    {
        c = toupper(key[i]);
        if (appearence_table[c - 'A'] == 0)
        {
            appearence_table[c - 'A'] = 1;
            mapping_table[i] = c - ('A' + i);
        }
        else
        {
            printf("Letters in the key cannot repeat.\n");
            return 1;
        }
    }

    // Prompt user for text
    string plaintext = get_string("plaintext:  ");

    // Encrypt
    string ciphertext = encrypt(plaintext, mapping_table);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Encrypts the given text
string encrypt(string plaintext, int mapping_table[])
{
    string ciphertext = plaintext;
    int length = strlen(plaintext);

    for (int i = 0, c = plaintext[0]; i < length; i++)
    {
        c = plaintext[i];

        if (c >= 'A' && c <= 'Z')
        {
            ciphertext[i] = c + mapping_table[c - 'A'];
        }
        else if (c >= 'a' && c <= 'z')
        {
            ciphertext[i] = c + mapping_table[c - 'a'];
        }
        else
        {
            ciphertext[i] = c;
        }
    }

    return ciphertext;
}
