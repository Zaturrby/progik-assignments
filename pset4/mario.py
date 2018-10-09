"""
mario.py

Programmeren IK
Robert-Jan Korteschiel
st. nr. 10399143

Usage: python mario.py height

A program that builds a wall, like the ones that Mario climbs over.
"""
# get input and ask again if invalid
height = -1
while height < 0 or height > 23:
    height = int(input("Height: "))

# build wall
for i in range(height):
    print(" " * (height - i - 1), "#" * (i + 2), sep="")