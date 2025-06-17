// HU: A fájlkezeléshez szükséges Java osztályok importálása.
// EN: Importing the necessary Java classes for file handling.
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

// HU: Az osztály neve megegyezik a fájl nevével (pl. Task2.java).
// EN: The class name must match the file name (e.g., Task2.java).
public class Task2 {
    // HU: A program belépési pontja, a 'main' metódus.
    // EN: The entry point of the program, the 'main' method.
    public static void main(String[] args) {
        
        // HU: Kezdeti változók az emelet és a pozíció követésére.
        // EN: Initial variables for tracking the floor and the position.
        int current_floor = 0;
        int pos = 0;
        
        // HU: Ez egy 'try-with-resources' blokk. A zárójelben létrehozott 'scanner'
        // EN: This is a 'try-with-resources' block. The 'scanner' created in the parentheses
        // HU: automatikusan bezáródik a blokk végén, így a 'scanner.close()' sorra nincs szükség.
        // EN: will be closed automatically at the end of the block, so the 'scanner.close()' line is not needed.
        try (Scanner scanner = new Scanner(new File("input.txt"))) {

            // HU: Beolvassuk a fájl következő (és egyetlen) sorát.
            // EN: We read the next (and only) line from the file.
            String data = scanner.nextLine();

            // HU: Végigmegyünk a beolvasott string minden karakterén.
            // EN: We loop through every character of the read string.
            for (char c : data.toCharArray()) {
                pos++;
                // HU: Az emelet változtatása a karakter alapján.
                // EN: Changing the floor based on the character.
                if(c == '(') current_floor++;
                else if(c == ')') current_floor--;

                // HU: Ellenőrizzük, hogy elértük-e a pincét.
                // EN: We check if we have reached the basement.
                if(current_floor == -1) break;
            }

            // HU: Kiírjuk a pozíciót, ahol a ciklus megszakadt.
            // EN: We print the position at which the loop was broken.
            System.out.println(pos);

        // HU: Elkapjuk a 'FileNotFoundException' hibát, ha az 'input.txt' nem létezik.
        // EN: We catch the 'FileNotFoundException' if 'input.txt' does not exist.
        } catch (FileNotFoundException e) {
            System.out.println("Error");
            // HU: Kiírjuk a hiba részletes leírását.
            // EN: We print the detailed stack trace of the error.
            e.printStackTrace();
        }
    }
}