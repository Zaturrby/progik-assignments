#include <cs50.h>
#include <stdio.h>

void stones(int i)
{
    // Print the stones
    for (int j = 0; j < i + 1; j++)
    {
        printf("#");
    }
}

int main(void)
{
    // Get input and validate it
    signed int height = -1;
    while (height < 0 || height > 23)
    {
        printf("Height: ");
        height = get_int();
    }
    // Build the entire pyramid by looping over the height
    for (int i = 0; i < height; i++)
    {
        // Print the spaces
        for (int j = height - i - 2; j >= 0; j--)
        {
            printf(" ");
        }
        // Print stones, spaces in between, and the newline
        stones(i);
        printf("  ");
        stones(i);
        printf("\n");
    }
}
