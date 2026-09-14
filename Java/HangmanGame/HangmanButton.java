/*
 * Java Hangman Game - HangmanButton.java
 *
 * Hangman button class.
 *
 * Date created: 13 September 2026 17:00
 * Date modified: 14 September 2026 14:01
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 *
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class HangmanButton extends JButton implements ActionListener {
    public HangmanButton(String label) {
        // Set size of the button
        this.setPreferredSize(new Dimension(48, 48));
        
        // Set button text
        this.setText(label);
        System.out.println("Created button: " + label);

        this.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        // Disable the button once pressed
        this.setEnabled(false);
        
        System.out.println("Making guess: " + this.getText().charAt(0));
    }
}
