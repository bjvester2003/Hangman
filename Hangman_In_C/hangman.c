#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>

#define MAX_TRIES 6

char*words[10] = {
    "programming",
    "computer",
    "keyboard",
    "hangman",
    "algorithm",
    "variable",
    "function",
    "pointer",
    "array",
    "language"
};

void displayHangman(int tries) {

    printf("\n\n");
    printf("  +--+\n");
    printf("  |  |\n");

    switch (tries)
    {
    case 0:
        printf("     |\n");
        printf("     |\n");
        printf("     |\n");
        break;
    
    case 1:
        printf("  o  |\n");
        printf("     |\n");
        printf("     |\n");
        break;
    
    case 2:
        printf("  o  |\n");
        printf("  |  |\n");
        printf("     |\n");
        break;
        
    case 3:
        printf(" \\o  |\n");
        printf("  |  |\n");
        printf("     |\n");
        break;

    case 4:
        printf(" \\o/ |\n");
        printf("  |  |\n");
        printf("     |\n");
        break;
    
    case 5:
        printf(" \\o/ |\n");
        printf("  |  |\n");
        printf(" /   |\n");
        break;

    case 6:
        printf(" \\o/ |\n");
        printf("  |  |\n");
        printf(" / \\ |\n");
        break;
    }
    printf("     |\n");
    printf(" +---+---+\n");
    printf("\n");
}

int main()
{
    srand(time(NULL));

    char word[50];
    char guessed[50];

    int wordLen, tries=0, i, correctGuess=0;

    // Select random word from the 'words' array and assign to 'word'
    strcpy(word, words[rand()%10]);
    wordLen = strlen(word);

    printf("%s\n", word);

    //initialize guessed array
    for(i=0;i<wordLen;i++)
    {
        guessed[i]='_';
    }
    guessed[wordLen] = '\0';

    printf("\nWelcome to Hangman!\n");
    printf("Guess the word: %s\n", guessed);

    while(tries < MAX_TRIES)
    {
        char guess;
        printf("\nEnter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        int found = 0;
        for(i=0;i<wordLen;i++)
        {
            if (word[i]==guess && guessed[i] != guess)
            {
                guessed[i]=guess;
                found = 1;
            }
        }
        
        if(!found)
        {
            tries++;
            displayHangman(tries);
            printf("Incorrect guess! %d tries left\n", MAX_TRIES-tries);
        } else {
            printf("correct guess!\n");
        }
        printf("word : %s\n", guessed);

        if(correctGuess == wordLen)
        {
            printf("congratulations! you have guessed the word: %s\n", word);
            break;
        }
    }
    if (tries == MAX_TRIES)
    {
        printf("Sorry, you have run out of tries. The word was: %s\n", word);
        displayHangman(tries);
    }
    return 0;
}