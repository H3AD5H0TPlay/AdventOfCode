// HU: Egy nem-sztenderd, kényelmi header, ami szinte minden C++ standard könyvtárat tartalmaz.
// EN: A non-standard, convenience header that includes almost every C++ standard library.
#include <bits/stdc++.h>

// HU: Lehetővé teszi, hogy ne kelljen a std:: előtagot használni (pl. cout, string).
// EN: Allows using standard library components without the std:: prefix (e.g., cout, string).
using namespace std;

int main() {
    // HU: Kezdeti változók az aktuális emelet és a karakter pozíciójának tárolására.
    // EN: Initial variables to store the current floor and the character position.
    int current_floor = 0; // HU: A Mikulás a 0. emeletről indul. / EN: Santa starts at floor 0.
    int pos = 0;           // HU: A pozíció, ami a karakterek sorszámát számolja. / EN: The position, which counts the character number.

    // HU: Megnyitjuk az input.txt fájlt olvasásra.
    // EN: We open the input.txt file for reading.
    ifstream file("input.txt");

    // HU: Ellenőrizzük, hogy a fájl megnyitása sikeres volt-e.
    // EN: We check if the file was opened successfully.
    if (!file) {
        cout << "File cannot be opened." << endl;
        return 1; // HU: Kilépés hibakóddal. / EN: Exit with an error code.
    }

    // HU: Egy stringstream segítségével hatékonyan beolvassuk a fájl teljes tartalmát egy stringbe.
    // EN: We efficiently read the entire content of the file into a single string using a stringstream.
    stringstream buffer;
    buffer << file.rdbuf();
    string text = buffer.str();

    // HU: A string hosszának lekérdezése (bár ebben a ciklusban nem használjuk, de jó gyakorlat).
    // EN: Getting the length of the string (although not used in this loop, it's good practice).
    int N = text.length();

    // HU: Végigmegyünk a string minden egyes karakterén index alapján.
    // EN: We loop through every single character of the string by index.
    for (int i = 0; i < N; i++) {
        // HU: A pozíciót növeljük minden karakter feldolgozása előtt (1-től induló indexelés).
        // EN: We increment the position before processing each character (for 1-based indexing).
        pos++;
        
        // HU: Ha a karakter egy nyitó zárójel, a Mikulás egy emeletet felmegy.
        // EN: If the character is an opening parenthesis, Santa goes up one floor.
        if(text[i] == '(') current_floor++;
        // HU: Ha a karakter egy záró zárójel, a Mikulás egy emeletet lemegy.
        // EN: If the character is a closing parenthesis, Santa goes down one floor.
        else if(text[i] == ')') current_floor--;

        // HU: Minden lépés után ellenőrizzük, hogy a Mikulás a pincébe (-1. emelet) ért-e.
        // EN: After each step, we check if Santa has entered the basement (floor -1).
        if(current_floor == -1) {
            // HU: Ha igen, azonnal kilépünk a ciklusból, mert az első ilyen pozíciót kerestük.
            // EN: If yes, we break out of the loop immediately, because we were looking for the first such position.
            break;
        }
    }

    // HU: Bezárjuk a fájlt.
    // EN: We close the file.
    file.close();

    // HU: Kiírjuk a pozíciót, ahol a Mikulás először a pincébe lépett.
    // EN: We print the position where Santa first entered the basement.
    cout << pos << endl;

    // HU: A program sikeresen lefutott.
    // EN: The program executed successfully.
    return 0;
}