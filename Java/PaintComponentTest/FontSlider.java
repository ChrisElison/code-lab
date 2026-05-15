/*
 * Java PaintComponent FontSlider Class
 * 
 * An example of using the PaintComponent method to draw to a JPanel
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-05-15 19:32
 * Date modified: 2026-05-15 20:30
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class FontSlider extends JSlider implements ChangeListener {
    public static int val = 0;
        
    public FontSlider(int min, int max, int val) {
        this.setMinimum(min);
        this.setMaximum(max);
        this.setValue(val);
        
        // Add an ActionListener to the slider
        this.addChangeListener(this);
    }
    
    // This method runs when the button is clicked
    public void stateChanged(ChangeEvent e) {
        val = this.getValue();
        PaintComponentTest.doSomething(val);
    }
}