# HU: Kezdeti változók beállítása.
# EN: Setting up the initial variables.
current_floor = 0  # HU: Az aktuális emelet, 0-ról indul. / EN: The current floor, starts from 0.
pos = 0            # HU: A karakter pozíciójának számlálója. A feladat 1-től indexel, ezért minden lépés után növeljük.
                   # EN: Counter for the character position. The puzzle uses 1-based indexing, so we increment after each step.

try:
    # HU: A fájl biztonságos megnyitása és beolvasása.
    # EN: Safely opening and reading the file.
    with open("input.txt", 'r', encoding='utf-8') as f:
        instructions = f.read()

        # HU: Végigmegyünk az utasítások (karakterek) sorozatán.
        # EN: We loop through the sequence of instructions (characters).
        for instruction in instructions:
            
            # HU: A pozíciót minden karakter feldolgozása ELŐTT növeljük, hogy az első karakter az 1. pozíció legyen.
            # EN: We increment the position counter BEFORE processing each character, so the first character is at position 1.
            pos += 1

            # HU: Ha a karakter '(', felmegyünk egy emeletet.
            # EN: If the character is '(', we go up one floor.
            if instruction == '(':
                current_floor += 1
            # HU: Ha a karakter ')', lemegyünk egy emeletet.
            # EN: If the character is ')', we go down one floor.
            elif instruction == ')':
                current_floor -= 1

            # HU: A feladat kulcsa: minden lépés UTÁN ellenőrizzük, hogy elértük-e a -1. emeletet.
            # EN: The key to the puzzle: AFTER each step, we check if we have reached the basement (floor -1).
            if current_floor == -1:
                # HU: Ha igen, azonnal megszakítjuk a ciklust, mert csak az első ilyen alkalom érdekel minket.
                # EN: If yes, we immediately break the loop, as we are only interested in the first time this happens.
                break
    
    # HU: Kiírjuk a pozíciót, ahol a ciklus megszakadt.
    # EN: We print the position at which the loop was broken.
    print(pos)

# HU: Hibakezelés, ha a fájl nem található.
# EN: Error handling in case the file is not found.
except FileNotFoundError:
    print("Error: input.txt not found.\nHiba: input.txt nem található.")