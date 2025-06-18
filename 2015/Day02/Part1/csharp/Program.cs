// HU: A System.IO névteret importáljuk a fájlkezelő osztályok (StreamReader) eléréséhez.
// EN: We import the System.IO namespace to access file handling classes (like StreamReader).
using System.IO;

// HU: Változók inicializálása. A jó gyakorlat szerint minden változónak adunk kezdőértéket.
// EN: Initializing variables. It's good practice to give an initial value to every variable.
int total = 0;
int part1 = 0;
int part2 = 0;
int part3 = 0;
int l = 0;
int w = 0;
int h = 0;
int surface_area = 0;

try
{
    // HU: A 'using' blokk biztosítja, hogy a fájlkezelő (sr) automatikusan bezáródjon a végén.
    // EN: The 'using' block ensures the file handler (sr) is closed automatically at the end.
    using (StreamReader sr = new StreamReader("input.txt"))
    {
        string line;
        // HU: A 'while' ciklus addig fut, amíg a ReadLine() tud új sort olvasni a fájlból.
        // EN: This 'while' loop runs as long as ReadLine() can read a new line from the file.
        while ((line = sr.ReadLine()) != null)
        {
            // HU: A sort feldaraboljuk az 'x' karakter mentén egy string tömbbe.
            // EN: We split the line along the 'x' character into an array of strings.
            string[] numbers = line.Split('x');

            // HU: A stringeket egésszé (integer) alakítjuk.
            // EN: We parse the strings into integers.
            l = Int32.Parse(numbers[0]);
            w = Int32.Parse(numbers[1]);
            h = Int32.Parse(numbers[2]);

            // HU: Kiszámoljuk a doboz három különböző oldalának területét.
            // EN: We calculate the area of the three unique sides of the box.
            part1 = l * w;
            part2 = w * h;
            part3 = h * l;

            // HU: Kiszámoljuk a teljes felszínt.
            // EN: We calculate the total surface area.
            surface_area = 2 * (part1 + part2 + part3);

            // HU: A teljes szükséges papírhoz hozzáadjuk a felszínt és a ráadást.
            // EN: We add the surface area and the slack to the total amount of paper needed.
            // HU: A Math.Min csak két értéket tud összehasonlítani, ezért egymásba kell őket ágyazni.
            // EN: Math.Min can only compare two values, which is why they need to be nested.
            total += surface_area + Math.Min(part1, Math.Min(part2, part3));
        }
    }

    // HU: A ciklus lefutása után kiírjuk a végső, összesített eredményt.
    // EN: After the loop finishes, we print the final, accumulated result.
    Console.WriteLine(total);
}
// HU: Hibakezelés, ha a fájl nem található vagy más hiba történik.
// EN: Error handling in case the file is not found or another error occurs.
catch (Exception e)
{
    Console.WriteLine("Hiba történt: " + e.Message);
}