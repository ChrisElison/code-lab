/*
 * Java Buttons Test
 * 
 * Automatically add A-J buttons to the UI, display a message when each is pressed
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-05-07 12:03
 * Date modified: 2026-05-07 12:03
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import java.awt.*;
import java.awt.event.*;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.*;
import javax.swing.event.*;
import java.util.ArrayList;
import javax.swing.border.EmptyBorder;

public class ButtonsTest extends JFrame {
    public ButtonsTest() {
        this.setTitle("Java Buttons Test by Chris Elison");
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
        
        // Add some CoolButtons to the content JPanel
        CoolButton testBtn1  = new CoolButton("A");
        CoolButton testBtn2  = new CoolButton("B");
        CoolButton testBtn3  = new CoolButton("C");
        CoolButton testBtn4  = new CoolButton("D");
        CoolButton testBtn5  = new CoolButton("E");
        CoolButton testBtn6  = new CoolButton("F");
        CoolButton testBtn7  = new CoolButton("G");
        CoolButton testBtn8  = new CoolButton("H");
        CoolButton testBtn9  = new CoolButton("I");
        CoolButton testBtn10  = new CoolButton("J");
        content.add(testBtn1);
        content.add(testBtn2);
        content.add(testBtn3);
        content.add(testBtn4);
        content.add(testBtn5);
        content.add(testBtn6);
        content.add(testBtn7);
        content.add(testBtn8);
        content.add(testBtn9);
        content.add(testBtn10);
        
        // Center the window on the screen
		this.setLocationRelativeTo(null);

		// Tell the program to exit when closing the JFrame
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        this.setContentPane(content);
        
        // Once window has been set up, display it
		this.setVisible(true);
    }
    
    // This method is called when a CoolButton is clicked
    public static void doSomething() {
        System.out.println("doSomething() called!");    
    }
    
    public static void main (String[] args) {
        new ButtonsTest();
        //System.out.println("Hello!");
    }
}
