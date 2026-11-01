#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold word and its hint
struct WordItem {
    char word[20];
    char hint[100];
};

// Function to scramble the letters of a word
void scrambleWord(char *word, char *scrambled) {
    int len = strlen(word);
    strcpy(scrambled, word);
    
    for (int i = 0; i < len; i++) {
        int r = rand() % len;
        char temp = scrambled[i];
        scrambled[i] = scrambled[r];
        scrambled[r] = temp;
    }
    
    if (strcmp(word, scrambled) == 0 && len > 1) {
        scrambleWord(word, scrambled);
    }
}

int main() {
    struct WordItem wordList[] = {
        {"PLANET", "A large body orbiting a star (General/Space)"},
        {"GALAXY", "A massive system of stars and dust (Space)"},
        {"GRAVITY", "The force that pulls objects toward Earth (Science)"},
        {"OXYGEN", "Gas we need to breathe to live (Science)"},
        {"GUITAR", "A musical instrument with strings (General)"},
        {"PYTHON", "A popular programming language or a snake (Tech/General)"},
        {"COFFEE", "A popular morning caffeinated drink (General)"},
        {"JUPITER", "The largest planet in our solar system (Space)"},
        {"VOLCANO", "A mountain that erupts with lava (General/Science)"},
        {"LAPTOP", "A portable personal computer (Tech)"}
    };
    
    int totalWords = 10;
    int score = 0;
    char guess[20];
    char scrambled[20];
    
    srand(time(0));
    
    // Shuffle all words so we never get duplicates in a session
    for (int i = totalWords - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct WordItem temp = wordList[i];
        wordList[i] = wordList[j];
        wordList[j] = temp;
    }
    
    printf("========================================\n");
    printf("      WELCOME TO WORDSMITH ANAGRAM      \n");
    printf("========================================\n");
    printf("Guess the mixed words using the hints!\n\n");
    
    // Play 5 rounds with guaranteed unique words
    for (int round = 1; round <= 5; round++) {
        scrambleWord(wordList[round - 1].word, scrambled);
        
        printf("--- Round %d ---\n", round);
        printf("Scrambled Word: %s\n", scrambled);
        printf("Hint: %s\n", wordList[round - 1].hint);
        printf("Your Guess: ");
        
        scanf("%s", guess);
        
        if (strcmp(guess, wordList[round - 1].word) == 0) {
            printf(" Correct! +10 Points\n\n");
            score += 10;
        } else {
            printf(" Wrong! The correct word was: %s\n\n", wordList[round - 1].word);
        }
    }
    
    printf("========================================\n");
    printf("      GAME OVER! Final Score: %d / 50   \n", score);
    printf("========================================\n");
    
    return 0;
}
