/*
 * Java Hangman Game - Letter Guess Test
 * 
 * Test program to guess a letter in a word. There's probably a
 * much easier and elegant way to do this, let me know!
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-06-24 19:40
 * Date modified: 2026-07-07 12:14
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import java.util.*;

public class LetterGuesser {
    public static String secretWord = "TRANSISTOR";
    public static String concealedWord = "";
    public static ArrayList<Character> testArr = new ArrayList<Character>();
    public static int guesses = 10;
    public static int correctHits = 0;

    public static void main(String[] args) {
        // Add n number of elements to testArr based on secretWord length
        for (int i=0; i<secretWord.length(); i++) {
            testArr.add('_');
        }

        Scanner scanner = new Scanner(System.in);

        System.out.println("Hangman Game Letter Guess Test");

        // Main loop, call makeGuess() while the concealedWord doesn't match secretWord
        do {
            // Reset correctHits counter
            correctHits = 0;

            // If we run out of guesses, exit the program for now
            if (guesses == 0) {
                System.out.println("Game over!");
                System.exit(0);
            }

            // Read in a character from the terminal, convert to upper case
            char testChar = scanner.next().toUpperCase().charAt(0);
            
            // Call makeGuess() function with character to test
            makeGuess(testChar);

            // If we guessed incorrectly, deduct a guess
            if (correctHits == 0) {
                guesses--;
            }

            System.out.println("Debug: " + testArr.toString());
            System.out.println("Concealed: " + concealedWord);
        } while (concealedWord.equals(secretWord) == false);
    }

    public static void makeGuess(char ch) {
        // Check if the provided char matches a char in secretWord string
        for (int i=0; i<secretWord.length(); i++) {
            if (secretWord.charAt(i) == ch) {
                // Update the testArr array with the matched character
                testArr.set(i, ch);
                // Increment correctHits counter
                correctHits++;
            }
        }

        // Clear concealedWord
        concealedWord = "";

        // Update the concealedWord String from the testArr
        testArr.forEach(x -> { concealedWord += x; });
    }
}
