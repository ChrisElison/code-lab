/*
 * Java read text file example
 * 
 * Opens a text file of words and adds them to an ArrayList
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-05-05 17:03
 * Date modified: 2026-05-05 17:48
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class ReadTextFileTest {
    // Word text file path, default "words.txt"
    public static String textFilePath = "words.txt";
    public static File f = new File(textFilePath);
    
    public static void main(String[] args) {
        BufferedReader reader;
        ArrayList<String> wordArray = new ArrayList<String>();
        
        // Check if the file in textFilePath exists first
        if (f.isFile()) {
            System.out.println("Reading file "+ textFilePath +"...");
            
            try {
                reader = new BufferedReader(new FileReader(textFilePath));
                String line = reader.readLine();
                
                while (line != null) {
                    wordArray.add(line);
                    line = reader.readLine();
                }
                
                reader.close();
            } catch (IOException e) {
                // Throw exception if we can't read file
                System.out.println("Error reading file "+ textFilePath);
            }
            
            // Display word count
            System.out.println("Found "+ wordArray.size() +" words!");
            
            // Iterate through the array, print words
            for (int i=0; i<wordArray.size(); i++) {
                System.out.print(wordArray.get(i) +", ");
            }
        } else {
            // File does not exist
            System.out.println("File: "+ textFilePath +" not found!");
        }
        
        System.out.println();
    }
}
