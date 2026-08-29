/*
 * Java Hangman Game - HangmanGame.java
 *
 * Main code file for my simple Swing Hangman game.
 *
 * Date created: 11 July 2026 16:06
 * Date modified: 27 August 2026 17:31
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 *
 */

import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.event.*;

public class HangmanGame extends JFrame implements ActionListener {
    public static final String textFilePath = "words.txt";  // Random words text file
    public static File f = new File(textFilePath);
    public static ArrayList<String> wordArray = new ArrayList<String>();    // Random words array
        
    public static String secretWord = "";   // Secret word to guess
    public static String concealedWord = "";    // Concealed word to be revealed 
    public static ArrayList<Character> concealedArr = new ArrayList<Character>();   // Concealed char array
    public static int guesses = 10;     // Number of guesses remaining
    public static int correctHits = 0;  // Used to track if a guess is correct

    public static JMenuBar menuBar;
    public static JMenu menu;
    public static JMenuItem menuItem;

    public static JPanel contentPanel;          // Main GUI JPanel
    public static HangmanCanvas canvasPanel;    // JPanel used for Grpahics2D canvas (Gallows)
    public static JPanel wordPanel;             // Concealed word JPanel
    public static JPanel keyboardPanel;         // JPanel for keyboard keys
    public static JPanel kbTop, kbMid, kbBot;   // Keyboard key rows

    // Various JLabels (Clean up)
    public static JLabel testLabel, testLabel2, testLabel3, testLabel4, testLabel5;

    // Constructor method for game
    public HangmanGame() {
        // Set window title
        this.setTitle("Java HangMan by Chris Elison");

        // Set window size
        this.setSize(500, 680);

        // Prevent window from being resized
        this.setResizable(false);

        // Center window on program staartup
        this.setLocationRelativeTo(null);

        // Close the program if window close button is pressed
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // UI stuff, add menus, panels and labels
        menuBar = new JMenuBar();

        menu = new JMenu("Game");
        menu.setMnemonic(KeyEvent.VK_G);
        menuBar.add(menu);

        menuItem = new JMenuItem("New Game", KeyEvent.VK_N);
        menu.add(menuItem);
        menuItem.addActionListener(this);

        menu.addSeparator();

        menuItem = new JMenuItem("Exit", KeyEvent.VK_X);
        menu.add(menuItem);
        menuItem.addActionListener(this);

        this.setJMenuBar(menuBar);
        
        contentPanel = new JPanel();
        contentPanel.setLayout(new GridLayout(2, 1));

        canvasPanel = new HangmanCanvas();
        wordPanel = new JPanel();
        keyboardPanel = new JPanel();

        kbTop = new JPanel();
        kbMid = new JPanel();
        kbBot = new JPanel();

        keyboardPanel.setLayout(new GridLayout(4, 1));

        contentPanel.add(canvasPanel);
        contentPanel.add(keyboardPanel);

        testLabel = new JLabel("Canvas here");
        testLabel2 = new JLabel("Concealed word");

        testLabel2.setFont(new Font(Font.MONOSPACED, Font.BOLD, 36));

        // TODO: Delete these labels
        testLabel3 = new JLabel("Q W E R T Y U I O P");
        testLabel4 = new JLabel("A S D F G H J K L");
        testLabel5 = new JLabel("Z X C V B N M");
        
        // Add a background image as a JLabel to the canvasPanel JPanel - Code from Google
        try {
            BufferedImage pic = ImageIO.read(this.getClass().getResource("hangmanbg.jpg"));
            JLabel icon = new JLabel(new ImageIcon(pic));
            canvasPanel.add(icon);
        } catch (IOException e) {
            System.out.println("Error: Failed to load image!");
            System.exit(0);
        }

        wordPanel.add(testLabel2);
        
        keyboardPanel.add(wordPanel);
        keyboardPanel.add(kbTop);
        keyboardPanel.add(kbMid);
        keyboardPanel.add(kbBot);

        // TODO: Delete labels, add keyboard buttons
        kbTop.add(testLabel3);
        kbMid.add(testLabel4);
        kbBot.add(testLabel5);

        // Set main content for the window
        this.setContentPane(contentPanel);

        // Show the window
        this.setVisible(true);
    }

    public static void main(String[] args) {
        new HangmanGame();

        // Load words from file into array
        getWords();

        // Start new game, reset UI
        newGame();

        // TODO: Delete this for Ep 5. Scanner object to read text from the terminal
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
        // Check if char appears anywhere in the secret word
        for (int i=0; i<secretWord.length(); i++) {
            if (secretWord.charAt(i) == ch) {
                concealedArr.set(i, ch);
                correctHits++;
            }
        }

        // Reset the concealedWord string
        concealedWord = " ";

        // Loop through the concealedArr array, set concealedWord String to mirror the array
        concealedArr.forEach(x -> { concealedWord += x + " "; });

        // Update the concealed word label, update
        testLabel2.setText(concealedWord);
        wordPanel.revalidate();
    }

    public static void getWords() {
        // This method reads words in from a text file and puts them into an array
        BufferedReader reader;

        if (f.isFile()) {
            try {
                reader = new BufferedReader(new FileReader(textFilePath));
                String line = reader.readLine();

                while (line != null) {
                    wordArray.add(line);
                    line = reader.readLine();
                }

                reader.close();
            } catch (IOException e) {
                System.out.println("Error reading file!");
                System.exit(0);
            }

        } else {
            System.out.println("Error: Couldn't find file: " +textFilePath);
            System.exit(0);
        }
    }

    public static String getRandomWord() {
        // This method simply returns a random word from the wordArray array
        Random rand = new Random();
        
        String word = wordArray.get(rand.nextInt(wordArray.size()));

        return word;
    }

    public static void newGame() {
        /* TODO: Reset UI, get new word, reset guesses */
        secretWord = getRandomWord();

        System.out.println("New secret word: " + secretWord);
        guesses = 10;           // Reset guesses
        concealedWord = " ";    // Reset concealed word

        concealedArr.clear();   // Clear the concealedArr array
        
        // Blank the conealedArr array with underscores
        for (int i=0; i<secretWord.length(); i++) {
            concealedArr.add('_');
        }

        // Set the conealedWord as the concealedArr but with spaces between letters
        concealedArr.forEach(x -> { concealedWord += x + " ";});

        // Update the concealed word label
        testLabel2.setText(concealedWord);
        wordPanel.revalidate();
    }

    public void actionPerformed(ActionEvent e) {
        // Action listener for the menu items
        switch (e.getActionCommand()) {
            // New Game - call newGame() method
            case "New Game":
                System.out.println("Starting new game...");
                newGame();
                break;
            // Exit the game
            case "Exit":
                System.out.println("Exiting...");
                System.exit(0);
                break;
        }
    }
}
