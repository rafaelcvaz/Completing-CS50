# Get's a cash value from user and prints the minimum number of coins necessary to return this cash]

def main():
    print("Change: ", end = "")
    
    # Checks if the change is a number higher than 0
    while True:
        change = input()

        try:
            change = float(change)
            if change > 0:
                break

            else:
                print("Change: ", end = "")

        except ValueError:
            print("Change: ", end = "")

    
    change = int(float(change) * 100.0)
    print(f"Number of coins: {coins((change))}")


def coins(n):
    ncoins = 0
    while n > 0:
        if n >= 25:
            while n >= 25:
                ncoins += 1
                n -= 25
        elif n >= 10 and n < 25:
            while n >= 10:
                ncoins += 1
                n -= 10
        elif n >= 5 and n < 10:
            while n >= 5:
                ncoins += 1
                n -= 5
        elif n >= 1 and n < 5:
            while n >= 1:
                ncoins += 1
                n -= 1

    return ncoins

main()