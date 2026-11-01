#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 6
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    char hint[60];
} Anagram;

Anagram anagramBank[MAX_WORDS] = {
    {"PROGRAM", "Instructions sequence executing operations."},
    {"COMPILER", "Translates high-level statements to raw bytecode."},
    {"POINTER", "Variable storing raw memory addresses dynamically."},
    {"FUNCTION", "Modular reusable block processing data structures."},
    {"VARIABLE", "Named system allocation container referencing values."},
    {"ARRAY", "Contiguous indexed sequence elements configuration."}
};

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) str[i] = toupper((unsigned char)str[i]);
}

void scrambleWord(const char *input, char *output) {
    int len = strlen(input);
    strcpy(output, input);
    for (int i = len - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = output[i];
        output[i] = output[j];
        output[j] = temp;
    }
}

int main() {
    srand((unsigned int)time(NULL));
    int score = 0;
    char userGuess[MAX_WORD_LEN];
    char scrambled[MAX_WORD_LEN];
    
    printf("=========================================\n");
    printf("     WORD SMITH - TERMINAL EDITION       \n");
    printf("=========================================\n\n");
    
    for (int i = 0; i < MAX_WORDS; i++) {
        scrambleWord(anagramBank[i].word, scrambled);
        printf("Scrambled Word: %s\nHint: %s\n", scrambled, anagramBank[i].hint);
        printf("Enter guess (or 'SKIP'): ");
        if (scanf("%19s", userGuess) != 1) break;
        toUpperCase(userGuess);
        
        if (strcmp(userGuess, anagramBank[i].word) == 0) {
            printf(">> Correct! +10 Points\n\n");
            score += 10;
        } else {
            printf(">> Incorrect. Moving forward...\n\n");
        }
    }
    printf("GAME OVER! Final Score: %d\n", score);
    return 0;
}
