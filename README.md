# v1.2 specifikacijos:

<pre>
CPU Intel Core i9-12900H, 12-oji karta, 14 branduolių (6 P + 8 E), 20 gijų, 2.5 GHz bazinis dažnis, iki 5.0 GHz
RAM 16 GB DDR5-4800 MHz, 2× 8 GB 
SSD - 1 TB PCIe Gen 4 NVMe M.2 SSD 
<pre>


# programos paleidimas
</pre>
1. Atsisiųsti v1.0 release failus
2. atsidarius Pirmas_lab_2 pasirinkti, kurią strategiją naudosime.
3. Atidaryti .sln failą per Visual studio
4. rekomenduoju naudoti c++17 versiją
5. paleisti programą Realease x64 metodu.

arba

1. Atsidarykite terminalą (arba „Developer PowerShell“ jei naudojate Visual Studio).
2. įrašykite: cd "3 strategijos folderio išsaugojimo vieta"
3. toliau: mkdir build
cd build
4.toliau: cmake ..
5. įvykdome kompiliaciją:cmake --build . --config Release
6. pereiti 5 release: cd .\Release
7. visą kodą galime paleisti: ./3_strategija.exe
   testavimą su: ./testavimas.exe




Paleidus programą:
Pasirinkite, ar norite įvesti duomenis ranka, ar nuskaityti iš failo.
Įveskite studentų duomenis (vardas, pavardė, pažymiai, egzaminas).
Programa automatiškai:
suskaičiuos vidurkius ir medianas,
išrūšiuos studentus pagal pasirinktą strategiją (pvz. 3 strategija),
atskirs „vargšiukus“,
išves rezultatus ekrane ir į failus.
</pre>
  

## Aprašymas
Programa skirta studentų pažymių tvarkymui, galutinio balo skaičiavimui ir rūšiavimui.

---

### Realizuoti Rule of Three metodai

#### 1. Destruktorius `~Studentas()`
**Paskirtis:** Atlaisvina resursus prieš objekto sunaikinimą.

#### 2. Copy Konstruktorius `Studentas(const Studentas& other)`

**Paskirtis:** Sukuria naują objektą kaip esamo kopiją.

#### 3. Assignment Operatorius `operator=`

**Paskirtis:** Priskiria vieno objekto reikšmes kitam.

<img width="1680" height="475" alt="image" src="https://github.com/user-attachments/assets/c2d11158-544e-4d8a-97cb-9e36c152ce61" />
<img width="1076" height="517" alt="image" src="https://github.com/user-attachments/assets/3b075075-7624-4b02-a426-c963d4e0ae58" />


## Duomenų įvesties būdai

| Būdas | Aprašymas | Kodas |
|-------|-----------|-------|
| **1 - Žinomas pažymių skaičius** | Vartotojas įveda visus duomenis rankiniu būdu | `cin >> studentas` |
| **2 - Nežinomas pažymių skaičius** | Įvedimas su ENTER pabaiga | `readStudent(cin)` |
| **3 - Generuoti pažymius** | Automatinis generavimas | `rand()` funkcijos |
| **4 - Iš failo** | Nuskaitymas iš `.txt` failo | `ifstream >> studentas` |

---

## Duomenų išvesties būdai

| Būdas | Aprašymas | Kodas |
|-------|-----------|-------|
| **Į failą** | Išsaugojimas `.txt` faile | `ofstream << studentas` |


---


## Testavimo rezultatai

### Įvesties/Išvesties operatorių testavimas

| Testas | Rezultatas | Pastabos |
|--------|-----------|----------|
| `cin >> studentas` | Veikia | Nuskaito vardą, pavardę, pažymius |
| `cout << studentas` | Veikia | Išveda formatuotą informaciją |
| `ifstream >> studentas` | Veikia | Skaito iš failo |
| `ofstream << studentas` | Veikia | Rašo į failą |

### Rule of Three testavimas

| Metodas | Testas | Rezultatas |
|---------|--------|-----------|
| Destruktorius | Objekto sunaikinimas | Atmintis atlaisvinama |
| Copy konstruktorius | `Studentas s2(s1)` | Sukuria identiška kopija |
| Assignment | `s1 = s2` | Priskiria reikšmes teisingai |
| Self-assignment | `s1 = s1` | Apsauga veikia |
