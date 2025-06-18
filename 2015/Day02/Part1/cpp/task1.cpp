// HU: Egy nem-sztenderd, kényelmi header, ami szinte minden C++ standard könyvtárat tartalmaz.
// EN: A non-standard, convenience header that includes almost every C++ standard library.
#include <bits/stdc++.h>

// HU: Lehetővé teszi, hogy ne kelljen a std:: előtagot használni (pl. cout, string).
// EN: Allows using standard library components without the std:: prefix (e.g., cout, string).
using namespace std;

int main() {
    // HU: Változók inicializálása. Fontos minden változónak kezdőértéket adni.
    // EN: Initializing variables. It's important to give an initial value to every variable.
    int total = 0;
    int l=0, w=0, h=0;
    int side1=0, side2=0, side3=0;
    int surface_area = 0;

    // HU: Megnyitjuk az input.txt fájlt olvasásra.
    // EN: We open the input.txt file for reading.
    ifstream file("input.txt");

    // HU: Egy string változó a fájl egy sorának tárolására.
    // EN: A string variable to store one line of the file.
    string line;

    // HU: Ellenőrizzük, hogy a fájl megnyitása sikeres volt-e.
    // EN: We check if the file was opened successfully.
    if (file.is_open()) {
        // HU: Soronként végigmegyünk a fájlon, amíg van olvasható sor.
        // EN: We loop through the file line by line, as long as there are lines to read.
        while (getline(file, line)) {
            // HU: Létrehozunk egy stringstream objektumot az aktuális sorból a könnyebb darabolásért.
            // EN: We create a stringstream object from the current line for easier parsing.
            stringstream ss(line);

            // HU: Ideiglenes string változók a darabolt részeknek.
            // EN: Temporary string variables for the parsed parts.
            string l_str, w_str, h_str;
            
            // HU: A getline-t használjuk a 'ss' streamen, 'x' határoló karakterrel.
            // EN: We use getline on the 'ss' stream with 'x' as the delimiter.
            getline(ss, l_str, 'x');
            getline(ss, w_str, 'x');
            getline(ss, h_str); // HU: Az utolsó darab a sor végéig tart. / EN: The last part goes until the end of the line.

            // HU: A beolvasott szövegeket (string) számokká (integer) alakítjuk a 'stoi' függvénnyel.
            // EN: We convert the read texts (strings) into numbers (integers) with the 'stoi' function.
            l = stoi(l_str);
            w = stoi(w_str);
            h = stoi(h_str);

            // HU: Kiszámoljuk a doboz három különböző oldalának területét.
            // EN: We calculate the area of the three unique sides of the box.
            side1 = l*w;
            side2 = w*h;
            side3 = h*l;

            // HU: Kiszámoljuk a doboz teljes felszínét.
            // EN: We calculate the total surface area of the box.
            surface_area = 2 * (side1 + side2 + side3);

            // HU: A teljes összeghez hozzáadjuk a felszínt és a ráadást (a legkisebb oldal területe).
            // EN: We add the surface area and the slack (the area of the smallest side) to the running total.
            // HU: A min() függvényhez kapcsos zárójeleket használunk, hogy több elemből válasszon.
            // EN: We use curly braces for the min() function to choose from multiple elements.
            total += surface_area + min({side1, side2, side3});
        }

        // HU: Bezárjuk a fájlt.
        // EN: We close the file.
        file.close();

        // HU: Kiírjuk a végső, összesített papírmennyiséget.
        // EN: We print the final, total amount of paper.
        cout << total << endl;
    }
    else {
        // HU: Hibaüzenet, ha a fájl nem nyitható meg.
        // EN: Error message if the file cannot be opened.
        cerr << "Unable to open file" << endl;
    }

    // HU: A program sikeresen lefutott.
    // EN: The program executed successfully.
    return 0;
}