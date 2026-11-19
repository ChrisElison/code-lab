/*
 * 2026-11-18 17:48
 */

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.Rectangle2D;
import java.util.*;
import java.util.ArrayList;
import java.util.List;
import javax.swing.*;
import javax.swing.event.*;

public class SegDisplay extends JPanel {
    private ArrayList<ShapeInstance> copies; 

    public SegDisplay() {
        copies = new ArrayList<>();
    
        Shape template = new Rectangle2D.Double(-20, -20, 40, 40);

        copies.add(new ShapeInstance(template, 100, 100, 1.0, Color.RED));
        copies.add(new ShapeInstance(template, 150, 200, 1.0, Color.BLUE));
        copies.add(new ShapeInstance(template, 155, 205, 1.0, Color.GREEN));

        //this.add(new JLabel("Display here!"));
        this.setBackground(Color.BLACK);
        //this.setSize(200, 300);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;

        // Enable anti-aliasing for smooth rendering
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        // Draw all copies
        for (ShapeInstance instance : copies) {
            instance.draw(g2d);
        }
    }
}
