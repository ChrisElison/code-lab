/*
 * Enable/Disable Buttons Test
 * 
 * Press a button to enable/disable an ArrayList of JButtons
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-06-20 17:30
 * Date modified: 2026-06-20 18:03
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import java.util.ArrayList;
import javax.swing.JButton;
import javax.swing.border.EmptyBorder;

public class DisableButtonsTest extends JFrame {
    public ArrayList<CoolButton> btnArray = new ArrayList<CoolButton>();
    
    public DisableButtonsTest() {
        this.setTitle("Java Disable Buttons Test by Chris Elison");
		this.setSize(900, 450);
		this.setResizable(false);
        
        // Add a panel to the window
		JPanel content = new JPanel();
        
        // Set a border (padding in CSS speak) around the inside of the window
        content.setBorder(new EmptyBorder(10, 10, 10, 10));
        GridLayout layout = new GridLayout(2,5);
        
        // Add gaps between the buttons
        layout.setHgap(10);
        layout.setVgap(10);
        content.setLayout(layout);
        
        // Array to hold button labels
        String[] btnLabels = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
        
        // Add 10 CoolButtons to the ArrayList
        for (int i=0; i<10; i++) {
            btnArray.add(new CoolButton(btnLabels[i]));
        }
        
        // Add each button to the content panel
        for (int j=0; j<btnArray.size(); j++) {
            content.add(btnArray.get(j));
        }
        
        // Center the window on the screen
		this.setLocationRelativeTo(null);

		// Tell the program to exit when closing the JFrame
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        this.setContentPane(content);
        
        // Once window has been set up, display it
		this.setVisible(true);
    }
    
    public static void main(String[] args) {
        new DisableButtonsTest();
        System.out.println("Hello, world!");
    }
}
