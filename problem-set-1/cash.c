#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change_owed;
    int cents;
    do
    {
        change_owed = get_float("Change Owed: ");
        cents = round(change_owed * 100);
    }
    while(change_owed < 0);
    int coins = 0;
    while(cents != 0)
    {
        // 25 cents
        coins += cents / 25;
        cents = cents % 25;
        // 10 cents
        coins += cents / 10;
        cents = cents % 10;
        // 5 cents
        coins += cents / 5;
        cents = cents % 5;
        // 1 cents
        coins += cents / 1;
        cents = cents % 1;
    }
    printf("%i\n", coins);
}
