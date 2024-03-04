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
        printf("Usage: ./substitution key");
        return 1;
    }
    int check_digits = 0;
    int key = 0;
    if (strlen(argv[1])!=26)
    {
        printf("Must contain 26 characters.");
        return 1;
    }
    for (int i = 0; i <26; i++){
        argv[1][i] = toupper(argv[1][i]);
    }
    for (int i = 0; i <26; i++){
        if (argv[1][i] < 65 || argv[1][i]>90){
            return 1;
        };
    }
    int N = 26;
    int letters[N];
    int count = 0;
    for (int j = 0; j<N; j++)
    {
        if (argv[1][count] == letters[j])
        {
            return 1;
        }
        letters[count] = argv[1][count];
    }
    string plaintext = get_string("Plaintext: \n");
    for (int i = 0; i<strlen(plaintext); i++){
        if((plaintext[i]>=65 && (plaintext[i]<=90)))
        {
            int b = plaintext[i] - 65;
            plaintext[i] = argv[1][b];
        }
        else if ((plaintext[i] >= 97) && (plaintext[i]<=122)){
            int b = toupper(plaintext[i]) - 65;
            plaintext[i] = tolower(argv[1][b]);
        }
        printf("ciphertext: %s\n", plaintext);
        }

}
