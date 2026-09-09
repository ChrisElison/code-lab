# 🪢 Hangman Game

This is a recreation of an assignment I was given 20 years ago in college to 
make a graphical Hangman game in Java. I thought it'd be a good introductory
project for my new YouTube channel, <a href="https://youtube.com/@ChrisElisonTech">Chris Elison Tech</a>!

It's just a Swing/AWT application using some JPanels and JButtons, nothing fancy. This is
about my level of Java at the moment, but I've learned a lot recreating this assignment.

The assignment had some mandatory conditions to get a pass:
* The original assignment had us making an applet rather than a JFrame application, but the principle is the same pretty much
* A word to guess must be randomly-chosen from an array, in my recreation, I go one step beyond and load words from a text file
* We had to add buttons representing letters of the alphabet to guess each letter, I used a loop to make A-Z buttons, this time round I am making a QWERTY layout
* We had to use the Graphics2D API to draw the stickman and gallows, we weren't allowed to use images for the stickman, only 2D shapes

I got a distinction for the assignment, btw ;-) Shout-out to my Java tutor, Susan and all my other tutors at NTC!

## Compile / Run
```
chris@Mimas:~/HangmanGame$ javac HangmanGame.java
chris@Mimas:~/HangmanGame$ java HangmanGame
```

## Contents:
* 📝 **HangmanGame.java**
    * Main program source file
* 📝 **HangmanCanvas.java**
    * Code for the Graphics2D JPanel where we draw the hangman graphics
* 📝 **hangmanbg.jpg**
    * Graphic used as background for the canvas JPanel
* 📝 **words.txt**
    * Plaintext list of words used to guess
