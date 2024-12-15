// Transform a text so it becomes cryptographed using a key in caesar style.

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits (string s);
char convert (char c, int key);

int main (int argc, string argv[])
{

   // Checks for correct usage

   if (argc != 2 || !only_digits(argv[1])) // If the user doesn't type the correct number of arguments or if it only has digits.
   {
    printf("Usage: ./caesar key\n");
    return 1;
   }

   int key = atoi(argv[1]);

   string plaintext = get_string("plaintext: ");

   printf("cyphertext: ");

   // Prints char per char of the new cyphertext

   for (int i = 0, n = strlen(plaintext); i < n; i++)
   {
    printf("%c", convert(plaintext[i], key));
   }

   printf("\n");

   return 0;

}

// Checks if the given key is made only by digits
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i])) // Return false if any character is not a digit
        {
            return false;
        }
    }
    return true; // All characters are digits
}

// Converts each char of the plaintext in cyphertext using the provided key
char convert(char c, int key)
{
    if (islower(c))
    {
        return (char) (((c - 'a' + key) % 26) + 'a');
    }
    
    if (isupper(c))
    {
        return (char) (((c - 'A' + key) % 26) + 'A');
    }

    // Return non-alphabetic characters unchanged
    return c;
}
