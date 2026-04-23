/*
 * Battle Ships Game
 * Version: 0.1
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date modified: 2026-03-11 19:03
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;

public class BattleshipsGame extends JFrame {
	public static String GAME_VER = "0.1";

	public BattleshipsGame() {
		// Set the window title, size and disable resizing
		this.setTitle("Battle Ships v" + GAME_VER + " by Chris Elison");
		this.setSize(1024, 768);
		this.setResizable(false);

		// Add a panel to the window
		JPanel content   = new JPanel();
		JLabel testLabel = new JLabel("Position your fleet!", JLabel.CENTER);
		testLabel.setFont(new Font("Serif", Font.BOLD, 48));
		JButton testBtn  = new JButton("Click me!");
		JButton testBtn2 = new JButton("And me too!");

		content.setLayout(new BorderLayout(5, 5));

		content.add(testBtn, BorderLayout.NORTH);
		content.add(testLabel, BorderLayout.CENTER);
		content.add(testBtn2, BorderLayout.SOUTH);

		// Center the window on the screen
		this.setLocationRelativeTo(null);

		// Tell the program to exit when closing the JFrame
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		this.setContentPane(content);

		// Once window has been set up, display it
		this.setVisible(true);
	}

	public static void main(String args[]) {
		try {
        		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
    		} catch (Exception unused) {
        		; // Ignore exception because we can't do anything.  Will use default.
		}

		System.out.println("Starting Battle Ships v" + GAME_VER);
		new BattleshipsGame();
	}
}
