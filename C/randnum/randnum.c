/*
 * Number Guessing Game
 * 
 * To compile: gcc randnum.com -o randnum
 *  
 * ToDo:
 *    - Add difficulty choice (Easy, Normal, Hard)
 *    - Scoring
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number gen
    srand(time(NULL));

    int guesses = 0; // Number of guesses
    int diff = 0; // Game difficulty
    printf("Select game difficulty (1: Easy, 2: Normal, 3: Hard): ");
    scanf("%d", &diff);

    // Set number of allowable guesses based on chosen difficulty
    switch(diff) {
       case(1):
          guesses = 10;
          break;
       case(2):
          guesses = 5;
          break;
       case(3):
          guesses = 3;
          break;
       default:
          printf("Invalid difficulty, please try again!\n");
          return 0;
    }

    int guess; // User guess
    int rand_num = rand() % 100 + 1; // Generate a random number between 1 & 100

    //printf("I'm thinking of a number, you have %d guesses! %d\n", guesses, rand_num);
    printf("I'm thinking of a number, you have %d guesses!\n", guesses);
    do {
        printf("Make a guess: ");
        scanf("%d", &guess);

        // Check if the guess equals the random number or not
        if (guess != rand_num) {
            printf("\nTry again!\n");

            // Decrement the number of guesses by one
            guesses--;
        } else {
            // If the guess was correct, print congratulations and exit the program
            printf("\nCongratulations! You guessed correctly!\n");
            printf("Thanks for playing!\n");
            return 0;
        }

        // If guess is higher than the random number
        if (guess > rand_num) {
            printf("Too high! Try a smaller number...\n");
        }

        // If guess is lower than the random number
        if (guess < rand_num) {
            printf("Too low! Try a bigger number...\n");
        }
    } while (guesses > 0);

    printf("Game over, you ran out of guesses!\n");
    printf("The correct number was: %d\n", rand_num);

    return 0;
}
