/**
 * @file failai.cpp
 * @brief Failų operacijų implementacija
 * @author Jūsų vardas
 * @date 2024
 */

#include "failai.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * @brief Nuskaito studentų duomenis iš tekstinio failo
 * @param fname Failo pavadinimas/kelias
 * @return Vector studentų objektų
 *
 * **Failo formatas:**
 * ```
 * Vardas    Pavarde    ND1  ND2  ...  NDn  Egz.
 * Jonas     Jonaitis   8    9    7    10
 * Petras    Petraitis  7    8    9    8
 * ```
 *
 * **Algoritmas:**
 * 1. Atidaro failą skaitymui
 * 2. Praleidžia pirmą eilutę (antraštė)
 * 3. Kiekvienai eilutei:
 *    - Nuskaito vardą ir pavardę
 *    - Nuskaito visus skaičius į laikiną vektorių
 *    - Paskutinis skaičius yra egzaminas
 *    - Kiti skaičiai - namų darbų pažymiai
 * 4. Sukuria Studentas objektus ir grąžina vektorių
 *
 * **Klaidų tvarkymas:**
 * - Jei failas neegzistuoja: išveda pranešimą ir grąžina tuščią vektorių
 * - Jei eilutė yra tuščia: praleidžia
 * - Jei eilutėje mažiau nei 2 skaičiai: praleidžia eilutę
 * - Jei nepavyksta nuskaityti vardo/pavardės: praleidžia eilutę
 *
 * @warning Jei failas nerastas, grąžina tuščią vektorių be exception
 * @note Funkcija taupo atmintį: skaito po vieną eilutę, ne visą failą
 *
 * Pavyzdys:
 * @code
 * vector<Studentas> studentai = Stud_from_file("studentai.txt");
 * if (studentai.empty()) {
 *     cout << "Failas tuscias arba nerastas\n";
 * }
 * @endcode
 *
 * @see Studentas::setPaz(), Studentas::setEgz(), Studentas::computeGalutiniai()
 */
vector<Studentas> Stud_from_file(const string& fname) {
    ifstream fd(fname);
    vector<Studentas> grupe;

    if (!fd) {
        cout << "Nepavyko atidaryti failo.\n";
        return grupe;
    }

    string eilute;
    // Praleidžiame antraštę
    getline(fd, eilute);

    // Skaitome duomenis
    while (getline(fd, eilute)) {
        if (eilute.empty()) continue;

        istringstream iss(eilute);
        Studentas st;
        string vard, pav;

        iss >> vard >> pav;
        if (!iss) continue; // Nepavyko nuskaityti vardo/pavardės

        // Skaitome visus skaičius
        vector<int> laik;
        int val;
        while (iss >> val)
            laik.push_back(val);

        // Turime turėti bent egzaminą ir bent vieną ND
        if (laik.size() < 2) continue;

        // Kuriame studento objektą
        st.setVar(vard);
        st.setPav(pav);
        st.setEgz(laik.back());
        laik.pop_back();
        st.setPaz(laik);
        st.computeGalutiniai();

        grupe.push_back(st);
    }

    return grupe;
}

/**
 * @brief Generuoja naują failą su atsitiktiniais studentų duomenimis
 *
 * **Veikimo eiga:**
 * 1. Paprašo vartotojo įvesti studentų skaičių
 * 2. Sukuria failą pavadinimu "studN.txt" (N - studentų skaičius)
 * 3. Įrašo antraštę
 * 4. Kiekvienam studentui:
 *    - Vardas: "VardasN" (N - studentų numeris)
 *    - Pavardė: "PavardeN"
 *    - Generuoja 15 atsitiktinių ND pažymių (1-10)
 *    - Generuoja atsitiktinį egzamino pažymį (1-10)
 *
 * **Išvesties failo formatas:**
 * ```
 * Vardas         Pavarde        ND1   ND2   ...   ND15  Egz.
 * Vardas1        Pavarde1       7     8     ...   9     10
 * Vardas2        Pavarde2       5     6     ...   8     7
 * ```
 *
 * **Naudojimas:**
 * - Testavimui su dideliais duomenų kiekiais
 * - Efektyvumo matavimams
 * - Automatiniam failų kūrimui
 *
 * @note Naudoja rand() - turėtų būti inicializuota su srand(time(nullptr))
 * @warning Jei failas negali būti sukurtas, išveda klaidos pranešimą
 *
 * **Generuojamų failų pavyzdžiai:**
 * - 1000 studentų → stud1000.txt
 * - 10000 studentų → stud10000.txt
 * - 100000 studentų → stud100000.txt
 *
 * Pavyzdys:
 * @code
 * srand(time(nullptr)); // Inicializuoti RNG
 * GeneruotiFaila();
 * // Konsolėje: "Iveskite studentu kieki: "
 * // Įvedus 1000: sukuriamas failas "stud1000.txt"
 * @endcode
 *
 * @complexity O(n * m), kur n - studentų skaičius, m - pažymių skaičius (15)
 */
void GeneruotiFaila() {
    int n;
    cout << "Iveskite studentu kieki: ";
    cin >> n;

    string filename = "stud" + to_string(n) + ".txt";
    ofstream fout(filename);

    if (!fout) {
        cerr << "Nepavyko sukurti failo!\n";
        return;
    }

    // Inicializuojame random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Antraštė
    fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    for (int i = 1; i <= 15; i++)
        fout << left << setw(6) << ("ND" + to_string(i));
    fout << left << setw(6) << "Egz." << endl;

    // Generuojame duomenis
    for (int i = 1; i <= n; i++) {
        fout << left << setw(15) << ("Vardas" + to_string(i))
            << left << setw(15) << ("Pavarde" + to_string(i));

        // 15 namų darbų pažymių
        for (int j = 0; j < 15; j++)
            fout << left << setw(6) << (rand() % 10 + 1);

        // Egzamino pažymys
        fout << left << setw(6) << (rand() % 10 + 1) << endl;
    }

    cout << "Failas '" << filename << "' sugeneruotas.\n";
}

// Template funkcija Spausdinti() jau implementuota failai.h faile