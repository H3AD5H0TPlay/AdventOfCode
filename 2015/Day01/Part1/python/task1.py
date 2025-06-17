# HU: Kezdeti emelet beállítása.
# EN: Setting the initial floor.
current_floor = 0

try:
    # HU: Fájl megnyitása és beolvasása.
    # EN: Opening and reading the file.
    with open("input.txt", 'r', encoding='utf-8') as f:
        instructions = f.read()

        # HU: Végigmegyünk az utasításokon.
        # EN: Looping through the instructions.
        for instruction in instructions:
            # HU: Ha az utasítás 'fel'...
            # EN: If the instruction is 'up'...
            if instruction == '(':
                # HU: ...közvetlenül növeljük az aktuális emelet számát.
                # EN: ...we directly increment the current floor number.
                current_floor += 1
            # HU: Ha az utasítás 'le'...
            # EN: If the instruction is 'down'...
            elif instruction == ')':
                # HU: ...közvetlenül csökkentjük az aktuális emelet számát.
                # EN: ...we directly decrement the current floor number.
                current_floor -= 1
    
    # HU: Kiírjuk az emeletet, ahol a Mikulás a végén áll. (232)
    # EN: We print the floor where Santa ends up. (232)
    print(current_floor)

except FileNotFoundError:
    print("Error: input.txt not found.\nHiba: input.txt nem található.")