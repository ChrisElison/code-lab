/*
 * Java Hangman Game - HangmanCanvas.java
 *
 * Canvas class for my Java Hangman game
 *
 * Date created: 22 August 2026 17:03
 * Date modified: 26 September 2026 19:33
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 *
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class HangmanCanvas extends JPanel {
    private final Image image; // New

    public HangmanCanvas(Image image) {
        this.image = image; // New
    }

    /* NEW */
    public void paintComponent (Graphics g) {
        super.paintComponent(g);
        
        Graphics2D g2d = (Graphics2D) g;

        // 1. Enable Anti-aliasing for smooth edges (Google)
        g2d.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, 
                         RenderingHints.VALUE_TEXT_ANTIALIAS_LCD_HRGB);

        // 2. Enable Fractional Metrics for better character positioning (Google)
        g2d.setRenderingHint(RenderingHints.KEY_FRACTIONALMETRICS, 
                         RenderingHints.VALUE_FRACTIONALMETRICS_ON);

        // Draw the background image
        g.drawImage(image, 0, 0, this);
        
        g2d.setFont(new Font("Noto Sans", Font.BOLD, 36));
        
        int guessesRemaining = HangmanGame.getGuesses();
        
        switch(guessesRemaining) {
            case 10:
                g2d.drawString("10 guesses remaining!", 200, 300);
                break;
            case 9:
                g2d.drawString("9 guesses remaining!", 200, 300);
                break;
            case 8:
                g2d.drawString("8 guesses remaining!", 200, 300);
                break;
            case 7:
                g2d.drawString("7 guesses remaining!", 200, 300);
                break;
            case 6:
                g2d.drawString("6 guesses remaining!", 200, 300);
                break;
            case 5:
                g2d.drawString("5 guesses remaining!", 200, 300);
                break;
            case 4:
                g2d.drawString("4 guesses remaining!", 200, 300);
                break;
            case 3:
                g2d.drawString("3 guesses remaining!", 200, 300);
                break;
            case 2:
                g2d.drawString("2 guesses remaining!", 200, 300);
                break;
            case 1:
                g2d.drawString("1 guess remaining!", 200, 300);
                break;
            case 0:
                g2d.drawString("Game over!", 200, 300);
                break;
        }
        
        //g2d.setFont(new Font("Noto Sans", Font.BOLD, 36));
        //g2d.drawString("Java Hangman Test!", 200, 300);
    }
    /* */
}
