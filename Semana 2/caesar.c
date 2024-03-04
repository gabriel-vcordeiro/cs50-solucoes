#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    int check_digits = 0;
    int key = 0;
    for (int i = 0; i <strlen (argv[1]); i++)
    {
        if (isdigit(argv[1][i]))
        {
            check_digits++;
        }
    }

    if (check_digits == strlen(argv[1]))
    {
        key = atoi(argv[1]);
    }
    else
    {
        return 1;
    }
    while (key>=26)
    {
        key = key - 26;
    }

    string plaintext = get_string("Plaintext: \n");
    for (int i = 0; i <strlen(plaintext); i++)
    {
        if((plaintext[i]>=65 && (plaintext[i]<=90)) || ((plaintext[i] >= 97) && (plaintext[i]<=122))){
            if(toupper(plaintext[i])+key>90)
            {
                plaintext[i] = plaintext[i] + key - 26;
            }
            else{
                    plaintext[i] += key;
            }
        }
    }
    printf("ciphertext: %s\n", plaintext);
}
