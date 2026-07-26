/*
 * Java Hangman Game - HangmanGame.java
 *
 * Main code file for my simple Swing Hangman game.
 *
 * Date created: 11 July 2026 16:06
 * Date modified: 11 July 2026 19:19
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 *
 */

import java.util.*;

public class HangmanGame {
    public static String secretWord = "TRANSISTOR"; // Secret word to guess
    public static String concealedWord = "";        // Concealed word to be revealed 
    public static ArrayList<Character> concealedArr = new ArrayList<Character>();   // Concealed char array
    public static int guesses = 10;     // Number of guesses remaining
    public static int correctHits = 0;  // Used to track if a guess is correct

    public static void main(String[] args) {
        // Set the concealedArr array to all underscores characters
        for (int i=0; i<secretWord.length(); i++) {
            concealedArr.add('_');
        }

        Scanner scanner = new Scanner(System.in);

        // Do this loop while the concealedWord string does not equal secretWord
        do {
            // Reset correctHits to 0
            correctHits = 0;

            // Check if we have run out of guesses, if so, exit the game
            if (guesses == 0) {
                System.out.println("Game over!");
                System.exit(0);
            }

            // Read in a character from the terminal, call makeGuess() with the character
            char testChar = scanner.next().toUpperCase().charAt(0);
            makeGuess(testChar);

            // Deduct a guess if no 'hits' were found in the word
            if (correctHits == 0) {
                guesses--;
            }

            System.out.println("Debug: " + concealedArr.toString());
            System.out.println("Concealed: " + concealedWord);
        } while (concealedWord.equals(secretWord) == false);
    }

    public static void makeGuess(char ch) {
        for (int i=0; i<secretWord.length(); i++) {
            if (secretWord.charAt(i) == ch) {
                concealedArr.set(i, ch);
                correctHits++;
            }
        }

        // Reset the concealedWord string
        concealedWord = "";

        // Loop through the concealedArr array, set concealedWord String to mirror the array
        concealedArr.forEach(x -> { concealedWord += x; });
    }
}
