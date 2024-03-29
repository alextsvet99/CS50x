// A scrabble game between two players

// Includes
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Constants
const int scoring_table[27] = {
//  0  A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q   R  S  T  U  V  W  X  Y  Z
    0, 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototypes
int score(string word);

// Main
int main(void)
{
    // Prompt for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score the words
    int score1 = score(word1);
    int score2 = score(word2);

    // Announce results
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Score the given word
int score(string word)
{
    int length = strlen(word);
    char c = 0;
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        c = word[i];

        // Check if uppercase, lowercase or not a letter
        if (c >= 65 && c <= 90)
        {
            c -= 64;
        }
        else if (c >= 97 && c <= 122)
        {
            c -= 96;
        }
        else
        {
            c = 0;
        }

        sum += scoring_table[(int) c];
    }
    return sum;
}
