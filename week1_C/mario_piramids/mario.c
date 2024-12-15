// Prints a pyramid of blocks #.

#include <cs50.h>
#include <stdio.h>

// Function prototypes
void print_spaces(int count);
void print_blocks(int count);

int main(void)
{
    int height;

    // Prompt user for height until a valid input is given
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Build the pyramid row by row. I starded the counter at 1 because the number of blank spaces printed starts at height-1, so the loop goes until i == height.
    for (int i = 1; i <= height; i++)
    {
        // Print left spaces
        print_spaces(height - i);

        // Print left blocks
        print_blocks(i);

        // Print gap between the two pyramids
        printf("  ");

        // Print right blocks, it doesn't need the spaces at the right side.
        print_blocks(i);

        printf("\n"); // Move to the next line after each row
    }
}

// Function to print spaces
void print_spaces(int count)
{
    for (int j = 0; j < count; j++)
    {
        printf(" ");
    }
}

// Function to print blocks
void print_blocks(int count)
{
    for (int j = 0; j < count; j++)
    {
        printf("#");
    }
}
