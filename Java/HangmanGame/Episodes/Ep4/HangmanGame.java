/*
 * Java Hangman Game - HangmanGame.java
 *
 * Main code file for my simple Swing Hangman game.
 *
 * Date created: 11 July 2026 16:06
 * Date modified: 09 August 2026 17:05
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 *
 */

import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

import java.awt.Graphics;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

public class HangmanGame extends JFrame implements ActionListener {
    public static final String textFilePath = "words.txt"; // Random words text file
    public static File f = new File(textFilePath);
    public static ArrayList<String> wordArray = new ArrayList<String>(); // Random words array
        
    public static String secretWord = ""; // Secret word to guess
    public static String concealedWord = "";        // Concealed word to be revealed 
    public static ArrayList<Character> concealedArr = new ArrayList<Character>();   // Concealed char array
    public static int guesses = 10;     // Number of guesses remaining
    public static int correctHits = 0;  // Used to track if a guess is correct

    public JMenuBar menuBar;
    public JMenu menu;
    public JMenuItem menuItem;

    public static JPanel contentPanel;
    public static HangmanCanvas canvasPanel;
    public static JPanel wordPanel;
    public static JPanel keyboardPanel;
    public static JPanel kbTop, kbMid, kbBot;

    public static JLabel testLabel, testLabel2, testLabel3, testLabel4, testLabel5;

    public HangmanGame() {
        this.setTitle("Java HangMan by Chris Elison");

        this.setSize(500, 680);

        this.setResizable(false);

        this.setLocationRelativeTo(null);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

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

        testLabel3 = new JLabel("Q W E R T Y U I O P");
        testLabel4 = new JLabel("A S D F G H J K L");
        testLabel5 = new JLabel("Z X C V B N M");
        
        try {
            BufferedImage pic = ImageIO.read(this.getClass().getResource("hangmanbg.jpg"));
            JLabel icon = new JLabel(new ImageIcon(pic));
            canvasPanel.add(icon);
        } catch (IOException e) {
            System.out.println("Error: Failed to load image!");
            System.exit(0);
        }

        //canvasPanel.add(testLabel);

        wordPanel.add(testLabel2);
        
        keyboardPanel.add(wordPanel);
        keyboardPanel.add(kbTop);
        keyboardPanel.add(kbMid);
        keyboardPanel.add(kbBot);

        kbTop.add(testLabel3);
        kbMid.add(testLabel4);
        kbBot.add(testLabel5);

        this.setContentPane(contentPanel);


        this.setVisible(true);
    }

    public static void main(String[] args) {
        new HangmanGame();

        // Loadwords from file into array
        getWords();

        // Get a random secret word
        //secretWord = getRandomWord();
        newGame();

        // Set the concealedArr array to all underscores characters
        //for (int i=0; i<secretWord.length(); i++) {
        //    concealedArr.add('_');
        //}

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
        concealedWord = " ";

        // Loop through the concealedArr array, set concealedWord String to mirror the array
        concealedArr.forEach(x -> { concealedWord += x + " "; });

        testLabel2.setText(concealedWord);
        wordPanel.revalidate();
    }

    public static void getWords() {
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
        Random rand = new Random();
        
        String word = wordArray.get(rand.nextInt(wordArray.size()));

        return word;
    }

    public static void newGame() {
        /* TODO: Reset UI, get new word, reset guesses */
        secretWord = getRandomWord();

        System.out.println("New secret word: " + secretWord);
        guesses = 10;
        concealedWord = " ";

        concealedArr.clear();
        
        for (int i=0; i<secretWord.length(); i++) {
            concealedArr.add('_');
        }

        concealedArr.forEach(x -> { concealedWord += x + " ";});

        testLabel2.setText(concealedWord);
        wordPanel.revalidate();
    }

    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand()) {
            case "New Game":
                System.out.println("Starting new game...");
                newGame();
                break;
            case "Exit":
                System.out.println("Exiting...");
                System.exit(0);
                break;
        }
    }
}
