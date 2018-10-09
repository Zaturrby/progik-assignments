/******************************************************************************
* initials.c
*
* Information Science - University of Amsterdam
* Robert-Jan Korteschiel
*
* Encode a string with caesar's algorithm
*
* Demonstrates simple string manipulations
******************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();
    // loop over string, check for spaces and convert the initials to uppercase
    for (int i = 0; i < strlen(name); i++)
    {
        if ((i == 0 || name[i - 1] == ' ') && isalpha(name[i]))
        {
            printf("%c", toupper(name[i]));
        }
    }
    printf("\n");
}