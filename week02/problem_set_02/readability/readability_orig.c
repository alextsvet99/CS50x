// Estimate a reading level

// Includes
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes

// Main
int main(void)
{
    // Prompt user for text
    string text = get_string("Enter text: ");

    // Count letters, words, sentences, punctuation, other symbols
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int spaces = 0;
    int punctuation = 0;
    int other = 0;

    int length = strlen(text);
    char c = 0;
    for (int i = 0; i < length; i++)
    {
        c = text[i];
        // If a letter, space, punctuation, other
        if (isalpha(c))
        {
            letters++;
        }
        else if (c == ' ')
        {
            spaces++;
            if (text[i-1] != ' ')
                words++;
        }
        else if (c == ',' || c == ';' || c == ':' || c == '-')
        {
            punctuation++;
        }
        else if (c == '.' || c == '!' || c == '?')
        {
            punctuation++;
            if (!(text[i-1] == '.' || text[i-1] == '!' || text[i-1] == '?'))
            {
                sentences++;
            }
        }
        else
        {
            other++;
        }
    }

    char last_char = text[length - 1];

    if (last_char != ' ')
        words++;

    /*if (!(last_char == '.' || last_char == '!' || last_char == '?'))
        sentences++;*/

    // Results
    /*printf("Processed %i out of %i symbols\n", (letters + spaces + punctuation + other), length);
    printf("Detected:\n  %i letters\n  %i words\n  %i sentences\
    \n  %i spaces\n  %i punctuation symbols\n  %i other symbols\n",
    letters, words, sentences, spaces, punctuation, other);*/

    // Estimate level
    float L = 100.0 * letters / words;
    float S = 100.0 * sentences / words;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    // printf("L=%f S=%f index=%f\n", L, S, index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16.5)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}
