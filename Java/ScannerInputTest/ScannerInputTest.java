/*
 * Java Scanner Console Input Test
 * 
 * An example of reading in data from the console using Scanner
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-06-02 19:09
 * Date modified: 2026-06-03 19:13
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import java.util.*;
    
public class ScannerInputTest {
    public static void main(String[] args) throws InputMismatchException {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Console Input Test by Chris Elison\n");
        System.out.print("Enter your name: ");
        
        String myName = scanner.next();
        
        System.out.println("Hello, "+ myName +"!");
        
        System.out.print("How old are you, "+ myName +"?: ");
        int myAge = 0;
            
        try {
            myAge = scanner.nextInt();
        } catch(InputMismatchException e) {
            System.out.println("Sorry, please enter a number only!");
            System.exit(0);
        }
        
        System.out.println("Your name is "+ myName +" and you are "+ myAge +" years old!");
    }
}
