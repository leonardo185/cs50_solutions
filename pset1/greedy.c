
// true program for greedy algorithm
#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    float money;
    int count;
    int leftover;

    do
    {
        printf("\n how much should you give?");
        money = get_float();
    }
    while(money<0);

    leftover=round(money*100);

    //for 25 cents
    count=leftover/25;
    count=round(count);
    leftover=leftover%25;

    //for 10 cents
    count=count + leftover/10;
    count=round(count);
    leftover=leftover%10;

    //for 5 cents
    count=count + leftover/5;
    count=round(count);
    leftover=leftover%5;

    //for 1 cent
    count = count + leftover;
    printf("%d\n", count);

}