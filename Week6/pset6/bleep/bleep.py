from cs50 import get_string
import sys


def main():
    # Ensures proper usage
    if len(sys.argv) != 2:
        print("Usage: python bleep.py dictionary")
        sys.exit(1)

    # Stores the file containing the banned words and opens it
    banned_words = sys.argv[1]
    file = open(banned_words, "r")
    if not file:
        sys.exit(1)

    # Creates a set and storages the words contained in the file
    list_of_banned_words = set()
    for words in file:
        words = words[0:-1]
        list_of_banned_words.add(words)

    # Prompts the user for a message that will be censored
    message = input("What message would you like to censor?\n")
    message = message.split(" ")
    censor = ""
    for words in message:
        if check(words.lower(), list_of_banned_words):
            words = censorship(words)
        censor = censor + words + " "
    print(censor)
    # Closes the read file
    file.close()
    return 0

# Returns true if the word is in the list of banned words


def check(w, dictionary):
    counter = 0
    for words in dictionary:
        if len(words) == len(w):
            if words == w:
                return True
    return False


def censorship(w):
    word = ""
    for c in w:
        word = word + "*"
    return word


if __name__ == "__main__":
    main()
