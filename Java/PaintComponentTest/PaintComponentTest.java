/*
 * Java PaintComponent Test
 * 
 * An example of using the PaintComponent method to draw to a JPanel
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-05-14 20:31
 * Date modified: 2026-05-15 20:31
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import javax.swing.*;
import javax.swing.event.*;
import javax.swing.BorderFactory;
import java.awt.*;
import java.awt.event.*;

public class PaintComponentTest extends JFrame {
    public static PaintPanel content;
    
    public PaintComponentTest() {
        // Set the window title, size and disable resizing
		this.setTitle("PaintComponent Test by Chris Elison");
		this.setSize(800, 600);
		this.setResizable(false);
        
        // Add a PaintPanel to the window
        content = new PaintPanel();
        
        FontSlider fontSlider = new FontSlider(10, 60, 32);
        
        // Center the window on the screen
		this.setLocationRelativeTo(null);

		// Tell the program to exit when closing the JFrame
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		this.setContentPane(content);
        
        content.add(fontSlider);

		// Once window has been set up, display it
		this.setVisible(true);
    }
    
    // This method is called when a CoolButton is clicked
    public static void doSomething(int val) {
        //System.out.println("Value: " + val);
        content.setFontSize(val);
    }
    
    public static void main(String[] args) {
        new PaintComponentTest();
    }
}