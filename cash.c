#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars; //input variable
    do
    {
        dollars = get_float("Change owed : ");
    }
    while (!(dollars >= 0));  //checking for non-negative

    int cents = round(dollars * 100);
    int coins = cents / 25;
    cents = cents % 25;
    coins += cents / 10;
    cents = cents % 10;
    coins += cents / 5;
    cents = cents % 5;
    coins += cents;
    printf("%d\n", coins);
}