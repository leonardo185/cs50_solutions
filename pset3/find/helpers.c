/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

 bool binarysearch(int value, int values[], int n)
{
    int first=0;
    int last=n-1;
    int middle;

     int c=0;
     while(first<last)
        {
            middle=(first+last)/2;

           if(values[middle]<value)
           {
               first=middle+1;
           }
           else if(values[middle]>value)
           {
               last=middle-1;
           }
           else
           {
            c=1;
            return true;
           }
        }

        return false;
}

void bubblesort(int values[], int n)
{

    int i,j,temp;

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {

            if(values[i]<values[j])
            {
                temp=values[i];
                values[i]=values[j];
                values[j]=temp;

            }

        }

    }

    return;
}

bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    // BINARY SEARCH

    if(value<0)
    {
       return false;
    }
    else
    return binarysearch(value, values, n);

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // bubble sort

    bubblesort(values, n);
    return;
}



