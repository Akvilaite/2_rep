# Studentų Pažymių Sistema v1.2

## Aprašymas
Programa skirta studentų pažymių tvarkymui, galutinio balo skaičiavimui ir rūšiavimui.

---

## v1.2 Naujienos

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

## Programos veikimo instrukcija

### 1. Kompiliavimas
```bash
g++ -o programa main.cpp studentas.cpp failai.cpp rusiavimas.cpp -std=c++17
```

### 2. Paleidimas
```bash
./programa
```

### 3. Pavyzdys
```
Pasirinkite konteinerio tipą:
1 - vector
2 - list
> 1

Pasirinkite veiksmą:
1 - Žinomas pažymių skaičius
2 - Nežinomas pažymių skaičius
3 - Generuoti pažymius
4 - Nuskaityti iš failo
5 - Sugeneruoti naują failą
> 4

Įveskite failo pavadinimą: studentai.txt
```

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

---

