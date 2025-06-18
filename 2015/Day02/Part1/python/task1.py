# HU: A helyes végeredmény, dokumentációs céllal.
# EN: The correct final answer, for documentation purposes.
# 1586300 - That's the right answer!

# HU: A teljes szükséges papírmennyiséget tároló változó inicializálása.
# EN: Initializing the variable that will store the total required amount of paper.
total = 0

# HU: Ideiglenes változók az oldalak területeinek. Ezeket a ciklus minden körben felülírja.
# EN: Temporary variables for the side areas. These are overwritten in each loop iteration.
part1 = 0
part2 = 0
part3 = 0

l = 0
w = 0
h = 0

# HU: Fájl megnyitása olvasásra a biztonságos 'with' blokkban, ami automatikusan bezárja a fájlt.
# EN: Opening the file for reading in a safe 'with' block, which closes the file automatically.
with open('input.txt', 'r') as file:
    # HU: Soronként végigmegyünk a fájlon. Minden sor egy ajándék méreteit tartalmazza.
    # EN: We loop through the file line by line. Each line contains the dimensions of one present.
    for line in file:
        # HU: Eltávolítjuk a felesleges szóközöket és az 'x' mentén feldaraboljuk a sort egy listába.
        # EN: We remove unnecessary whitespace and split the line by the 'x' character into a list.
        box = line.strip().split('x')
        
        # HU: A szövegként beolvasott méreteket egésszé (integer) alakítjuk.
        # EN: We convert the dimensions, read as text, into integers.
        l = int(box[0])
        w = int(box[1])
        h = int(box[2])

        # HU: Kiszámoljuk a doboz három különböző oldalának területét.
        # EN: We calculate the area of the three unique sides of the box.
        part1 = l*w
        part2 = w*h
        part3 = h*l

        # HU: Kiszámoljuk a doboz teljes felszínét a képlet (2*lw + 2*wh + 2*hl) alapján.
        # EN: We calculate the total surface area of the box based on the formula (2*lw + 2*wh + 2*hl).
        surface_area = 2*(part1+part2+part3)

        # HU: A teljes összeghez hozzáadjuk a felszínt és a ráadást (a legkisebb oldal területe).
        # EN: We add the surface area and the slack (the area of the smallest side) to the running total.
        total += surface_area + min(part1, part2, part3)

# HU: Kiírjuk a végső, összesített papírmennyiséget.
# EN: We print the final, total amount of paper.
print(total)