/*
 * Java Buttons Test - EnableButton.java
 * 
 * This file is for the EnableButton class which extends JButton
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-06-20 18:38
 * Date modified: 2026-06-20 18:38
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

public class EnableButton extends JButton implements ActionListener {
    // Constructor method, this is called when we create a CoolButton
    public EnableButton(String label) {
        // Set the button text
        this.setText(label);
        
        // Add an ActionListener to the button
        this.addActionListener(this);
    }
    
    // This method runs when the button is clicked
    public void actionPerformed(ActionEvent e) {
        //System.out.println("Clicked: "+ this.getText());
        switch (this.getText()) {
            case "Enable":
                DisableButtonsTest.enableBtns();
                break;
            case "Disable":
                DisableButtonsTest.disableBtns();
                break;
        }
    }
}
