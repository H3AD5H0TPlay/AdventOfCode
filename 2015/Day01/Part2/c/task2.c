// HU: A sztenderd bemeneti/kimeneti és a standard könyvtári funkciók importálása.
// EN: Including the standard input/output and standard library headers.
#include <stdio.h>
#include <stdlib.h> // HU: Az exit() függvényhez / EN: For the exit() function

int main() {
    // HU: Egy nagy karaktertömb (C-stílusú string) a fájl tartalmának tárolására.
    // EN: A large character array (C-style string) to store the file's content.
    char c[1000000];
    
    // HU: Kezdeti változók az emelet és a pozíció követésére.
    // EN: Initial variables for tracking the floor and the position.
    int current_floor = 0;
    int pos = 0;
    
    // HU: Fájlmutató deklarálása.
    // EN: Declaring a file pointer.
    FILE *fptr;

    // HU: Megnyitjuk az input.txt fájlt olvasásra ('r' mód) és ellenőrizzük, hogy sikeres volt-e.
    // EN: We open the input.txt file for reading ('r' mode) and check if it was successful.
    if ((fptr = fopen("input.txt", "r")) == NULL) {
        printf("Error! File cannot be opened.");
        // HU: A program kilép 1-es hibakóddal, ha a fájlt nem lehet megnyitni.
        // EN: The program exits with error code 1 if the file cannot be opened.
        exit(1);
    }

    // HU: Beolvassuk a szöveget a fájlból a sortörés karakterig ('\n') a 'c' tömbbe.
    // EN: We read the text from the file into the 'c' array until a newline character ('\n') is encountered.
    fscanf(fptr, "%[^\n]", c);
    
    // HU: Egy 'for' ciklussal végigmegyünk a beolvasott 'c' string minden karakterén.
    // EN: We loop through every character of the read 'c' string with a 'for' loop.
    // HU: A ciklus addig fut, amíg el nem éri a string végét jelző '\0' karaktert.
    // EN: The loop runs until it reaches the '\0' character which marks the end of the string.
    for (int i = 0; c[i] != '\0'; i++) {
        // HU: Növeljük a pozíciót minden karakter feldolgozása előtt (1-től induló indexelés).
        // EN: We increment the position before processing each character (for 1-based indexing).
        pos++;
        
        // HU: Az 'i'-edik karaktert vizsgáljuk minden ciklusban.
        // EN: We examine the 'i'-th character in each iteration.
        if(c[i] == '(') {
            // HU: Ha a karakter '(', Santa felmegy egy emeletet.
            // EN: If the character is '(', Santa goes up one floor.
            current_floor++;
        }
        else if (c[i] == ')') {
            // HU: Ha a karakter ')', Santa lemegy egy emeletet.
            // EN: If the character is ')', Santa goes down one floor.
            current_floor--;
        }

        // HU: Minden lépés után ellenőrizzük, hogy a Mikulás a pincébe (-1. emelet) ért-e.
        // EN: After each step, we check if Santa has entered the basement (floor -1).
        if (current_floor == -1) {
            // HU: Ha igen, azonnal kilépünk a ciklusból, mert az első ilyen pozíciót kerestük.
            // EN: If yes, we break out of the loop immediately, because we were looking for the first such position.
            break;
        }
    }

    // HU: Kiírjuk a pozíciót, ahol a ciklus megszakadt.
    // EN: We print the position at which the loop was broken.
    printf("%d\n", pos);

    // HU: Bezárjuk a fájlt, hogy felszabadítsuk az erőforrást.
    // EN: We close the file to free up the resource.
    fclose(fptr);

    // HU: A program sikeresen lefutott.
    // EN: The program executed successfully.
    return 0;
}