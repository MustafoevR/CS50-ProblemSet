#include <cs50.h>
#include <stdio.h>
#include <string.h>

// preferences[i][j] is jth preference for voter i
int preferences[100][9];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[9];

// Numbers of voters and candidates
int voter_count;  // Global variable
int candidate_count; // Global variable

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > 9)
    {
        printf("Maximum number of candidates is %i\n", 9);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false; // So far no one has been eleminated
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > 100)
    {
        printf("Maximum number of voters is %i\n", 100);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void) // Important take a closer look !!!!!!!!
{
    // TODO
    for(int i = 0; i < voter_count; i++) // I am not sure it will work as I presume it to work
    {
        for(int j = 0; j < candidate_count; j++)
        {
            int pref_index = preferences[i][j];
            if(!candidates[pref_index].eliminated)
            {
                candidates[pref_index].votes++;
                break;
            }
        }
    }
    return;s
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int min = 100;
    for(int i = 0; i < candidate_count; i++)
    {
        if(!candidates[i].eliminated && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        if(!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
