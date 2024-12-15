// Calculates a score for each word the user types and defines a winner.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int ALPHA_SIZE = 26;
const int SCORES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const char CHARS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


string fixcase (string player);
int calculate_scores (string player, int score);

int main (void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    player1 = fixcase(player1);
    player2 = fixcase(player2);

    int score1 = 0;
    int score2 = 0;

    score1 = calculate_scores (player1, score1);
    score2 = calculate_scores (player2, score2);


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

// Converts the uppercase letters to lowercase so we can compare every char
string fixcase (string player)
{
    for (int i = 0, n = strlen(player); i < n; i++)
    {
        if (isupper(player[i]))
        {
            player[i] = tolower(player[i]);
        }
    }
    return player;
}

int calculate_scores (string player, int score)
{
    for (int i = 0, n = strlen(player); i < n; i++)
    {
        for (int j = 0; j < ALPHA_SIZE; j++)
        {
            if (player[i] == CHARS[j])
            {
                score = score + SCORES[j];
            }
        }

    }
    return score;
}
