/*
 * Java PaintComponent Test
 * 
 * An example of using the PaintComponent method to draw to a JPanel
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-05-14 20:31
 * Date modified: 2026-05-14 20:31
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
    public PaintComponentTest() {
        // Set the window title, size and disable resizing
		this.setTitle("PaintComponent Test by Chris Elison");
		this.setSize(800, 600);
		this.setResizable(false);
        
        // Add a PaintPanel to the window
		PaintPanel content = new PaintPanel();
        
        // Center the window on the screen
		this.setLocationRelativeTo(null);

		// Tell the program to exit when closing the JFrame
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		this.setContentPane(content);

		// Once window has been set up, display it
		this.setVisible(true);
    }
    
    public static void main(String[] args) {
        new PaintComponentTest();
    }
}