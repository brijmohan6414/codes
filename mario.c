#include <cs50.h>
#include <stdio.h>

void left_side(int a, int b);
void right_side(int c);

int main(void)
{
    int n; // input variable
    do
    {
        n = get_int("Enter the height : ");
    }
    while (!(n >= 1 && n <= 8));

    for (int i = 1; i <= n; i++)
    {
        left_side(i, n); //left side pyramid
        printf("  ");   //spaces in betwwen
        right_side(i); //right side pyramid
        printf("\n");   //new line
    }
}
void left_side(int a, int b)
{
    for (int j = 1; j <= (b - a); j++)
    {
        printf(" ");
    }
    for (int j = 1; j <= a; j++)
    {
        printf("#");
    }
}
void right_side(int c)
{
    for (int j = 1; j <= c; j++)
    {
        printf("#");
    }
}
