/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <string.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Implementation of binary search using position information
 */

bool binarySearch(int value, int values[], int start, int end)
{
    // Determine middle and check
    int middle = (start + end) / 2;
    if (values[middle] == value)
    {
        return true;
    }
    if (end - start < 0)
    {
        return false;
    }
    // Select left part or right part
    if (value < values[middle])
    {
        return binarySearch(value, values, start, middle - 1);
    }
    else
    {
        return binarySearch(value, values, middle + 1, end);
    }
}

/**
 * Search through array with binary search
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int n)
{
    return binarySearch(value, values, 0, n);
}

/**
 * Sorts array of n values with counting sort
 */
void sort(int values[], int n)
{
    // Put values into buckets
    int buckets[65536] = {0};
    for (int i = 0; i < n; i++)
    {
        buckets[values[i]]++;
    }
    // Get the values out of the buckets
    for (int i = 0, next = 0; i < 65536; i++)
    {
        for (int j = 0; j < buckets[i]; j++, next++)
        {
            values[next] = i;
        }
    }
}