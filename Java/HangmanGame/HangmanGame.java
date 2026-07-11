/*
 * 11 July 2026 16:06
 * 11 July 2026 16:31
 */

import java.util.*;

public class HangmanGame {
    public static String secretWord = "TRANSISTOR";
    public static String concealedWord = "";
    public static ArrayList<Character> concealedArr = new ArrayList<Character>();
    public static int guesses = 10;
    public static int correctHits = 0;

    public static void main(String[] args) {
        for (int i=0; i<secretWord.length(); i++) {
            concealedArr.add('_');
        }

        Scanner scanner = new Scanner(System.in);

        do {
            correctHits = 0;

            if (guesses == 0) {
                System.out.println("Game over!");
                System.exit(0);
            }

            char testChar = scanner.next().toUpperCase().charAt(0);
            makeGuess(testChar);

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

        concealedWord = "";

        concealedArr.forEach(x -> { concealedWord += x; });
    }
}
