#include <cs50.h>
#include <stdio.h>

int main(void)
{   int change;
    do{
    change = get_int("Input the amount of money you will change:" );
    }
    while (change<0);
    int coins = 0;
    while (change>=25){
            change = change - 25;
            coins++;
        }
        while (change>=10){
            change = change - 10;
            coins++;
        }
        while (change>=5){
            change = change-5;
            coins++;
        }
        while (change>=1){
            change = change - 1;
            coins++;
        }
    printf("The amount of coins is: %i\n", coins);
    }


