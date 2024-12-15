# Calculates the level of complexity of a sentence based on the size of sentences and words.

def main():
    print("Text: ", end = "")
    sentence = input()

    index = calculate_level(sentence)

    # Calculate Grade Level based on index
    
    if index < 1:
        print("Before grade 1")
    elif index >= 1 and index < 16:
        print(f"Grade {index}")
    else:
        print("Grade 16+")
         

def calculate_level(text):

    letters = 0
    words = 1
    sentences = 0


    # Goes through each character, defining the number of letters, words and sentences
    for i in range(len(text)):
        if text[i].islower() or text[i].isupper():
            letters += 1
        elif text[i].isspace():
            words += 1
        elif text[i] == "." or text[i] == "!" or text[i] == "?":
            sentences += 1

    L = float(letters) / (0.01 * words)
    S = float(sentences) / (0.01 * words)
    index = round((0.0588 * L) - (0.296 * S) - 15.8)

    return index
    
main()
    
