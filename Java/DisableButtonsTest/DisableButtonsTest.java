/*
 * Enable/Disable Buttons Test
 * 
 * Press a button to enable/disable an ArrayList of JButtons
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-06-20 17:30
 * Date modified: 2026-06-20 18:18
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
    public static ArrayList<CoolButton> btnArray = new ArrayList<CoolButton>();
    
    public DisableButtonsTest() {
        this.setTitle("Java Disable Buttons Test by Chris Elison");
		this.setSize(900, 450);
		this.setResizable(false);
        
        // Add a panel to the window
        JPanel content = new JPanel();
        JPanel topPanel = new JPanel();
        JPanel btnPanel = new JPanel();
        
        // Set a border (padding in CSS speak) around the inside of the window
        content.setBorder(new EmptyBorder(10, 10, 10, 10));
        topPanel.setBorder(new EmptyBorder(10, 10, 10, 10));
        btnPanel.setBorder(new EmptyBorder(10, 10, 10, 10));
        
        GridLayout gridLayout = new GridLayout(2, 5);
        
        // Add gaps between the buttons
        gridLayout.setHgap(10);
        gridLayout.setVgap(10);
        
        content.setLayout(new BorderLayout(5, 5));
        topPanel.setLayout(new GridLayout(1, 2));
        btnPanel.setLayout(gridLayout);
        
        // Add Enable/Disable buttons to top panel
        topPanel.add(new EnableButton("Enable"));
        topPanel.add(new EnableButton("Disable"));
        
        // Array to hold button labels
        String[] btnLabels = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
        
        // Add 10 CoolButtons to the ArrayList
        for (int i=0; i<10; i++) {
            btnArray.add(new CoolButton(btnLabels[i]));
        }
        
        // Add each button to the content panel
        for (int j=0; j<btnArray.size(); j++) {
            btnPanel.add(btnArray.get(j));
        }
        
        content.add(topPanel, BorderLayout.NORTH);
        content.add(btnPanel, BorderLayout.SOUTH);
        
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
    
    public static void enableBtns() {
        System.out.println("Enabled buttons");
        
        // Enable buttons
        for (int j=0; j<btnArray.size(); j++) {
            btnArray.get(j).setEnabled(true);
        }
    }
    
    public static void disableBtns() {
        System.out.println("Disabled buttons");
        
        // Disable buttons
        for (int j=0; j<btnArray.size(); j++) {
            btnArray.get(j).setEnabled(false);
        }
    }
}
