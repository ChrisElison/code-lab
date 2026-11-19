/*
 * Seven Segment Test 1 - Single Digit
 *
 * In this test example I aim to display a number from 0-9
 * represented by a 7-segment LED display
 *
 * Date started: 2026-11-15 13:20
 * Date modified: 2026-11-15 13:39
 *
 * Author: Christopher Elison <chriselison.uk>
 *
 */

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.event.*;

public class SevenSegTest extends JFrame {
    private static int number = 0;

    private static JPanel contentPanel;

    public SevenSegTest() {
        this.setTitle("Java 7-Segment Display by Chris Elison");

        this.setSize(500, 300);

        //this.setResizable(false);
        
        // Center window on program staartup
        this.setLocationRelativeTo(null);

        // Close the program if window close button is pressed
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        contentPanel = new JPanel(new GridLayout(1, 1));
        //contentPanel.add(new JLabel("Hello world!"), BorderLayout.NORTH);
        contentPanel.add(new SegDisplay());

        // Set main content for the window
        this.setContentPane(contentPanel);
        
        this.setVisible(true);
    }

    public static void main(String[] args) {
        // Check if argument number is supplied
        if (args.length == 0 || Integer.parseInt(args[0]) > 9) {
            System.out.println("Usage: java SevenSegTest [0-9]\n");
            System.exit(0);
        }

        number = Integer.parseInt(args[0]);

        System.out.println("7-segment LED display test v0.1 by Chris Elison");
        System.out.println("Displaying number: " + number);

        new SevenSegTest();
    }
}
