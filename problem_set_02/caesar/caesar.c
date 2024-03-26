// Encrypt a message with a Caesar method

// Includes
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool is_int(string s);
string encrypt(string plaintext, int key);

// Main
int main(int argc, string argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./cesar key\n");
        return 1;
    }

    // Check the key is integer
    // Can't check with atoi() because it returns 0 in case of an error
    // and 0 in case the input was 0 - inconclusive results
    if (!is_int(argv[1]))
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }
    int key = atoi(argv[1]);

    // Prompt user for text
    string plaintext = get_string("plaintext:  ");

    // Encrypt
    string ciphertext = encrypt(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Checks input to be an integer
bool is_int(string s)
{
    int length = strlen(s);
    int start = 0;

    if (s[0] == '-' && length != 1)
        start = 1;

    for (int i = start; i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Encrypts the given text (supports negative keys)
string encrypt(string plaintext, int key)
{
    string ciphertext = plaintext;

    int length = strlen(plaintext);
    char c = plaintext[0];
    for (int i = 0; i < length; i++)
    {
        c = plaintext[i];
        if (c >= 'A' && c <= 'Z')
        {
            ciphertext[i] = 'A' + (26 + (c - 'A' + key) % 26) % 26;
        }
        else if (c >= 'a' && c <= 'z')
        {
            ciphertext[i] = 'a' + (26 + (c - 'a' + key) % 26) % 26;
        }
        else
        {
            ciphertext[i] = c;
        }
    }

    return ciphertext;
}
