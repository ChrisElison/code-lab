import java.awt.*;
import java.awt.geom.*;

public class ShapeInstance {
    // Shared geometry template
    private Shape baseShape;
    
    // Instance-specific properties
    private double x, y;
    private double scale;
    private double rotationAngle; // in radians
    private Color color;

    public ShapeInstance(Shape baseShape, double x, double y, double scale, Color color) {
        this.baseShape = baseShape;
        this.x = x;
        this.y = y;
        this.scale = scale;
        this.rotationAngle = 0.0;
        this.color = color;
    }

    public void setPosition(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void setRotation(double angle) {
        this.rotationAngle = angle;
    }

    // Render this specific copy onto the Graphics2D context
    public void draw(Graphics2D g2d) {
        // Save the current graphics transform
        AffineTransform oldTransform = g2d.getTransform();

        // Apply transformations for this specific instance
        g2d.translate(x, y);
        g2d.rotate(rotationAngle);
        g2d.scale(scale, scale);

        // Set color and render the shape
        g2d.setColor(color);
        g2d.fill(baseShape); // or g2d.draw(baseShape) for outline

        // Restore the original graphics transform
        g2d.setTransform(oldTransform);
    }
}
