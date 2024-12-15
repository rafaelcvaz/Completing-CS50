# Asks the user for a credit card number and prints if it's valid and what type of card it is

def main():
    print("Number: ", end = "")
    number = input()

    while len(number) < 13 or len(number) > 16:
        print("The credit card number must have between 13 and 16 digits")
        print("Number: ", end = "")
        number = input()

    number = int(number)

    check_card(number)


def check_card(n):
    original_n = n

    # Calculate Luhn’s Algorithm
    sum_odd = 0
    sum_even = 0
    position = 0

    while n > 0:

        digit = n % 10
        if position % 2 == 0:
            sum_odd += digit
        else:
            product = digit * 2
            sum_even += (product // 10) + (product % 10) 
        n = n // 10
        position += 1

    
    # Checks to see if the card is valid
    if (sum_even + sum_odd) % 10 != 0:
        print("INVALID")
    else:
        while original_n >= 100:
            original_n = original_n // 10
    
        # Checks type of card
        if original_n == 34 or original_n == 37:
            print("AMEX")
        elif original_n // 10 == 4:
            print("VISA")
        elif original_n >= 51 and original_n <= 55:
            print("MASTERCARD")
        else:
            print("INVALID")





main()