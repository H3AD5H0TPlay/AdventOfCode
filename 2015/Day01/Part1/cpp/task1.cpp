// HU: Egy nem-sztenderd, kényelmi header, ami szinte minden C++ standard könyvtárat tartalmaz.
// EN: A non-standard, convenience header that includes almost every C++ standard library.
#include <bits/stdc++.h>

// HU: Lehetővé teszi, hogy ne kelljen a std:: előtagot használni (pl. cout, string).
// EN: Allows the use of standard library components without the std:: prefix (e.g., cout, string).
using namespace std;


int main() {
    // HU: Kezdeti változó az aktuális emelet tárolására. A Mikulás a 0. emeletről indul.
    // EN: Initial variable to store the current floor. Santa starts at floor 0.
    int current_floor = 0;

    // HU: Megnyitjuk az input.txt fájlt olvasásra.
    // EN: We open the input.txt file for reading.
    ifstream file("input.txt");

    // HU: Ellenőrizzük, hogy a fájl megnyitása sikeres volt-e.
    // EN: We check if the file was opened successfully.
    if (!file) {
        cout << "File cannot be opened." << endl;
        return 1; // HU: Kilépés hibakóddal. / EN: Exit with an error code.
    }

    // HU: Egy stringstream segítségével hatékonyan beolvassuk a fájl teljes tartalmát.
    // EN: We efficiently read the entire content of the file using a stringstream.
    stringstream buffer;
    buffer << file.rdbuf();
    string text = buffer.str(); // HU: A beolvasott tartalom a 'text' stringbe kerül. / EN: The read content is stored in the 'text' string.

    // HU: A string hosszának lekérdezése a ciklushoz.
    // EN: Getting the length of the string for the loop.
    int N = text.length();

    // HU: Végigmegyünk a string minden egyes karakterén index alapján.
    // EN: We loop through every single character of the string by index.
    for (int i = 0; i < N; i++) {
        // HU: Ha a karakter egy nyitó zárójel, a Mikulás egy emeletet felmegy.
        // EN: If the character is an opening parenthesis, Santa goes up one floor.
        if(text[i] == '(') current_floor++;
        // HU: Ha a karakter egy záró zárójel, a Mikulás egy emeletet lemegy.
        // EN: If the character is a closing parenthesis, Santa goes down one floor.
        else if(text[i] == ')') current_floor--;
    }

    // HU: Bezárjuk a fájlt, miután végeztünk vele.
    // EN: We close the file after we are done with it.
    file.close();

    // HU: Kiírjuk a végső emeletet a konzolra.
    // EN: We print the final floor to the console.
    cout << current_floor << endl;

    // HU: A program sikeresen lefutott.
    // EN: The program executed successfully.
    return 0;
}