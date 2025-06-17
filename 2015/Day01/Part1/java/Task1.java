// HU: A fájlkezeléshez és a beolvasáshoz szükséges Java osztályok importálása.
// EN: Importing the necessary Java classes for file handling and input scanning.
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

// HU: Az osztály neve megegyezik a fájl nevével (Task1.java).
// EN: The class name matches the file name (Task1.java).
public class Task1 {
    // HU: A program belépési pontja, a 'main' metódus.
    // EN: The entry point of the program, the 'main' method.
    public static void main(String[] args) {
        
        // HU: Kezdeti változó az aktuális emelet tárolására. A Mikulás a 0. emeletről indul.
        // EN: Initial variable to store the current floor. Santa starts at floor 0.
        int current_floor = 0;
        
        // HU: A try-catch blokk a fájlkezelési hibák (pl. ha a fájl nem létezik) lekezelésére szolgál.
        // EN: The try-catch block is used to handle file handling errors (e.g., if the file doesn't exist).
        try {
            // HU: Létrehozunk egy Fájl objektumot, ami az 'input.txt'-re mutat.
            // EN: We create a File object that points to 'input.txt'.
            File file = new File("input.txt");
            
            // HU: Létrehozunk egy Scanner objektumot, ami a fájlunkat fogja olvasni.
            // EN: We create a Scanner object that will read our file.
            Scanner scanner = new Scanner(file);

            // HU: Beolvassuk a fájl következő (és egyetlen) sorát a 'data' string változóba.
            // EN: We read the next (and only) line from the file into the 'data' string variable.
            String data = scanner.nextLine();

            // HU: Végigmegyünk a beolvasott 'data' string minden egyes 'c' karakterén.
            // EN: We loop through every single character 'c' of the read 'data' string.
            for (char c : data.toCharArray()) {
                // HU: Ha a karakter '(', a Mikulás felmegy egy emeletet.
                // EN: If the character is '(', Santa goes up one floor.
                if(c == '(') current_floor++;
                // HU: Ha a karakter ')', a Mikulás lemegy egy emeletet.
                // EN: If the character is ')', Santa goes down one floor.
                else if(c == ')') current_floor--;
            }

            // HU: Fontos: miután végeztünk, bezárjuk a Scannert, hogy felszabadítsuk az erőforrást.
            // EN: Important: after we are done, we close the Scanner to free up the resource.
            scanner.close();

            // HU: Kiírjuk a végeredményt, azaz a végső emeletet a konzolra.
            // EN: We print the result, which is the final floor, to the console.
            System.out.println(current_floor);

        // HU: Elkapjuk a 'FileNotFoundException' hibát, ha az 'input.txt' nem létezik.
        // EN: We catch the 'FileNotFoundException' if 'input.txt' does not exist.
        } catch (FileNotFoundException e) {
            System.out.println("Error");
            // HU: Kiírjuk a hiba részletes leírását a hibakeresés megkönnyítésére.
            // EN: We print the detailed stack trace of the error to make debugging easier.
            e.printStackTrace();
        }
    }
}