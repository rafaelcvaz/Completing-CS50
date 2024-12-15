// Asks for a credit card number and checks which type it is.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;
    long original_number;

    // Asks the user for input
    do
    {
        number = get_long("Number: ");
        original_number = number; // Store the original number for later use
    }
    while (number <= 0);

    int sum_odd = 0; // Sum of digits in odd positions (from right)
    int sum_even = 0; // Sum of digits in even positions (from right)
    int position = 0; // To track the position of digits

    while (number > 0)
    {
        int digit = number % 10; // Get the last digit
        if (position % 2 == 0) // Odd position (considering the rightmost position as 0)
        {
            sum_odd += digit;
        }
        else // Even position
        {
            int product = digit * 2;
            sum_even += (product / 10) + (product % 10); // Add the digits of the product
        }
        number /= 10; // Remove the last digit
        position++;
    }

    // Check if the card is valid
    if ((sum_odd + sum_even) % 10 != 0)
    {
        printf("INVALID\n");
        return 1;
    }

    // Reduces the original number to the first two digits
    while (original_number >= 100)
    {
        original_number /= 10; 
    }
    
    // Determine card type based on original number
        if (original_number == 34 || original_number == 37) // AMEX (starts with 34 or 37)
    {
        printf("AMEX\n");
    }
    else if ((original_number / 10) == 4) // VISA (starts with 4)
    {
        printf("VISA\n");
    }
    else if (original_number >= 51 && original_number <= 55) // MASTERCARD (starts with numbers between 51 and 55)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n"); // If it doesn't match any known type
    }

    return 0;
}
