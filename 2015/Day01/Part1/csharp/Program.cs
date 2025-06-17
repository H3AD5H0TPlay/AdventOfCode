// HU: A 'using' blokk automatikusan kezeli a fájl bezárását.
// EN: The 'using' block automatically handles the closing of the file.

int current_floor = 0;
try
{
    // HU: A StreamReader-t egy 'using' utasításba ágyazzuk.
    // EN: We embed the StreamReader in a 'using' statement.
    using (StreamReader sr = new StreamReader("input.txt"))
    {
        string line = sr.ReadLine();
        if (line != null) // HU: Ellenőrizzük, hogy nem üres-e a fájl. / EN: We check if the file is not empty.
        {
            foreach (char c in line)
            {
                if (c == '(') current_floor++;
                else if (c == ')') current_floor--;
            }
        }
    }
    Console.WriteLine(current_floor);
}
catch (Exception e)
{
    Console.WriteLine("Exception: " + e.Message);
}