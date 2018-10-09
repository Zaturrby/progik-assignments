#include <cs50.h>
#include <stdio.h>

int luhnsCheck(long long creditcard);
string typeCheck(long long creditcard);

int main(void)
{
    printf("Creditcard Number: ");
    long long creditcard = get_long_long();
    // Check for Luhn and display the result
    if (luhnsCheck(creditcard) == 0)
    {
        // Get the type (returns INVALID if unknown)
        string type = typeCheck(creditcard);
        printf("%s\n", type);
    }
    else
    {
        printf("INVALID\n");
    }
}

int luhnsCheck(long long creditcard)
{
    long long result = creditcard;
    int multipliedDigits = 0;
    int addedDigits = 0;
    // Loop over the digits
    for (int i = 0; result > 0; i++)
    {
        // Get the current digit
        int rest = result % 10;
        // Test for odd or even
        if (i % 2)
        {
            // Combine the digits if two and add them
            if (rest * 2 < 10)
            {
                multipliedDigits += rest * 2;
            }
            else
            {
                multipliedDigits += rest * 2 % 10 + rest * 2 / 10;
            }
        }
        else
        {
            addedDigits += rest;
        }
        result /= 10;
    }
    return (multipliedDigits + addedDigits) % 10;
}

string typeCheck(long long creditcard)
{
    // Determine the length of the integer and the first two numbers
    int secondDigit = 0;
    int firstDigit = 0;
    int length = 0;
    for (length = 0; creditcard > 0; length++)
    {
        secondDigit = firstDigit;
        firstDigit = creditcard % 10;
        creditcard /= 10;
    }
    int firstTwoDigits = firstDigit * 10 + secondDigit;
    // Test for the first two digits (amex and mastercard)
    // Setting INVALID upfront because of double case statement
    string type = "INVALID";
    switch (firstTwoDigits)
    {
        case 34:
        case 37:
            if (length == 15)
            {
                type = "AMEX";
            }
            break;
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            if (length == 16)
            {
                type = "MASTERCARD";
            }
            break;
    }
    // Test for the first digit only (visa)
    switch (firstDigit)
    {
        case 4:
            if (length == 13 || length == 16)
            {
                type = "VISA";
            }
            break;
    }
    return type;
}
