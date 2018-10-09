/******************************************************************************
* crack.c
*
* Information Science - University of Amsterdam
* Robert-Jan Korteschiel
*
* Retrieve the password associated with a crypt DES-encoded hash.
*
* Demonstrates the fundamentals of cryptography and slightly more complex
* string manipulations with modulo arithmetic.
******************************************************************************/

#define _XOPEN_SOURCE
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void crack(char *receivedHash)
{
    int depth = 4;
    char password[5];
    char offset[5];
    char salt[2] = { receivedHash[0], receivedHash[1] };
    int attempt = 0;
    int characters = 1;
    do
    {
        // construct a password
        for (int i = 0; i < characters; i++)
        {
            // each consecutive char runs 52 to the power of its place slower
            offset[i] = (attempt / (int) pow(52, i)) % 26;
            // and is converted to a letter
            password[i] = (((attempt % 52) < 26) ? 'A' : 'a') + offset[i];
        }
        attempt++;
        printf("%s\n", password);
        // reset the attempt count to zero if a new char is needed
        if (attempt >= pow(52, characters))
        {
            characters++;
            attempt = 0;
        }
    }
    // check the password, and quit if the search is too deep
    while (strcmp(crypt(password, salt), receivedHash) && characters <= depth);
    printf("%s\n", password);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: Wrong number of arguments, should be 1");
        return 1;
    }
    crack(argv[1]);
}
