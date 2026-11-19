/*
 * Digit.java
 *
 * 2026-11-15 17:33
 *
 */

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.event.*;

public class Digit {
    public static int value;
    
    public static enum DigitColour {
        COLOUR_RED,
        COLOUR_GREEN,
        COLOUR_BLUE,
        COLOUR_YELLOW,
        COLOUR_PURPLE
    };

    public static DigitColour colour = DigitColour.COLOUR_RED;

    public static ArrayList<Segment> segments = new ArrayList<Segment>();
    
    public void setValue(int val) {
        this.value = val;
    }
}
