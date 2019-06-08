#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("\nminuits: "); //enter time in minuits
    float x = get_float();

    float y =  x*1.5*128; //to find number of ounce
    float z = y/16; //to find number of bottles

    printf("\nbottles: %0.1f",z);

}