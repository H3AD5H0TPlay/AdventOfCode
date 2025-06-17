// HU: A System.IO névteret importáljuk, hogy használhassuk a fájlkezelő osztályokat.
// EN: We import the System.IO namespace to use file handling classes.
using System.IO;

// HU: Kezdeti változók az emelet és a pozíció követésére.
// EN: Initial variables for tracking the floor and the position.
int current_floor = 0;
int pos = 0;

try
{
    // HU: A 'using' blokk biztosítja, hogy a StreamReader erőforrás (a megnyitott fájl)
    // EN: The 'using' block ensures that the StreamReader resource (the opened file)
    // HU: automatikusan és biztonságosan bezáródjon, amint a blokk végére érünk, még hiba esetén is.
    // EN: is automatically and safely closed as soon as we exit the block, even in case of an error.
    using (StreamReader sr = new StreamReader("input.txt"))
    {
        // HU: Beolvassuk az első sort a fájlból.
        // EN: We read the first line from the file.
        string line = sr.ReadLine();

        // HU: Ellenőrizzük, hogy a beolvasás sikeres volt-e (a fájl nem volt üres).
        // EN: We check if the read was successful (the file was not empty).
        if (line != null)
        {
            // HU: Végigmegyünk a beolvasott sor minden egyes 'c' karakterén.
            // EN: We loop through every single character 'c' of the read line.
            foreach (char c in line)
            {
                // HU: Növeljük a pozíciót minden karakter feldolgozása előtt (1-től induló indexelés).
                // EN: We increment the position before processing each character (for 1-based indexing).
                pos++;

                // HU: Az emelet változtatása a karakter alapján.
                // EN: Changing the floor based on the character.
                if (c == '(') current_floor++;
                else if (c == ')') current_floor--;

                // HU: Ellenőrizzük, hogy elértük-e a pincét.
                // EN: We check if we have reached the basement.
                if (current_floor == -1)
                {
                    // HU: Ha igen, azonnal kilépünk a ciklusból, mert az első ilyen pozíciót kerestük.
                    // EN: If yes, we break out of the loop immediately, because we were looking for the first such position.
                    break;
                }
            }
        }
    }
    // HU: Kiírjuk a pozíciót, ahol a ciklus megszakadt.
    // EN: We print the position at which the loop was broken.
    Console.WriteLine(pos);
}
// HU: Elkapjuk az esetleges hibákat (pl. ha a fájl nem található).
// EN: We catch any potential exceptions (e.g., if the file is not found).
catch (Exception e)
{
    Console.WriteLine("Exception: " + e.Message);
}