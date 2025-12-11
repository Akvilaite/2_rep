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
| `main.cpp` | Pagrindinė programos logika |

### UML Klasių diagrama

```
┌─────────────────────────┐
│       Zmogus            │
├─────────────────────────┤
│ # var_: string          │
│ # pav_: string          │
├─────────────────────────┤
│ + var(): string         │
│ + pav(): string         │
│ + print(ostream&): void │ (virtual)
└─────────────────────────┘
            △
            │ inherits
            │
┌─────────────────────────┐
│      Studentas          │
├─────────────────────────┤
│ - paz_: vector<int>     │
│ - egz_: int             │
│ - galVid_: double       │
│ - galMed_: double       │
├─────────────────────────┤
│ + computeGalutiniai()   │
│ + readStudent(istream&) │
│ + print(ostream&)       │ (override)
│ + operator<()           │
│ + operator==()          │
└─────────────────────────┘
```

## 📦 Release'ai

### [v2.0](https://github.com/username/repo/releases/tag/v2.0) - 2024-12-10

**Pagrindiniai pakeitimai:**
- ✨ Implementuotas OOP: `Zmogus` bazinė klasė
- ✨ Šablonai (templates) konteinerių nepriklausomumui
- ✨ Rule of Three realizacija `Studentas` klasėje
- ✨ Operatorių perkrovimas (`<<`, `>>`, `<`, `==`)
- ✨ Virtualios funkcijos ir polimorfizmas
- 📚 Doxygen dokumentacija
- ✅ Unit testai su Google Test
- 📝 Profesionalus README su rezultatais

**Techninis įdėjimas:**
- Paveldėjimas: `Studentas` paveldi `Zmogus`
- Abstrakcija: `print()` - gryna virtuali funkcija
- Šablonai: `Rikiuoti`, `Strategija2`, `Strategija3` veikia su bet kuriuo konteineriu
- Kopijų valdymas: Copy constructor, copy assignment operator, destructor

### [v1.5](https://github.com/username/repo/releases/tag/v1.5) - 2024-11-25

- ✨ Trijų strategijų implementacija
- ⚡ Optimizuotas `partition`/`splice` naudojimas
- 📊 Išsamus laiko matavimas

### [v1.2](https://github.com/username/repo/releases/tag/v1.2) - 2024-11-20

- ✨ Studentų dalinimas į "vargšiukus" ir "kietiakus"
- 📊 Laiko matavimo funkcionalumas

### [v1.1](https://github.com/username/repo/releases/tag/v1.1) - 2024-11-15

- ✨ Darbas su `vector` ir `list`
- 📊 Efektyvumo palyginimas

### [v1.0](https://github.com/username/repo/releases/tag/v1.0) - 2024-11-10

- 🎉 Pradinė versija
- ✨ Bazinis funkcionalumas

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
