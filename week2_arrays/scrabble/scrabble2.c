// Calculates a score for each word the user types and defines a winner.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int ALPHA_SIZE = 26;
const int SCORES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_score(string word);

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Calculate scores for both players
    int score1 = calculate_score(player1);
    int score2 = calculate_score(player2);

    // Determine the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Calculate the score of a word
int calculate_score(string word)
{
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        char c = tolower(word[i]); // Convert character to lowercase

        if (isalpha(c)) // Check if the character is alphabetic
        {
            // Calculate the index based on the character
            int index = c - 'a'; // Get index from 'a' to 'z'
            score += SCORES[index]; // Add corresponding score
        }
    }

    return score;
}
