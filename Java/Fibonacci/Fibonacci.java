/*
 * Fibonacci sequence example
 * 
 * Fibonacci sequence in Java, probably a better way to do this!
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-05-04 19:28
 * Date modified: 2026-05-04 19:57
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import java.util.ArrayList;

public class Fibonacci {
    public static void main(String[] args) {
        ArrayList<Integer> seq = new ArrayList<Integer>();
        seq.add(0);
        seq.add(1);
        int fib;
        
        for (int i=1; i<20; i++) {
            fib = (seq.get(i) + seq.get(i-1));
            seq.add(fib);
        }
        
        for (int j=0; j<seq.size(); j++) {
            System.out.print(seq.get(j) + ", ");
        }
        
        System.out.println();
    }
}
