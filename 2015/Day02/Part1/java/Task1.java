// HU: A szükséges importok.
// EN: The necessary imports.
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Task1 {
    public static void main(String[] args) {
        // HU: A végső összeget tároló változó.
        // EN: The variable to store the final total.
        int total = 0;

        // HU: try-with-resources blokk a biztonságos fájlkezelésért.
        // EN: A try-with-resources block for safe file handling.
        // HU: A Scanner automatikusan bezáródik a blokk végén.
        // EN: The Scanner will be closed automatically at the end of the block.
        try (Scanner scanner = new Scanner(new File("input.txt"))) {

            // HU: Ez a standard 'while' ciklus fájlok olvasására Javában.
            // EN: This is the standard 'while' loop for reading files in Java.
            // HU: Addig fut, amíg a scanner tud új sort olvasni a fájlból.
            // EN: It runs as long as the scanner can read a new line from the file.
            while (scanner.hasNextLine()) {
                // HU: Beolvassuk az aktuális sort.
                // EN: We read the current line.
                String line = scanner.nextLine();
                
                // HU: A sort feldaraboljuk az 'x' karakter mentén egy string tömbbe.
                // EN: We split the line along the 'x' character into an array of strings.
                String[] parts = line.split("x");

                // HU: A szövegeket (string) számokká (integer) alakítjuk.
                // EN: We parse the strings into integers.
                int l = Integer.parseInt(parts[0]);
                int w = Integer.parseInt(parts[1]);
                int h = Integer.parseInt(parts[2]);

                // HU: Kiszámoljuk a doboz három különböző oldalának területét.
                // EN: We calculate the area of the three unique sides of the box.
                int side1 = l * w;
                int side2 = w * h;
                int side3 = h * l;

                // HU: Kiszámoljuk a doboz teljes felszínét.
                // EN: We calculate the total surface area of the box.
                int surface_area = 2 * (side1 + side2 + side3);

                // HU: A Math.min csak két értéket tud összehasonlítani, ezért egymásba kell őket ágyazni.
                // EN: Math.min can only compare two values, which is why they need to be nested.
                int slack = Math.min(side1, Math.min(side2, side3));

                // HU: A teljes összeghez hozzáadjuk a felszínt és a ráadást.
                // EN: We add the surface area and the slack to the running total.
                total += surface_area + slack;
            }

        // HU: Elkapjuk a 'FileNotFoundException' hibát, ha az 'input.txt' nem létezik.
        // EN: We catch the 'FileNotFoundException' if 'input.txt' does not exist.
        } catch (FileNotFoundException e) {
            System.out.println("Hiba: A fájl nem található.");
            e.printStackTrace();
        }

        // HU: A ciklus lefutása után kiírjuk a végső, összesített eredményt.
        // EN: After the loop finishes, we print the final, accumulated result.
        System.out.println(total);
    }
}