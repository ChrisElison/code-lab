import java.util.*;

public class RandArray {
    public static String[] simpsons = {"Homer", "Marge", "Bart", "Lisa", "Maggie", "Abe", "Herb"};

    public static void main(String[] args) {
        listSimpsons(5);
    }

    public static void listSimpsons(int count) {
        Random rand = new Random();

        for (int i=0; i<count; i++) {
            System.out.println(simpsons[rand.nextInt(simpsons.length)]);
        }
    }
}
