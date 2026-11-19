import javax.swing.*;
import java.awt.*;

public class SevenSegmentDisplayDemo extends JFrame {
    private SevenSegmentPanel displayPanel;

    public SevenSegmentDisplayDemo() {
        setTitle("Dynamic 7-Segment Display");
        setSize(400, 450);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        setLayout(new BorderLayout());

        displayPanel = new SevenSegmentPanel();
        add(displayPanel, BorderLayout.CENTER);

        // Slider to dynamically change the number
        JSlider slider = new JSlider(0, 9, 0);
        slider.setMajorTickSpacing(1);
        slider.setPaintTicks(true);
        slider.setPaintLabels(true);
        slider.addChangeListener(e -> {
            displayPanel.setNumber(slider.getValue());
        });

        add(slider, BorderLayout.SOUTH);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new SevenSegmentDisplayDemo().setVisible(true);
        });
    }
}

class SevenSegmentPanel extends JPanel {
    private int currentNumber = 0;

    // Segment definition table for digits 0-9: {A, B, C, D, E, F, G}
    private final boolean[][] digitSegments = {
        {true,  true,  true,  true,  true,  true,  false}, // 0
        {false, true,  true,  false, false, false, false}, // 1
        {true,  true,  false, true,  true,  false, true},  // 2
        {true,  true,  true,  true,  false, false, true},  // 3
        {false, true,  true,  false, false, true,  true},  // 4
        {true,  false, true,  true,  false, true,  true},  // 5
        {true,  false, true,  true,  true,  true,  true},  // 6
        {true,  true,  true,  false, false, false, false}, // 7
        {true,  true,  true,  true,  true,  true,  true},  // 8
        {true,  true,  true,  true,  false, true,  true}   // 9
    };

    public void setNumber(int number) {
        if (number >= 0 && number <= 9) {
            this.currentNumber = number;
            repaint(); // Redraw panel with the new number
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        // Background
        g2d.setColor(new Color(20, 20, 20));
        g2d.fillRect(0, 0, getWidth(), getHeight());

        // Dimensions and positioning for the digit
        int x = 100, y = 50, w = 120, h = 220, thickness = 18;
        
        boolean[] active = digitSegments[currentNumber];

        Color activeColor = new Color(255, 50, 50);    // Lit segment color
        Color inactiveColor = new Color(60, 60, 60);  // Unused/grayed-out segment color

        // Draw segments A through G
        drawSegmentA(g2d, x, y, w, thickness, active[0] ? activeColor : inactiveColor);
        drawSegmentB(g2d, x, y, w, h, thickness, active[1] ? activeColor : inactiveColor);
        drawSegmentC(g2d, x, y+h/2, w, h, thickness, active[2] ? activeColor : inactiveColor);
        drawSegmentD(g2d, x, y+h, w, thickness, active[3] ? activeColor : inactiveColor);
        drawSegmentE(g2d, x, y+h/2, w, h, thickness, active[4] ? activeColor : inactiveColor);
        drawSegmentF(g2d, x, y, w, h, thickness, active[5] ? activeColor : inactiveColor);
        drawSegmentG(g2d, x, y+h/2, w, thickness, active[6] ? activeColor : inactiveColor);
    }

    // Helper methods to draw individual segments using polygons for slanted ends
    private void drawSegmentA(Graphics2D g, int x, int y, int w, int t, Color c) {
        g.setColor(c);
        Polygon p = new Polygon();
        p.addPoint(x + t/2, y);
        p.addPoint(x + w - t/2, y);
        p.addPoint(x + w - t, y + t);
        p.addPoint(x + t, y + t);
        g.fillPolygon(p);
    }

    private void drawSegmentB(Graphics2D g, int x, int y, int w, int h, int t, Color c) {
        g.setColor(c);
        Polygon p = new Polygon();
        int halfH = h / 2;
        p.addPoint(x + w, y + t/2);
        p.addPoint(x + w, y + halfH - t/2);
        p.addPoint(x + w - t, y + halfH - t);
        p.addPoint(x + w - t, y + t);
        g.fillPolygon(p);
    }

    private void drawSegmentC(Graphics2D g, int x, int y, int w, int h, int t, Color c) {
        g.setColor(c);
        Polygon p = new Polygon();
        int halfH = h / 2;
        p.addPoint(x + w, y + t/2);
        p.addPoint(x + w, y + halfH - t/2);
        p.addPoint(x + w - t, y + halfH - t);
        p.addPoint(x + w - t, y + t);
        g.fillPolygon(p);
    }

    private void drawSegmentD(Graphics2D g, int x, int y, int w, int t, Color c) {
        g.setColor(c);
        Polygon p = new Polygon();
        p.addPoint(x + t, y);
        p.addPoint(x + w - t, y);
        p.addPoint(x + w - t/2, y - t);
        p.addPoint(x + t/2, y - t);
        g.fillPolygon(p);
    }

    private void drawSegmentE(Graphics2D g, int x, int y, int w, int h, int t, Color c) {
        g.setColor(c);
        Polygon p = new Polygon();
        int halfH = h / 2;
        p.addPoint(x, y + t/2);
        p.addPoint(x, y + halfH - t/2);
        p.addPoint(x + t, y + halfH - t);
        p.addPoint(x + t, y + t);
        g.fillPolygon(p);
    }

    private void drawSegmentF(Graphics2D g, int x, int y, int w, int h, int t, Color c) {
        g.setColor(c);
        Polygon p = new Polygon();
        int halfH = h / 2;
        p.addPoint(x, y + t/2);
        p.addPoint(x, y + halfH - t/2);
        p.addPoint(x + t, y + halfH - t);
        p.addPoint(x + t, y + t);
        g.fillPolygon(p);
    }

    private void drawSegmentG(Graphics2D g, int x, int y, int w, int t, Color c) {
        g.setColor(c);
        Polygon p = new Polygon();
        p.addPoint(x + t/2, y);
        p.addPoint(x + w - t/2, y);
        p.addPoint(x + w - t*3/4, y + t/2);
        p.addPoint(x + t*3/4, y + t/2);
        g.fillPolygon(p);
    }
}
