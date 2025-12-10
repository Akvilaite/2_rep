/**
 * @file rusiavimas.h
 * @brief Šabloninės funkcijos studentų rikiavimui ir skirstymui
 * @author Jūsų vardas
 * @date 2024
 *
 * Šis failas apima:
 * - Universalias šablonas, veikiančias su vector ir list
 * - Tris skirtingas skirstymo strategijas
 * - Rikiavimo funkcijas pagal įvairius kriterijus
 */

#pragma once
#include "studentas.h"
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <type_traits>
#include <functional>

using namespace std;

/**
 * @brief Rikiuoja studentų konteinerį pagal pasirinktą kriterijų
 * @tparam Container Konteinerio tipas (vector<Studentas> arba list<Studentas>)
 * @param Grupe Studentų konteineris (perduodamas nuoroda - keičiamas vietoje)
 *
 * Funkcija leidžia vartotojui interaktyviai pasirinkti rikiavimo kriterijų:
 * - 1: Pagal vardą/pavardę (abėcėlės tvarka)
 * - 2: Pagal galutinį vidurkį (mažėjimo tvarka)
 * - 3: Pagal galutinę medianą (mažėjimo tvarka)
 *
 * @note Funkcija automatiškai pasirenka tinkamą algoritmą:
 * - std::sort() - vector (random access iterator)
 * - Container::sort() - list (bidirectional iterator)
 *
 * Pavyzdys:
 * @code
 * vector<Studentas> grupe;
 * // ... užpildyti grupę ...
 * Rikiuoti(grupe); // Interaktyvus rikiavimas
 * @endcode
 *
 * @complexity
 * - Vector: O(n log n) - std::sort
 * - List: O(n log n) - list::sort
 */
template <typename Container>
void Rikiuoti(Container& Grupe) {
    int pasirinkimas;
    cout << "\nPasirinkite pagal ka rikiuoti studentus:\n";
    cout << "1 - Pagal varda/pavarde\n";
    cout << "2 - Pagal galutini vidurki\n";
    cout << "3 - Pagal galutine mediana\n";

    while (!(cin >> pasirinkimas) || pasirinkimas < 1 || pasirinkimas > 3) {
        cout << "Neteisingas pasirinkimas. Bandykite dar karta: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Lambda funkcija palyginimui
    function<bool(const Studentas&, const Studentas&)> comp;

    if (pasirinkimas == 1) {
        comp = [](const Studentas& a, const Studentas& b) {
            if (a.var() == b.var()) return a.pav() < b.pav();
            return a.var() < b.var();
            };
    }
    else if (pasirinkimas == 2) {
        comp = [](const Studentas& a, const Studentas& b) {
            return a.galVid() > b.galVid();
            };
    }
    else {
        comp = [](const Studentas& a, const Studentas& b) {
            return a.galMed() > b.galMed();
            };
    }

    // Compile-time pasirinkimas tarp std::sort ir list::sort
    using Iter = decltype(begin(Grupe));
    using Cat = typename iterator_traits<Iter>::iterator_category;
    constexpr bool is_random_access = is_same<Cat, random_access_iterator_tag>::value;

    if constexpr (is_random_access)
        sort(Grupe.begin(), Grupe.end(), comp);
    else
        Grupe.sort(comp);
}

/**
 * @brief Strategija 2: Klasikinis erase/remove metodas
 * @tparam Container Konteinerio tipas
 * @param studentai Pradinis studentų konteineris (bus pakeistas - lieka tik kietiakai)
 * @param vargsiukai Išvesties konteineris vargšiukams (bus užpildytas)
 * @param kriterijus Kriterijus skirstymui (1 - vidurkis, 2 - mediana)
 *
 * Veikimo principas:
 * 1. Iteruoja per visus studentus
 * 2. Jei galutinis < 5.0, kopijuoja į vargsiukai ir pažymi šalinimui
 * 3. Pašalina pažymėtus elementus iš pradinio konteinerio
 *
 * **Vector atveju:**
 * - Naudoja std::remove_if idiomą
 * - Complexity: O(n) perkėlimas + O(n) erase
 *
 * **List atveju:**
 * - Naudoja manual iteravimą su erase
 * - Complexity: O(n) su konstantiniu šalinimu
 *
 * @warning Šis metodas sukuria kopijas elementų (push_back)
 * @see Strategija3 - optimizuotesnė alternatyva
 */
template <typename Container>
void Strategija2(Container& studentai, Container& vargsiukai, int kriterijus) {
    if constexpr (is_same<Container, vector<Studentas>>::value) {
        // Vector: naudojame remove_if idiomą
        auto it = remove_if(studentai.begin(), studentai.end(), [&](const Studentas& s) {
            double val = (kriterijus == 1 ? s.galVid() : s.galMed());
            if (val < 5.0) {
                vargsiukai.push_back(s);
                return true;
            }
            return false;
            });
        studentai.erase(it, studentai.end());
    }
    else {
        // List: manual iteravimas
        for (auto it = studentai.begin(); it != studentai.end();) {
            double val = (kriterijus == 1 ? it->galVid() : it->galMed());
            if (val < 5.0) {
                vargsiukai.push_back(*it);
                it = studentai.erase(it);
            }
            else {
                ++it;
            }
        }
    }
}

/**
 * @brief Strategija 3: Optimizuotas partition/splice metodas
 * @tparam Container Konteinerio tipas
 * @param studentai Pradinis studentų konteineris (bus pakeistas - lieka tik kietiakai)
 * @param vargsiukai Išvesties konteineris vargšiukams (bus užpildytas)
 * @param kriterijus Kriterijus skirstymui (1 - vidurkis, 2 - mediana)
 *
 * **Efektyviausias metodas!**
 *
 * Veikimo principas:
 *
 * **Vector atveju:**
 * 1. Naudoja std::partition - perskirsto elementus vietoje
 * 2. Kietiakai lieka pradžioje, vargšiukai - gale
 * 3. std::move perkeliama vargšiukus į atskirą konteinerį
 * 4. Pašalina vargšiukų dalį iš pradinio vektoriaus
 *
 * **List atveju:**
 * 1. Naudoja list::splice - perkeliama mazgus be kopijavimo
 * 2. Vargšiukai tiesiog "atkabinami" ir prijungiami prie naujo sąrašo
 * 3. Nepereina per duomenis, tik keičia rodykles
 *
 * @complexity
 * - Vector: O(n) partition + O(k) move (k - vargšiukų skaičius)
 * - List: O(n) iteration, bet tik rodyklių keitimas, ne kopijavimas
 *
 * @note Šis metodas yra **greitesnis** už Strategija2, ypač dideliems duomenų kiekiams
 *
 * Pavyzdys:
 * @code
 * vector<Studentas> studentai = {...};
 * vector<Studentas> vargsiukai;
 * Strategija3(studentai, vargsiukai, 1); // Pagal vidurkį
 * // Dabar: studentai turi tik >= 5.0, vargsiukai turi < 5.0
 * @endcode
 */
template <typename Container>
void Strategija3(Container& studentai, Container& vargsiukai, int kriterijus) {
    // Predikatas: true jei kietiakas (>= 5.0)
    auto pred = [&](const Studentas& s) {
        double val = (kriterijus == 1 ? s.galVid() : s.galMed());
        return val >= 5.0;
        };

    if constexpr (is_same_v<Container, vector<Studentas>>) {
        // Vector: partition algoritmas
        auto it = partition(studentai.begin(), studentai.end(), pred);
        // it dabar rodo į pirmą vargšiuką

        // Perkeli vargšiukus į atskirą konteinerį
        move(it, studentai.end(), back_inserter(vargsiukai));

        // Pašalina vargšiukus iš pradinio vektoriaus
        studentai.erase(it, studentai.end());
    }
    else if constexpr (is_same_v<Container, list<Studentas>>) {
        // List: splice metodas (efektyviausias!)
        for (auto it = studentai.begin(); it != studentai.end();) {
            double val = (kriterijus == 1 ? it->galVid() : it->galMed());
            if (val < 5.0) {
                // Splice: perkeliama mazgą be kopijavimo
                vargsiukai.splice(vargsiukai.end(), studentai, it++);
            }
            else {
                ++it;
            }
        }
    }
}

/**
 * @brief Strategija 1: Pradinis skirstymas į du naujus konteinerius
 * @tparam Container Konteinerio tipas
 * @param studentai Pradinis studentų konteineris (nekeičiamas)
 * @param vargsiukai Išvesties konteineris vargšiukams
 * @param kietiakai Išvesties konteineris kietiakams
 * @param kriterijus Kriterijus skirstymui (1 - vidurkis, 2 - mediana)
 *
 * Paprasčiausias metodas:
 * - Pereina per visus studentus
 * - Kopijuoja į atitinkamą konteinerį pagal galutinį pažymį
 * - Pradinis konteineris lieka nepakeistas
 *
 * @warning Naudoja daug atminties (3 konteineriai)
 * @note Šis metodas dažniausiai naudojamas kaip bazinė strategija
 *
 * @complexity O(n) iteravimas + O(n) kopijavimas
 */
template <typename Container>
void Strategija1(const Container& studentai,
    Container& vargsiukai,
    Container& kietiakai,
    int kriterijus)
{
    vargsiukai.clear();
    kietiakai.clear();

    for (const auto& st : studentai) {
        double val = (kriterijus == 1 ? st.galVid() : st.galMed());
        if (val < 5.0)
            vargsiukai.push_back(st);
        else
            kietiakai.push_back(st);
    }
}