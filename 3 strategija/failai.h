/**
 * @file failai.h
 * @brief Failų operacijų deklaracijos
 * @author Jūsų vardas
 * @date 2024
 *
 * Šis failas apibrėžia funkcijas darbui su failais:
 * - Studentų duomenų nuskaitymas iš failų
 * - Naujų failų generavimas su atsitiktiniais duomenimis
 * - Rezultatų išvedimas į failus
 */

#pragma once
#include "studentas.h"
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iomanip>

using namespace std;

/**
 * @brief Nuskaito studentų duomenis iš failo
 * @param fname Failo pavadinimas
 * @return Vector studentų objektų
 *
 * Failo formatas:
 * - Pirmoje eilutėje: antraštė (praleidžiama)
 * - Kitose eilutėse: Vardas Pavardė ND1 ND2 ... NDn Egzaminas
 *
 * Pavyzdys:
 * @code
 * Vardas Pavarde ND1 ND2 ND3 Egz.
 * Jonas Jonaitis 8 9 7 10
 * @endcode
 *
 * @warning Jei failas neegzistuoja, grąžinamas tuščias vektorius
 */
vector<Studentas> Stud_from_file(const string& fname);

/**
 * @brief Generuoja naują failą su atsitiktiniais studentų duomenimis
 *
 * Funkcija:
 * - Paprašo įvesti studentų skaičių
 * - Sukuria failą pavadinimu "studN.txt" (N - studentų skaičius)
 * - Sugeneruoja 15 namų darbų pažymių ir egzamino pažymį kiekvienam
 * - Pažymiai: atsitiktiniai skaičiai nuo 1 iki 10
 *
 * Pavyzdys:
 * @code
 * GeneruotiFaila();
 * // Konsole: "Iveskite studentu kieki: "
 * // Įvedus 1000, sukuriamas failas "stud1000.txt"
 * @endcode
 *
 * @note Naudoja rand() funkciją, inicializuotą su srand(time(nullptr))
 */
void GeneruotiFaila();

/**
 * @brief Spausdina studentų duomenis į failą lentelės formatu
 * @tparam Container Konteinerio tipas (vector arba list)
 * @param Grupe Studentų konteineris
 * @param out_file Išvesties failo pavadinimas
 
 * Funkcija yra šabloninė ir veikia su:
 * - std::vector<Studentas>
 * - std::list<Studentas>
 * - kitais sekų konteineriais
 *
 * @note Jei failas negali būti atidarytas, funkcija grįžta be veiksmų
 */
template <typename Container>
void Spausdinti(const Container& Grupe, const string& out_file) {
    ofstream fout(out_file);
    if (!fout) return;

    // Antraštė
    fout << left << setw(15) << "Vardas"
        << left << setw(20) << "Pavarde"
        << right << setw(20) << "Galutinis (Vid.)"
        << right << setw(20) << "Galutinis (Med.)" << '\n';
    fout << string(75, '-') << '\n';

    // Duomenys
    for (const auto& st : Grupe) {
        fout << left << setw(15) << st.var()
            << left << setw(20) << st.pav()
            << right << setw(20) << fixed << setprecision(2) << st.galVid()
            << right << setw(20) << fixed << setprecision(2) << st.galMed() << '\n';
    }
}