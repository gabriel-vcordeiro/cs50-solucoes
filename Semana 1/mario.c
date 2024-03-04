#include <cs50.h>
#include <stdio.h>
int main(void)
{

    int height;
    do
    {
        height = get_int("Insert the height: ");
    }
    while (height<1);

    // Print a pyramid of that height
    int counter = 1;
    while (counter <= height) {
        int spaces = height - counter;
        for(int i = 0; i < spaces; i++) {
            printf(" ");
        }
        for(int i = 0; i < counter; i++) {
            printf("#");
        }
        printf("\n");
        counter++;
    }
}