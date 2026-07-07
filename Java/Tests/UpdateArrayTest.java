/*
 *  This code doesn't work, we can't update an element in a standard array!
 */

import java.util.*;

public class UpdateArrayTest {
    public static void main(String[] args) {
        String[] names = {"Homer", "Marge", "Bart", "Lisa", "Maggie"};
        Character[] myName = {'C', 'H', 'R', 'I', 'S'};

        System.out.println(names[0]);

        names[0] = "Flanders";

        System.out.println(names[0]);

        names.add("Milhouse");

        System.out.println(names[5]);
    }
}
