/*
 * Java PaintComponent PaintPanel Class
 * 
 * An example of using the PaintComponent method to draw to a JPanel
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-05-14 20:48
 * Date modified: 2026-05-15 20:31
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;

public class PaintPanel extends JPanel {
    public static int ftSize;
          
    public PaintPanel() {
          this.ftSize = 32;
    }
          
    public void setFontSize(int size) {
          this.ftSize = size;
          //System.out.println("Updated size: " + this.ftSize);
          this.repaint();
    }
          
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        
        Graphics2D g2d = (Graphics2D) g;

        // 1. Enable Anti-aliasing for smooth edges
        g2d.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, 
                         RenderingHints.VALUE_TEXT_ANTIALIAS_LCD_HRGB);

        // 2. Enable Fractional Metrics for better character positioning
        g2d.setRenderingHint(RenderingHints.KEY_FRACTIONALMETRICS, 
                         RenderingHints.VALUE_FRACTIONALMETRICS_ON);

        g2d.setFont(new Font("Noto Sans", Font.PLAIN, this.ftSize));
        g2d.drawString("Java PaintComponent Test!", 200, 300);
    }
}