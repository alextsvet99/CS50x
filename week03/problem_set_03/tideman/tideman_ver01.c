#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
int winner_exists(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Populate the ranks array with candidate indeces
    // in the ranking order
    // Loop over candidates to find name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            // Record the rank
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // preferences[i][j] is the number of voters in whose ranks
    // i is higher than j (ith candidate is higher than jth candidate)
    // Loop over the ranks array
    for (int i = 0; i < candidate_count; i++)
    {
        // knowing that ranks[i] wins over the remaining candidates
        // Loop over remaining ranks
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Loop over prefernces and compare [i][j] to [j][i] to find
    // who is more preferred
    for (int i = 0; i < candidate_count; i++)
    {
        // It should be enough to look at the right half of the maxtrix only
        // because preferences[i][j] + preferences[j][i] = voter_count
        for (int j = i; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Sorting with the bubble sort algorithm (for no reason in particular)
    int swap_count = 0;
    int n_sorted = 1;
    pair cashed_pair;
    do
    {
        swap_count = 0;

        for (int i = 0; i < pair_count - n_sorted; i++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] <
                preferences[pairs[i + 1].winner][pairs[i + 1].loser])
            {
                cashed_pair = pairs[i];
                pairs[i] = pairs[i + 1];
                pairs[i + 1] = cashed_pair;
                swap_count++;
            }
        }

        n_sorted++;
    }
    while (swap_count);
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Loop over pairs
    for (int i = 0; i < pair_count; i++)
    {
        // Lock pair
        locked[pairs[i].winner][pairs[i].loser] = true;

        // If cycles exist
        if (winner_exists() == -1)
        {
            // Unlock pair
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
        // Else
        // Move on
    }
    return;
}

// Check for cycles in locked pairs, return -1 if a cycle exists or
// the index of a source candidate
int winner_exists(void)
{
    // Condition for non-existance of cycles:
    // at least 1 candidate has wins without losses
    // In matrix terms, a candidate has trues in rows
    // and no trues in columns
    int win_count, loss_count;
    int winner = -1;

    // Loop over candidates
    for (int i = 0; i < candidate_count; i++)
    {
        win_count = 0;
        loss_count = 0;

        // Check the whole row for wins (trues) and the whole column for losses  (also trues)
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j])
                win_count++;

            if (locked[j][i])
                loss_count++;
        }

        // Check if the candidate is ok
        if (win_count > 0 && loss_count == 0)
            winner = i;
        else if (win_count > 0 && loss_count > 1)
            return -1;
    }

    if (winner == -1)
        return -1;
    else
        return winner;
}

// Print the winner of the election
void print_winner(void)
{
    int winner = winner_exists();
    printf("%s\n", candidates[winner]);
    return;
}
