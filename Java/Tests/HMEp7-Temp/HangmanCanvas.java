/*
 * Java Hangman Game - HangmanCanvas.java
 *
 * Canvas class for my Java Hangman game
 *
 * Date created: 22 August 2026 17:03
 * Date modified: 02 October 2026 14:56
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
    public Graphics2D g2d;
    
    private final Image image; // New
    private int[] supportPolyX = {200, 250, 260, 200};
    private int[] supportPolyY = {150, 100, 100, 160};

    public HangmanCanvas(Image image) {
        this.image = image; // New
    }
    
    public void drawGallowsPost() {
        g2d.setColor(new Color(196, 181, 130));
        g2d.drawRect(200, 100, 10, 190); /* x, y, width, height */
        g2d.fillRect(200, 100, 10, 190);
    }
    
    public void drawGallowsBeam() {
        g2d.setColor(new Color(196, 181, 130));
        g2d.drawRect(200, 100, 120, 10);
        g2d.fillRect(200, 100, 120, 10);
    }
    
    public void drawGallowsSupport() {
        g2d.setColor(new Color(196, 181, 130));
        g2d.drawPolygon(supportPolyX, supportPolyY, 4);
        g2d.fillPolygon(supportPolyX, supportPolyY, 4);
    }
    
    public void drawRope() {
        g2d.setColor(new Color(20, 23, 18));
        g2d.drawLine(290, 110, 290, 150);
    }
    
    public void drawHead() {
        g2d.setColor(new Color(5, 5, 5));
        g2d.drawOval(277, 150, 25, 25);
    }
    
    public void drawBody() {
        g2d.setColor(new Color(5, 5, 5));
        g2d.drawLine(290, 175, 290, 250);
    }
    
    public void drawLegs() {
        g2d.setColor(new Color(5, 5, 5));
        g2d.drawLine(290, 250, 270, 270);
        g2d.drawLine(290, 250, 310, 270);
    }
    
    public void drawArms() {
        
    }

    /* NEW */
    public void paintComponent (Graphics g) {
        super.paintComponent(g);
        
        //Graphics2D g2d = (Graphics2D) g;
        g2d = (Graphics2D) g;

        // 1. Enable Anti-aliasing for smooth edges (Google)
        g2d.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, 
                         RenderingHints.VALUE_TEXT_ANTIALIAS_LCD_HRGB);

        // 2. Enable Fractional Metrics for better character positioning (Google)
        g2d.setRenderingHint(RenderingHints.KEY_FRACTIONALMETRICS, 
                         RenderingHints.VALUE_FRACTIONALMETRICS_ON);
        
        // Enable Anti-aliasing for shapes
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                             RenderingHints.VALUE_ANTIALIAS_ON);

        // Draw the background image
        g2d.drawImage(image, 0, 0, this);
        
        g2d.setFont(new Font("Noto Sans", Font.PLAIN, 12));
        
        int guessesRemaining = HangmanGame.getGuesses();
        
        switch(guessesRemaining) {
            case 10:
                g2d.drawString("10 guesses remaining!", 15, 300);
                break;
            case 9:
                g2d.drawString("9 guesses remaining!", 15, 300);
                drawGallowsPost();
                break;
            case 8:
                g2d.drawString("8 guesses remaining!", 15, 300);
                drawGallowsPost();
                drawGallowsBeam();
                break;
            case 7:
                g2d.drawString("7 guesses remaining!", 15, 300);
                drawGallowsPost();
                drawGallowsBeam();
                drawGallowsSupport();
                break;
            case 6:
                g2d.drawString("6 guesses remaining!", 15, 300);
                drawGallowsPost();
                drawGallowsBeam();
                drawGallowsSupport();
                drawRope();
                break;
            case 5:
                g2d.drawString("5 guesses remaining!", 15, 300);
                drawGallowsPost();
                drawGallowsBeam();
                drawGallowsSupport();
                drawRope();
                drawHead();
                break;
            case 4:
                g2d.drawString("4 guesses remaining!", 15, 300);
                drawGallowsPost();
                drawGallowsBeam();
                drawGallowsSupport();
                drawRope();
                drawHead();
                drawBody();
                break;
            case 3:
                g2d.drawString("3 guesses remaining!", 15, 300);
                drawGallowsPost();
                drawGallowsBeam();
                drawGallowsSupport();
                drawRope();
                drawHead();
                drawBody();
                drawLegs();
                break;
            case 2:
                g2d.drawString("2 guesses remaining!", 15, 300);
                drawGallowsPost();
                drawGallowsBeam();
                drawGallowsSupport();
                drawRope();
                drawHead();
                drawBody();
                drawLegs();
                drawArms();
                break;
            case 1:
                g2d.drawString("1 guess remaining!", 15, 300);
                drawGallowsPost();
                drawGallowsBeam();
                drawGallowsSupport();
                drawRope();
                drawHead();
                drawBody();
                drawLegs();
                drawArms();
                break;
            case 0:
                g2d.drawString("Game over!", 15, 300);
                drawGallowsPost();
                drawGallowsBeam();
                drawGallowsSupport();
                drawRope();
                drawHead();
                drawBody();
                drawLegs();
                drawArms();
                break;
        }
        
        g2d.setFont(new Font("Noto Sans", Font.BOLD, 36));
        
        if (HangmanGame.getGameState() == HangmanGame.GameState.GAME_LOST) {
            g2d.drawString("LOL YOU FOOKEN NUBCAKE!", 40, 40);
        }
        
        if (HangmanGame.getGameState() == HangmanGame.GameState.GAME_WON) {
            g2d.drawString("YUO ARE A WINRAR!!", 40, 40);
        }
        
        //g2d.setFont(new Font("Noto Sans", Font.BOLD, 36));
        //g2d.drawString("Java Hangman Test!", 200, 300);
    }
    /* */
}
