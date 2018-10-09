"""
caesar.py

Programmeren IK
Robert-Jan Korteschiel
st. nr. 10399143

Usage: python caesar.py key

A program that shift letters by a key, providing primitive encryption.
"""

import sys

# check arguments
if len(sys.argv) is not 2:
    exit("usage: python caesar.py key")

text = input("plaintext: ")
print("ciphertext: ", end="")

# shift letters
for letter in text:
    if letter.isalpha():
        # get the ASCII value
        base = ord('a') if letter.islower() else ord('A')
        # calculate the shift
        letter = chr((ord(letter) - base + int(sys.argv[1])) % 26 + base)
    print(letter, end="")
print()