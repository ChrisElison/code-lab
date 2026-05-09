/*
 * Java GUI window menu test program
 * 
 * Attempt to add a menu at the top of the window
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-05-09 17:04
 * Date modified: 2026-05-09 18:00
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class MenuTest extends JFrame implements ActionListener {
    JMenuBar menuBar;
    JMenu menu, submenu;
    JMenuItem menuItem;
    
    public MenuTest() {
        // Setup the window title, size and set if resizable
        this.setTitle("Java Menu Test by Chris Elison");
		this.setSize(800, 450);
		this.setResizable(false);
        
        // Center the window on the screen
		this.setLocationRelativeTo(null);

		// Tell the program to exit when closing the JFrame
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // Create the menu bar.
        menuBar = new JMenuBar();
        
        // Build the first menu.
        menu = new JMenu("File");
        menu.setMnemonic(KeyEvent.VK_F);
        menu.getAccessibleContext().setAccessibleDescription("The only menu in this program that has menu items");
        menuBar.add(menu);
        
        // Add a new game MenuItem, add an ActionListener
        menuItem = new JMenuItem("New Game", KeyEvent.VK_N);
        menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_1, ActionEvent.ALT_MASK));
        menuItem.getAccessibleContext().setAccessibleDescription("This doesn't really do anything");
        menu.add(menuItem);
        menuItem.addActionListener(this);
        
        // Add a seperator
        menu.addSeparator();
        
        // Add an Exit MenuItem, add an ActionListener
        menuItem = new JMenuItem("Exit", KeyEvent.VK_X);
        menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_2, ActionEvent.ALT_MASK));
        menuItem.getAccessibleContext().setAccessibleDescription("This doesn't really do anything");
        menu.add(menuItem);
        menuItem.addActionListener(this);
        
        this.setJMenuBar(menuBar);
        
        //this.setContentPane(content);
        
        // Once window has been set up, display it
		this.setVisible(true);
    }
    
    // Handle clicks of menu items
    public void actionPerformed(ActionEvent e) {
        // We can use switch statement to handle which menu item is clicked
        switch (e.getActionCommand()) {
            case "New Game":
                System.out.println("Starting new game!");
                break;
            case "Exit":
                System.out.println("Exiting!");
                System.exit(0);
                break;
        }
    }
    
    public static void main(String[] args) {
        // Set the look and feel to system
        try {
        		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
    		} catch (Exception unused) {
        		; // Ignore exception because we can't do anything.  Will use default.
		}
        
        new MenuTest();
    } 
}
