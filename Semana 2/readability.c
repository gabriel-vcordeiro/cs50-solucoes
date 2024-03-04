#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calculate_score (string word, int scores[]);
int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Insert your word: \n");
    string word2 = get_string ("Insert your word: \n");
    int scores[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int score1 = 0;
    int score2= 0;
    // Compute the score of each word
    int a = calculate_score(word1, scores);
    int b = calculate_score(word2, scores);
    printf("Player 1 score: %i\n", a);
    printf("Player 2 score: %i\n", b);
    // Print the winner
    if (a >b)
    {
        printf("Player 1 wins!\n");
    }
    else if (b>a){
        printf("Player 2 wins!\n");
    }
    else{
        printf("Tie\n");
    }
}
int calculate_score (string word, int scores[]){
    int score = 0;
    for (int i = 0; i <strlen(word); i++)
    {
     char c = word[i];
     char b = toupper(c);
     int position = (int)b - 65;
     if (position>= 0 && position <25){
        score += scores[position];
    }}
    return score;
}
