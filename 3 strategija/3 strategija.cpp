/**
 * @file main.cpp
 * @brief Pagrindinė programos valdymo logika
 * @author Jūsų vardas
 * @date 2024
 * @version 2.0
 *
 * Studentų valdymo sistema v2.0
 *
 * Ši programa leidžia:
 * - Įvesti studentų duomenis rankiniu būdu arba generuoti atsitiktinai
 * - Nuskaityti duomenis iš failų
 * - Apskaičiuoti galutinius pažymius (vidurkį ir medianą)
 * - Suskirstyti studentus į "vargšiukus" (< 5.0) ir "kietiakus" (>= 5.0)
 * - Matuoti operacijų vykdymo laiką
 * - Išsaugoti rezultatus į failus
 *
 * **Architektūra:**
 * - OOP principai: paveldėjimas (Zmogus → Studentas)
 * - Template programavimas: universalios funkcijos vector/list
 * - STL algoritmai: sort, partition, remove_if, splice
 * - Chrono biblioteka: tikslus laiko matavimas
 *
 * **Palaikomi konteineriai:**
 * - std::vector - greitas atsitiktinis priėjimas, efektyvus partition
 * - std::list - greitas įterpimas/šalinimas, efektyvus splice
 *
 * **Strategijos:**
 * 1. Strategija 1: Du nauji konteineriai (bazinis metodas)
 * 2. Strategija 2: Erase/remove idioma (klasikinis)
 * 3. Strategija 3: Partition/splice (optimizuotas)
 */

#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <string>
#include <cstdlib>

#include "studentas.h"
#include "failai.h"
#include "rusiavimas.h"

using namespace std;
using namespace std::chrono;

/**
 * @brief Pagrindinė programos funkcija
 * @return 0 - sėkminga, kitu atveju - klaida
 *
 * **Programos eiga:**
 *
 * 1. **Inicializacija:**
 *    - Išjungia C/C++ srauto sinchronizaciją (greičiui)
 *    - Inicializuoja random number generator
 *
 * 2. **Konteinerio pasirinkimas:**
 *    - 1: vector<Studentas>
 *    - 2: list<Studentas>
 *
 * 3. **Duomenų įvedimas:**
 *    - 1: Žinomas pažymių skaičius
 *    - 2: Nežinomas pažymių skaičius (ENTER baigia)
 *    - 3: Atsitiktinis generavimas
 *    - 4: Nuskaityti iš failo
 *    - 5: Sugeneruoti naują failą
 *
 * 4. **Rikiavimas:**
 *    - Pagal vardą/pavardę
 *    - Pagal galutinį vidurkį
 *    - Pagal galutinę medianą
 *
 * 5. **Skirstymas:**
 *    - Strategija 1: Pradinis metodas
 *    - Strategija 2: Erase/remove
 *    - Strategija 3: Partition/splice
 *
 * 6. **Rezultatų išvedimas:**
 *    - vargsiukai.txt - studentai su gal. < 5.0
 *    - [failas].txt - studentai su gal. >= 5.0
 *
 * 7. **Laiko matavimas:**
 *    - Failo nuskaitymo laikas
 *    - Skirstymo laikas
 *    - Išvedimo laikas
 *    - Bendras laikas
 *
 * **Laiko matavimo mechanizmas:**
 * @code
 * auto start = high_resolution_clock::now();
 * // ... operacija ...
 * auto end = high_resolution_clock::now();
 * double laikas = duration_cast<duration<double>>(end - start).count();
 * @endcode
 *
 * **Optimizacijos:**
 * - ios::sync_with_stdio(false) - greitesnis I/O
 * - Template funkcijos - compile-time optimizacija
 * - Move semantics - efektyvus duomenų perkėlimas
 * - In-place algoritmai - mažiau kopijavimo
 *
 * @note Programa automatiškai pasirenka efektyviausią algoritmą pagal konteinerio tipą
 * @warning Strategija 1 neimplementuota šioje versijoje (naudokite 2 arba 3)
 */
int main() {

    // ============================================
    // INICIALIZACIJA
    // ============================================

    /**
     * Išjungia C stdio ir C++ iostream sinchronizaciją.
     * Tai pagreitina I/O operacijas, bet negalima maišyti
     * printf/scanf su cout/cin.
     */
    ios::sync_with_stdio(false);

    /**
     * Inicializuoja random number generator su dabartiniu laiku.
     * Užtikrina skirtingus rezultatus kiekviename paleidime.
     */
    srand(static_cast<unsigned int>(time(nullptr)));

    // ============================================
    // KONTEINERIO PASIRINKIMAS
    // ============================================

    cout << "Pasirinkite konteinerio tipa:\n";
    cout << "1 - vector\n";
    cout << "2 - list\n";
    int konteinerisTipas;

    while (!(cin >> konteinerisTipas) || (konteinerisTipas != 1 && konteinerisTipas != 2)) {
        cout << "Neteisingas pasirinkimas. Bandykite dar karta: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // ============================================
    // LAIKO KINTAMIEJI
    // ============================================

    double failoLaikas = 0.0;      ///< Failo nuskaitymo laikas (s)
    double rusiavimoLaikas = 0.0;  ///< Studentų skirstymo laikas (s)
    double isvedimoLaikas = 0.0;   ///< Rezultatų išvedimo laikas (s)

    // ============================================
    // DUOMENŲ ĮVEDIMO BŪDO PASIRINKIMAS
    // ============================================

    cout << "\nPasirinkite veiksma:\n";
    cout << "1 - Zinomas pazymiu skaicius\n";
    cout << "2 - Nezinomas pazymiu skaicius (ENTER x2)\n";
    cout << "3 - Generuoti pazymius\n";
    cout << "4 - Nuskaityti duomenis is failo\n";
    cout << "5 - Sugeneruoti nauja faila\n";

    int budas;
    while (!(cin >> budas) || budas < 1 || budas > 5) {
        cout << "Neteisingas pasirinkimas: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Jei pasirinkta tik failų generavimas - baigti
    if (budas == 5) {
        GeneruotiFaila();
        return 0;
    }

    // ============================================
    // DUOMENŲ STRUKTŪRŲ DEKLARAVIMAS
    // ============================================

    vector<Studentas> vGrupe;  ///< Vector konteineris studentams
    list<Studentas> lGrupe;    ///< List konteineris studentams
    string fname;              ///< Failo pavadinimas

    // ============================================
    // DUOMENŲ ĮKROVIMAS
    // ============================================

    if (budas == 4) {
        // Nuskaityti iš failo
        cout << "Iveskite failo pavadinima: ";
        cin >> fname;

        auto start = high_resolution_clock::now();
        vGrupe = Stud_from_file(fname);
        auto end = high_resolution_clock::now();
        failoLaikas = duration_cast<duration<double>>(end - start).count();

        // Jei pasirinktas list - konvertuoti
        if (konteinerisTipas == 2) {
            lGrupe.assign(vGrupe.begin(), vGrupe.end());
            vGrupe.clear();
        }
    }
    else {
        // Rankinis įvedimas arba generavimas
        int n;
        cout << "Kiek studentu grupeje: ";
        while (!(cin >> n) || n <= 0) {
            cout << "Netinkamas skaicius. Bandykite dar karta: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        for (int i = 0; i < n; ++i) {
            Studentas st = Stud_iv(budas);
            if (konteinerisTipas == 1)
                vGrupe.push_back(st);
            else
                lGrupe.push_back(st);
        }
    }

    // Patikrinti, ar yra duomenų
    if ((konteinerisTipas == 1 && vGrupe.empty()) ||
        (konteinerisTipas == 2 && lGrupe.empty())) {
        cout << "Nerasta duomenu!\n";
        return 0;
    }

    // ============================================
    // KRITERIJAUS PASIRINKIMAS
    // ============================================

    int kriterijus;
    cout << "\nPasirinkite kriteriju studentu dalinimui:\n";
    cout << "1 - Pagal vidurki\n";
    cout << "2 - Pagal mediana\n";

    while (!(cin >> kriterijus) || (kriterijus != 1 && kriterijus != 2)) {
        cout << "Neteisingas pasirinkimas. Bandykite dar karta: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // ============================================
    // STRATEGIJOS PASIRINKIMAS
    // ============================================

    int strategija;
    cout << "\nPasirinkite strategija:\n";
    cout << "1 - Pirma strategija \n";
    cout << "2 - Klasikine versija (erase/remove)\n";
    cout << "3 - Optimizuota versija (partition/splice)\n";

    while (!(cin >> strategija) || (strategija != 2 && strategija != 3 && strategija != 1)) {
        cout << "Neteisingas pasirinkimas. Bandykite dar karta: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // ============================================
    // APDOROJIMAS SU VECTOR
    // ============================================

    if (konteinerisTipas == 1) {
        vector<Studentas> vargsiukai;

        // Rikiuoti
        Rikiuoti(vGrupe);

        // Skirstyti pagal strategiją
        auto startR = high_resolution_clock::now();
        if (strategija == 2)
            Strategija2(vGrupe, vargsiukai, kriterijus);
        else
            Strategija3(vGrupe, vargsiukai, kriterijus);
        auto endR = high_resolution_clock::now();
        rusiavimoLaikas = duration_cast<duration<double>>(endR - startR).count();

        // Išvesti rezultatus
        auto startI = high_resolution_clock::now();
        Spausdinti(vargsiukai, "vargsiukai.txt");
        if (budas == 4)
            Spausdinti(vGrupe, fname);
        auto endI = high_resolution_clock::now();
        isvedimoLaikas = duration_cast<duration<double>>(endI - startI).count();
    }

    // ============================================
    // APDOROJIMAS SU LIST
    // ============================================

    else {
        list<Studentas> vargsiukai;

        // Rikiuoti
        Rikiuoti(lGrupe);

        // Skirstyti pagal strategiją
        auto startR = high_resolution_clock::now();
        if (strategija == 2)
            Strategija2(lGrupe, vargsiukai, kriterijus);
        else
            Strategija3(lGrupe, vargsiukai, kriterijus);
        auto endR = high_resolution_clock::now();
        rusiavimoLaikas = duration_cast<duration<double>>(endR - startR).count();

        // Išvesti rezultatus
        auto startI = high_resolution_clock::now();
        Spausdinti(vargsiukai, "vargsiukai.txt");
        if (budas == 4)
            Spausdinti(lGrupe, fname);
        auto endI = high_resolution_clock::now();
        isvedimoLaikas = duration_cast<duration<double>>(endI - startI).count();
    }

    // ============================================
    // STATISTIKOS IŠVEDIMAS
    // ============================================

    double bendrasLaikas = failoLaikas + rusiavimoLaikas + isvedimoLaikas;

    cout << "\n===== LAIKO MATAVIMAI =====\n";
    cout << "Failo nuskaitymo laikas: " << failoLaikas << " s\n";
    cout << "Skirstymo i vargsiukus laikas: " << rusiavimoLaikas << " s\n";
    cout << "Rezultatu isvedimo i faila laikas: " << isvedimoLaikas << " s\n";
    cout << "---------------------------------\n";
    cout << "Bendras programos veikimo laikas: " << bendrasLaikas << " s\n";
    cout << "===========================\n";

    cout << "\nRezultatai issaugoti i faila: vargsiukai.txt\n";
    if (budas == 4)
        cout << "Atnaujintas failas: " << fname << " (liko tik kietiakai)\n";

    return 0;
}