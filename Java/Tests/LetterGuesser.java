/*
 * Java Hangman Game - Letter Guess Test
 * 
 * Test program to guess a letter in a word
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-06-24 19:40
 * Date modified: 2026-06-24 20:19
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import java.util.*;

public class LetterGuesser {
    public static String secretWord = "TRANSISTOR";
    public static String concealedWord = "";
    public static ArrayList<Character> testArr = new ArrayList<Character>();
        
    public static void main(String[] args) {
        // Add n number of elements to testArr based on secretWord length
        for (int i=0; i<secretWord.length(); i++) {
            testArr.add('_');
        }

        Scanner scanner = new Scanner(System.in);

        System.out.println("Hangman Game Letter Guess Test");

        // Main loop, call makeGuess() while the concealedWord doesn't match secretWord
        do {
            // Read in a character from the terminal
            char testChar = scanner.next().toUpperCase().charAt(0);
                
            makeGuess(testChar);
            System.out.println("Debug: " + testArr.toString());
            System.out.println("Concealed: " + concealedWord);
        } while (concealedWord.equals(secretWord) == false);
    }

    public static void makeGuess(char ch) {
        // Check if the provided char matches a char in secretWord string
        for (int i=0; i<secretWord.length(); i++) {
            if (secretWord.charAt(i) == ch) {
                System.out.println("Matched!");
                
                // Update the testArr array with the matched character
                testArr.set(i, ch);
            }
        }

        // Clear concealedWord
        concealedWord = "";

        // Update the concealedWord String from the testArr
        testArr.forEach(x -> { concealedWord += x; });
    }
}
