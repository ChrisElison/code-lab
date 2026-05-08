/*
 * Java Buttons Test - CoolButton.java
 * 
 * Automatically add A-Z buttons to the UI, display a message when each is pressed
 * This file is for the CoolButton class which extends JButton
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-05-08 19:05
 * Date modified: 2026-05-08 19:05
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

public class CoolButton extends JButton implements ActionListener {
    // Constructor method, this is called when we create a CoolButton
    public CoolButton(String label) {
        // Se the button text
        this.setText(label);
        
        System.out.println("Created cool button with label: "+ label);
        
        // Add an ActionListener to the button
        this.addActionListener(this);
    }
    
    // This method runs when the button is clicked
    public void actionPerformed(ActionEvent e) {
        System.out.println("Clicked: "+ this.getText());
        
        // Call the doSomething() method in the parent class
        ButtonsTest.doSomething();
    }
}
