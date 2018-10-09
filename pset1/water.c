#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Promt the user
    printf("Minutes: ");
    int minutes = get_int();
    // print and calculate the value
    printf("Bottles: %i\n", minutes * 12);
}
