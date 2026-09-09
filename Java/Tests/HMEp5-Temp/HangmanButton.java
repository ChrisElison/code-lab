import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class HangmanButton extends JButton implements ActionListener {
    public HangmanButton(String label) { 
        this.setPreferredSize(new Dimension(48, 48));
        this.setText(label);
        System.out.println("Created button: " + label);

        this.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        this.setEnabled(false);
        System.out.println("Making guess: " + this.getText().charAt(0));
    }
}
