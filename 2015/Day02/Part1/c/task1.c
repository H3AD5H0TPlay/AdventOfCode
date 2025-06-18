#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // HU: A teljes szükséges papírmennyiséget tároló változó.
    // EN: Variable to store the total amount of required paper.
    int total = 0;

    // HU: Fájlmutató deklarálása.
    // EN: Declaring a file pointer.
    FILE* file = fopen("input.txt", "r");

    // HU: Egy puffer a fájl egy sorának tárolására.
    // EN: A buffer to store one line from the file.
    char line[1500];

    // HU: Ellenőrizzük, hogy a fájl megnyitása sikeres volt-e.
    // EN: We check if the file was opened successfully.
    if (file != NULL) {
        
        // HU: Soronként végigmegyünk a fájlon.
        // EN: We loop through the file line by line.
        while (fgets(line, sizeof(line), file)) {
            // HU: Létrehozunk egy tömböt a 3 dimenziónak és egy számlálót.
            // EN: We create an array for the 3 dimensions and a counter.
            int dimensions[3];
            int i = 0;
            
            // HU: Az 'x' karakter mentén elkezdjük feldarabolni a sort.
            // EN: We start splitting the line along the 'x' character.
            char *token = strtok(line, "x");

            // HU: Addig megyünk, amíg a strtok talál új darabot (tokent).
            // EN: We loop as long as strtok finds a new piece (token).
            while(token != NULL) {
                // HU: Az atoi() (ASCII to Integer) függvénnyel a szöveget számmá alakítjuk
                // EN: With the atoi() (ASCII to Integer) function, we convert the text to a number
                // HU: és elmentjük a tömb 'i'-edik helyére.
                // EN: and save it to the 'i'-th position of the array.
                dimensions[i] = atoi(token);

                // HU: Növeljük a számlálót, hogy a következő szám a tömb következő helyére kerüljön.
                // EN: We increment the counter so the next number goes into the next position in the array.
                i++;

                // HU: Meghívjuk a strtok-ot NULL-lal, hogy a következő darabot keresse ugyanabban a stringben.
                // EN: We call strtok with NULL to find the next token in the same string.
                token = strtok(NULL, "x");
            }

            // HU: Miután a darabolás kész, a 'dimensions' tömb tartalmazza a 3 számot.
            // EN: After the splitting is done, the 'dimensions' array contains the 3 numbers.
            int l = dimensions[0];
            int w = dimensions[1];
            int h = dimensions[2];
            
            // HU: Kiszámoljuk az oldalak területeit.
            // EN: We calculate the areas of the sides.
            int side1 = l * w;
            int side2 = w * h;
            int side3 = h * l;

            // HU: Kiszámoljuk a teljes felszínt.
            // EN: We calculate the total surface area.
            int surface_area = 2 * (side1 + side2 + side3);

            // HU: Megkeressük a legkisebb oldalt a ráadáshoz.
            // EN: We find the smallest side for the slack.
            int slack = side1;
            if (side2 < slack) slack = side2;
            if (side3 < slack) slack = side3;
            
            // HU: Hozzáadjuk az aktuális doboz papírszükségletét a teljes összeghez.
            // EN: We add the paper requirement of the current box to the total sum.
            total += surface_area + slack;
        }

        // HU: Bezárjuk a fájlt.
        // EN: We close the file.
        fclose(file);
    }
    else {
        fprintf(stderr, "Unable to open file.");
    }

    // HU: Kiírjuk a végeredményt. A '%d\n' egy számot és egy sortörést ír ki.
    // EN: We print the final result. '%d\n' prints a number followed by a newline.
    printf("%d\n", total);

    return 0;
}