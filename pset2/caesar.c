/******************************************************************************
* caesar.c
*
* Information Science - University of Amsterdam
* Robert-Jan Korteschiel
*
* Encode a string with caesar's algorithm
*
* Demonstrates simple string manipulations and modulo arithmatic
******************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // handle and convert arguments
    if (argc != 2)
    {
        return 1;
    }
    int key = atoi(argv[1]);
    printf("plaintext: ");
    string text = get_string();
    // shift the text if alpha
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            int base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + key) % 26 + base;
        }
    }
    printf("ciphertext: %s\n", text);
}