#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void clear_winners(string winners[], int n);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Find name in the candidate list (assuming the name appears only once)
    // Linear search is better than binary search because
    // a) MAX number of candidates is low;
    // b) the list is not sorted;
    // b+) sorting is not worth the effort beacause a).
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Update their vote count
            candidates[i].votes++;
            return true;
        }
    }
    // If not found return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Find the highest number of votes
    int max_votes = -1;
    string winners[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        winners[i] = "None"; // replace garbage value

        if (candidates[i].votes > max_votes)
        {
            clear_winners(winners, i);
            winners[i] = candidates[i].name;
            max_votes = candidates[i].votes;
        }
        else if (candidates[i].votes == max_votes)
        {
            // strcat(winner, "\n");
            // strcat(winner, candidates[i].name);
            winners[i] = candidates[i].name;
        }
    }

    // Print results
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(winners[i], "None") != 0)
            printf("%s\n", winners[i]);
    }

    return;
}

// Clear the list of winners
void clear_winners(string winners[], int n)
{
    for (int i = 0; i < n; i++)
    {
        winners[i] = "None";
    }
}
