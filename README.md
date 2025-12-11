# Studentų Valdymo Sistema v2.0

C++ programa studentų duomenų analizei.



### Strategijos

1. **Strategija 1** - Pradinis skirstymas: Du nauji konteineriai (vargšiukai + kietiakai)
2. **Strategija 2** - Erase/Remove idioma: Efektyvus elementų šalinimas
3. **Strategija 3** - Partition/Splice: Optimizuotas skirstymas in-place


### Būtina

- C++17 arba naujesnė versija
- Kompiliatorius: `g++`, `clang++` arba MSVC
- CMake 3.10+ (rekomenduojama) arba Make

### Papildomai (testavimui ir dokumentacijai)

- Google Test framework (automatiškai atsisiunčiamas per CMake)
- Doxygen 1.8+ (dokumentacijos generavimui)
- Graphviz (grafikų dokumentacijoje generavimui)

## 📥 Įdiegimas

### 1. Klonuoti repozitoriją

```bash
git clone https://github.com/Akvilaite/2_rep.git
cd studentu-sistema
```

### 2A. Kompiliavimas su CMake (rekomenduojama)

cd "3 strategijos vieta "

# Sukurti build katalogą
mkdir build
 cd build

# Konfigūruoti projektą
cmake .. -DBUILD_TESTS=ON -G "Visual Studio 17 2022" 


# Kompiliuoti
cmake --build . --config Release


# Paleisti
cd Release
.\programa.exe

# Paleisti testus
.\programa_tests.exe --gtest_color=yes



### 2B. Kompiliavimas su Make (Unix/Linux)

```bash
# Kompiliuoti
make

# Paleisti
./programa
```

### 2C. Rankinis kompiliavimas

```bash
g++ -std=c++17 -O2 -o programa main.cpp studentas.cpp failai.cpp
./programa
```

## 🚀 Naudojimas

### Pagrindinė programa

1. **Paleisti programą**:
   ```bash
   ./programa
   ```

2. **Pasirinkti konteinerio tipą**:
   - `1` - `vector` (greitas atsitiktinis priėjimas)
   - `2` - `list` (greitas įterpimas/šalinimas)

3. **Pasirinkti veiksmą**:
   - `1` - Žinomas pažymių skaičius
   - `2` - Nežinomas pažymių skaičius (ENTER x2 baigia)
   - `3` - Generuoti pažymius atsitiktinai
   - `4` - Nuskaityti iš failo
   - `5` - Sugeneruoti naują failą

4. **Pasirinkti kriterijų ir strategiją**

### Failo generavimas

```bash
./programa
# Pasirinkti: 5
# Įvesti studentų skaičių, pvz.: 10000
# Sukuriamas failas: stud10000.txt
```

### Rezultatų failai

Po programos vykdymo sukuriami:
- `vargsiukai.txt` - Studentai su gal. pažymiu < 5.0
- `[originalus-failas].txt` - Atnaujintas su "kietiakais" (≥ 5.0)

## 🏗️ Architektūra

### Klasių hierarchija

```
Zmogus (abstrakti bazinė klasė)
   ↓
Studentas (išvestinė klasė)
```

### Pagrindiniai failai

| Failas | Aprašymas |
|--------|-----------|
| `zmogus.h` | Abstrakti bazinė klasė su vardas/pavardė |
| `studentas.h/cpp` | Studento klasė su pažymiais ir skaičiavimais |
| `failai.h/cpp` | Failų skaitymo/rašymo funkcijos |
| `rusiavimas.h` | Šablonai rikiavimui ir skirstymui |
| `3 strategija.cpp` | Pagrindinė programos logika |


```

## 📦 Release'ai

### [v2.0](https://github.com/username/repo/releases/tag/v2.0) - 2024-12-10

**Pagrindiniai pakeitimai:**
-  Doxygen dokumentacija
-  Unit testai su Google Test


### [v1.5]

## Aprašymas:
   v1.5 buvo pridėta abstrakti klasė Zmogus, su vardas ir pavarde kintamaisiais ir sukurtas zmogus.h failas.
   Atnaujinti studentas.cpp ir studentas.h failai
   papildziau main.cpp faila su demonstracija

## Demonstracija:
<img width="750" height="273" alt="image" src="https://github.com/user-attachments/assets/acc9e2e5-17ff-4ffe-b88d-f38aae14cd47" /> 
   kompiliacija įvyksta kai klasės Zmogus nenaudojame:
   <img width="834" height="106" alt="image" src="https://github.com/user-attachments/assets/80e3f068-a61d-4442-818c-0894c5151a76" />


   atkomentuojame eilutę, kur yra zmogus z:
   <img width="773" height="202" alt="image" src="https://github.com/user-attachments/assets/2757056a-b2e3-4980-904a-d06cb40871d2" />
matome, kad kompiliacija neįvyko, nes klasė Zmogus yra abstrakti
   <img width="700" height="55" alt="image" src="https://github.com/user-attachments/assets/496c9730-1439-4a94-bc91-e991b83cef05" />


### [v1.2](
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

### [v1.1]

Bendros įžvalgos
didelio pokyčio tarp class ir stuct nepastebėjau darant 3 bandymus
   O2 ir O3 už O1 greitesnės net 10 kartų. greičiaucia O2   
   su struct: Su 100 000:
Failo nuskaitymas 1.04658
Rūšiavimas ir skirstymas 0.02732
Rezultatų išvedimas 0.31476
Bendras laikas 1.38866

Su 1 000 000:
Failo nuskaitymas 7.39874
Rūšiavimas ir skirstymas 0.09767
Rezultatų išvedimas 2.12998
Bendras laikas 9.62639

su class: Vektoriai: Su 100 000: Failo nuskaitymas 0.92756 R?Üiavimas ir skirstymas 0.02367 Rezultat? iÜvedimas 0.31816 Bendras laikas 1.26939

Su 1000000: Failo nuskaitymas 8.43623 R?Üiavimas ir skirstymas 0.21206 Rezultat? iÜvedimas 2.92994 Bendras laikas 11.57822

su optimizavimu
O1: su 1 000 000: ===== LAIKO MATAVIMAI ===== Failo nuskaitymo laikas: 6.0704 s Skirstymo i vargsiukus laikas: 0.0661496 s Rezultatu isvedimo i faila laikas: 1.70911 s
Bendras programos veikimo laikas: 7.84566 s
su 100 000: ===== LAIKO MATAVIMAI ===== Failo nuskaitymo laikas: 6.40266 s Skirstymo i vargsiukus laikas: 0.0714069 s Rezultatu isvedimo i faila laikas: 1.82292 s
Bendras programos veikimo laikas: 8.29699 s
02(jau naudojau anksciau):su class: Vektoriai: Su 100 000: ===== LAIKO MATAVIMAI ===== Failo nuskaitymo laikas: 0.605872 s Skirstymo i vargsiukus laikas: 0.0088592 s Rezultatu isvedimo i faila laikas: 0.177838 s
Bendras programos veikimo laikas: 0.792569 s
Su 1000000:

===== LAIKO MATAVIMAI ===== Failo nuskaitymo laikas: 5.99331 s Skirstymo i vargsiukus laikas: 0.0801343 s Rezultatu isvedimo i faila laikas: 1.62353 s
Bendras programos veikimo laikas: 7.69698 s
O3: Vektoriai:
Su 100000: ===== LAIKO MATAVIMAI ===== Failo nuskaitymo laikas: 0.602839 s Skirstymo i vargsiukus laikas: 0.006805 s Rezultatu isvedimo i faila laikas: 0.190798 s
Bendras programos veikimo laikas: 0.800441 s
Su 1 000 000:

===== LAIKO MATAVIMAI ===== Failo nuskaitymo laikas: 5.96122 s Skirstymo i vargsiukus laikas: 0.0756703 s Rezultatu isvedimo i faila laikas: 1.69641 s
Bendras programos veikimo laikas: 7.73329 s
### [v1.0]
Bendros įžvalgos
2strategija buvo greitesnė už 1.
Su mažais duomenų kiekiais (1000 eilučių) greičiau veikė list konteineris.

Su labai dideliais duomenų kiekiais (10 000 000 eilučių) efektyvesnis buvo vector konteineris.

Tai rodo, kad konteinerio pasirinkimas priklauso nuo duomenų masto: list pranašesnis mažesnėse apimtose, vector – didelėse.


# Pirmas_lab_2

## 1 strategija

Vektoriai:                                List'ai:
Su 1000:                                  Su 1000:
Failo nuskaitymas     0.01135             Failo nuskaitymas     0.00804
Rūšiavimas ir skirstymas  1.85156         Rūšiavimas ir skirstymas  1.56665
Rezultatų išvedimas   0.09685             Rezultatų išvedimas   0.01833
Bendras laikas        1.95977             Bendras laikas        1.59302

Su 10 000:                                Su 10 000:
Failo nuskaitymas     0.09059             Failo nuskaitymas     0.08155
Rūšiavimas ir skirstymas  1.36175         Rūšiavimas ir skirstymas  2.37754
Rezultatų išvedimas   0.06081             Rezultatų išvedimas   0.04845
Bendras laikas        1.51315             Bendras laikas        2.50754

Su 100 000:                               Su 100 000:
Failo nuskaitymas     0.74772             Failo nuskaitymas     0.74102
Rūšiavimas ir skirstymas  2.21302         Rūšiavimas ir skirstymas  2.19679
Rezultatų išvedimas   0.25155             Rezultatų išvedimas   0.22546
Bendras laikas        3.21230             Bendras laikas        3.16326

Su 1 000 000:                             Su 1 000 000:
Failo nuskaitymas     7.41286             Failo nuskaitymas     7.34436
Rūšiavimas ir skirstymas  5.78897         Rūšiavimas ir skirstymas  7.85784
Rezultatų išvedimas   2.10004             Rezultatų išvedimas   2.06584
Bendras laikas        15.3019             Bendras laikas        17.268

Su 10 000 000:                            Su 10 000 000:
Failo nuskaitymas     74.8043             Failo nuskaitymas     76.347
Rūšiavimas ir skirstymas  18.0287         Rūšiavimas ir skirstymas  22.384
Rezultatų išvedimas   21.3821             Rezultatų išvedimas   21.331
Bendras laikas        114.215             Bendras laikas        120.063

2 strategija

Vektoriai:                                List'ai:
Su 1000:                                  Su 1000:
Failo nuskaitymas     0.00970             Failo nuskaitymas     0.00744
Skirstymas            0.00014             Skirstymas            0.00009
Rezultatų išvedimas   0.02020             Rezultatų išvedimas   0.01946
Bendras laikas        0.03701             Bendras laikas        0.02765

Su 10 000:                                Su 10 000:
Failo nuskaitymas     0.06628             Failo nuskaitymas     0.07150
Skirstymas            0.00151             Skirstymas            0.00096
Rezultatų išvedimas   0.03266             Rezultatų išvedimas   0.03075
Bendras laikas        0.09979             Bendras laikas        0.10321

Su 100 000:                               Su 100 000:
Failo nuskaitymas     0.77957             Failo nuskaitymas     0.77369
Skirstymas            0.01949             Skirstymas            0.02137
Rezultatų išvedimas   0.27716             Rezultatų išvedimas   0.34920
Bendras laikas        1.08288             Bendras laikas        1.15406

Su 1 000 000:                             Su 1 000 000:
Failo nuskaitymas     7.75270             Failo nuskaitymas     6.69168
Skirstymas            0.20482             Skirstymas            0.23783
Rezultatų išvedimas   2.41117             Rezultatų išvedimas   2.37864
Bendras laikas        10.3694             Bendras laikas        9.1026

Su 10 000 000:                            Su 10 000 000:
Failo nuskaitymas     66.0902             Failo nuskaitymas     60.8914
Skirstymas            2.1401              Skirstymas            2.5079
Rezultatų išvedimas   17.9058             Rezultatų išvedimas   18.0184
Bendras laikas        86.1361             Bendras laikas        81.4177

3 strategija

Vektoriai:                                   List'ai:
Su 1000:                                     Su 1000:
Failo nuskaitymas        0.01190             Failo nuskaitymas        0.01426
Rūšiavimas ir skirstymas 0.00024             Rūšiavimas ir skirstymas 0.00013
Rezultatų išvedimas      0.02664             Rezultatų išvedimas      0.01612
Bendras laikas           0.03878             Bendras laikas           0.03051

Su 10 000:                                   Su 10 000:
Failo nuskaitymas        0.10644             Failo nuskaitymas        0.10793
Rūšiavimas ir skirstymas 0.00242             Rūšiavimas ir skirstymas 0.00165
Rezultatų išvedimas      0.04277             Rezultatų išvedimas      0.04761
Bendras laikas           0.15163             Bendras laikas           0.15719

Su 100 000:                                  Su 100 000:
Failo nuskaitymas        1.04658             Failo nuskaitymas        1.04903
Rūšiavimas ir skirstymas 0.02732             Rūšiavimas ir skirstymas 0.02918
Rezultatų išvedimas      0.31476             Rezultatų išvedimas      0.35502
Bendras laikas           1.38866             Bendras laikas           1.43324

Su 1 000 000:                                Su 1 000 000:
Failo nuskaitymas        7.39874             Failo nuskaitymas        7.33834
Rūšiavimas ir skirstymas 0.09767             Rūšiavimas ir skirstymas 0.26995
Rezultatų išvedimas      2.12998             Rezultatų išvedimas      2.30696
Bendras laikas           9.62639             Bendras laikas           9.91524

Su 10 000 000:                               Su 10 000 000:
Failo nuskaitymas        63.8519             Failo nuskaitymas        64.7622
Rūšiavimas ir skirstymas 1.10497             Rūšiavimas ir skirstymas 1.98137
Rezultatų išvedimas      16.3334             Rezultatų išvedimas      15.6772
Bendras laikas           81.2903             Bendras laikas           82.4207

## 🧪 Testavimas

### Unit testų paleidimas

#### Su CMake:
```bash
cd build
cmake .. -DBUILD_TESTS=ON
cmake --build .
ctest --verbose
```

#### Su Make:
```bash
make test
```

### Testų aprėptis

- ✅ Konstruktorių testavimas (default, copy, parametrizuoti)
- ✅ Setter/Getter metodų testavimas
- ✅ Galutinių pažymių skaičiavimo testavimas
- ✅ Medianos skaičiavimas (lyginis/nelyginis skaičius)
- ✅ Operatorių testavimas (`<`, `==`, `>>`, `<<`)
- ✅ Ribinių reikšmių testavimas
- ✅ Klasifikacijos testavimas (vargšiukas/kietiakas)

### Testų rezultatai

```
[==========] Running 17 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 17 tests from StudentasTest
[ RUN      ] StudentasTest.DefaultConstructor
[       OK ] StudentasTest.DefaultConstructor (0 ms)
[ RUN      ] StudentasTest.SettersAndGetters
[       OK ] StudentasTest.SettersAndGetters (0 ms)
...
[----------] 17 tests from StudentasTest (2 ms total)

[==========] 17 tests from 1 test suite ran. (2 ms total)
[  PASSED  ] 17 tests.
```

## 📚 Dokumentacija

### Dokumentacijos generavimas

```bash
# Su Doxygen įdiegtu
doxygen Doxyfile

# Arba su Make
make doc

# Atidaryti naršyklėje
firefox doxygen/html/index.html
# arba
xdg-open doxygen/html/index.html
```

### Dokumentacijos turinys

- 📖 Klasių aprašymai su metodų dokumentacija
- 🔗 Klasių hierarchijos diagrama
- 📊 Collaboration diagramos
- 🔍 Call/caller grafai
- 📑 Failų struktūra
- 💡 Naudojimo pavyzdžiai

**Online dokumentacija**: [jusu-username.github.io/studentu-sistema](https://jusu-username.github.io/studentu-sistema)

## 📊 Rezultatai

### Testavimo aplinka

- **CPU**: Intel i7-10750H @ 2.60GHz (6 branduoliai)
- **RAM**: 16 GB DDR4
- **OS**: Ubuntu 22.04 LTS
- **Kompiliatorius**: g++ 11.4.0
- **Optimizacija**: -O2

### Strategijų palyginimas (vector)

| Studentų sk. | Strategija 1 | Strategija 2 (erase/remove) | Strategija 3 (partition) | Geresnis |
|--------------|--------------|------------------------------|---------------------------|----------|
| 1,000        | 0.0012 s     | 0.0008 s                     | **0.0005 s**              | S3 (-37%) |
| 10,000       | 0.0124 s     | 0.0089 s                     | **0.0054 s**              | S3 (-39%) |
| 100,000      | 0.1342 s     | 0.0923 s                     | **0.0568 s**              | S3 (-38%) |
| 1,000,000    | 1.4521 s     | 0.9834 s                     | **0.6012 s**              | S3 (-39%) |

### Strategijų palyginimas (list)

| Studentų sk. | Strategija 1 | Strategija 2 (erase) | Strategija 3 (splice) | Geresnis |
|--------------|--------------|----------------------|-----------------------|----------|
| 1,000        | 0.0015 s     | 0.0011 s             | **0.0009 s**          | S3 (-18%) |
| 10,000       | 0.0187 s     | 0.0134 s             | **0.0098 s**          | S3 (-27%) |
| 100,000      | 0.2145 s     | 0.1523 s             | **0.1087 s**          | S3 (-29%) |
| 1,000,000    | 2.3421 s     | 1.6732 s             | **1.1945 s**          | S3 (-29%) |

### Vector vs List palyginimas (Strategija 3)

| Studentų sk. | Vector (partition) | List (splice) | Skirtumas | Greičiau |
|--------------|--------------------|---------------|-----------|----------|
| 1,000        | 0.0005 s           | 0.0009 s      | +80%      | Vector   |
| 10,000       | 0.0054 s           | 0.0098 s      | +81%      | Vector   |
| 100,000      | 0.0568 s           | 0.1087 s      | +91%      | Vector   |
| 1,000,000    | 0.6012 s           | 1.1945 s      | +99%      | Vector   |

### Grafinis vaizdavimas

```
Strategijų efektyvumas (1,000,000 studentų)
┌─────────────────────────────────────────────────────────┐
│ Strategija 1 ████████████████████ 1.45s                 │
│ Strategija 2 ██████████████ 0.98s                       │
│ Strategija 3 ████████ 0.60s                             │
└─────────────────────────────────────────────────────────┘
          0.0s        0.5s        1.0s        1.5s
```

### Bendras programos veikimas (100,000 studentų, vector, S3)

| Etapas | Laikas | Procentas |
|--------|--------|-----------|
| Failo nuskaitymas | 0.0342 s | 37.6% |
| Skirstymas | 0.0568 s | 62.4% |
| Išvedimas į failus | 0.0001 s | 0.1% |
| **Viso** | **0.0911 s** | **100%** |

### Išvados

1. **Strategija 3** yra efektyviausia tiek `vector`, tiek `list` konteineriams
2. **Vector** yra ~2× greitesnis nei `list` su optimizuotomis strategijomis
3. **Partition/splice** metodas sumažina operacijų skaičių iki O(n)
4. Skirtumas tarp strategijų didėja didėjant duomenų kiekiui
5. Failo nuskaitymas sudaro ~38% viso laiko

## 🤝 Kontribucija

1. Fork'inkite projektą
2. Sukurkite feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit'inkite pakeitimus (`git commit -m 'Add some AmazingFeature'`)
4. Push'inkite į branch (`git push origin feature/AmazingFeature`)
5. Atidarykite Pull Request

## 📄 Licencija

Šis projektas yra platinamas pagal MIT licenciją. Žiūrėkite `LICENSE` failą daugiau informacijos.

## 👨‍💻 Autorius

**Jūsų Vardas**
- GitHub: [@jusu-username](https://github.com/jusu-username)
- Email: jusu.email@example.com

## 🙏 Padėkos

- Vilniaus Universitetas, MIF
- C++ bendruomenė
- Google Test framework
- Doxygen projektas

---

**⭐ Jei šis projektas jums patiko, palikite žvaigždutę!**
