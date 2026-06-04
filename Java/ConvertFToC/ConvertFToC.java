/*
 * Java Fahrenheit to Celsius Temperature converter
 * 
 * Simple command line app to convert F to C using DecimalFormat
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-06-04 20:03
 * Date modified: 2026-06-04 20:29
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.*;

 public class ConvertFToC {
	private static final DecimalFormat df = new DecimalFormat("0.00");
	 
 	public static void main(String[] args) throws InputMismatchException {
		double tempC = 0.00;
		double tempF = 0.00;
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Enter value in F: ");
		
		try {
            tempF = scanner.nextDouble();
        } catch(InputMismatchException e) {
            System.out.println("Sorry, please enter a valid number!");
            System.exit(0);
        }
		
		tempC = ((tempF - 32) * 5/9);
		
		System.out.println("C: "+ df.format(tempC));
	}
 }
