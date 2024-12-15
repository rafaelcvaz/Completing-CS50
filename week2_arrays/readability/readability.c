// Calculates the level of complexity of a sentence based on the size of sentences and words.

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main (void)
{
    string sentence = get_string("Text: ");

    int letters = 0;
    int words = 1; // Because this code will count the number of words considering the number of spaces, but the last word won't have a space after it.
    int sentences = 0;

    // Goes through each character and look for letters, words and sentences.

    for (int i = 0, n = strlen(sentence); i < n; i++)
    {
        if (isupper(sentence[i]) || islower(sentence[i]))
        {
            letters++;
        }
        else if (isspace(sentence[i]))
        {
            words++;
        }
        else if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            sentences++;
        }
    }

    // Calculate L and S (parameters for calculating the final index that determines the complexity of the text)

    float L = (float) letters / (0.01 * words);
    float S = (float) sentences / (0.01 * words);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int final_index = round(index);

    if (final_index < 1)
    {
        printf ("Before grade 1\n");
    }
    else if (final_index >= 1 && final_index < 16)
    {
        printf ("Grade %i\n", final_index);
    }
    else
    {
        printf ("Grade 16+\n");
    }

    return 0;

}

