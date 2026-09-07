import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class HangmanButton extends JButton {
    public HangmanButton(String label) { 
        this.setPreferredSize(new Dimension(48, 48));
        this.setText(label);
        System.out.println("Created button: " + label);
    }
}
