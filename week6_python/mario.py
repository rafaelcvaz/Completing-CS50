# Asks the user how height and prints a piramid

def main():
    print("Height: ", end = "")
    height = input()
    while int(height) < 1 or int(height) > 8:
        print("Height: ", end = "")
        height = input()
    print_piramid(int(height))

    
def print_piramid(n):
    blocks = 1
    while n > 0:
        print(f" " * (n - 1), end = "")
        print(f"#" * blocks)
        n -= 1
        blocks += 1

main()