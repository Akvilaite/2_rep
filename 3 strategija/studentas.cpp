/**
 * @file studentas.cpp
 * @brief Studento klasės implementacija
 * @author Jūsų vardas
 * @date 2024
 */

#include "studentas.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <sstream>

using namespace std;

/**
 * @brief Apskaičiuoja galutinius įvertinimus (vidurkį ir medianą)
 *
 * Algoritmas:
 * 1. Jei nėra namų darbų pažymių, galutinis = egzaminas
 * 2. Skaičiuoja namų darbų vidurkį
 * 3. Skaičiuoja namų darbų medianą:
 *    - Jei nelyginis skaičius: vidurinė reikšmė
 *    - Jei lyginis skaičius: dviejų vidurinių vidurkis
 * 4. Apskaičiuoja galutinį: 0.4 * ND + 0.6 * Egzaminas
 *
 * @note Automatiškai iškviečiama po pažymių nustatymo
 * @see setPaz(), setEgz()
 */
void Studentas::computeGalutiniai() {
    if (paz_.empty()) {
        galVid_ = egz_;
        galMed_ = egz_;
        return;
    }

    // Vidurkio skaičiavimas
    double suma = 0.0;
    for (int x : paz_)
        suma += x;
    double vid = suma / paz_.size();
    galVid_ = vid * 0.4 + egz_ * 0.6;

    // Medianos skaičiavimas
    vector<int> tmp = paz_;
    sort(tmp.begin(), tmp.end());
    double med = 0.0;
    size_t n = tmp.size();

    if (n % 2 == 0)
        med = (tmp[n / 2 - 1] + tmp[n / 2]) / 2.0;
    else
        med = tmp[n / 2];

    galMed_ = med * 0.4 + egz_ * 0.6;
}

/**
 * @brief Nuskaito studento duomenis iš įvesties srauto
 * @param is Įvesties srautas
 * @return Nuoroda į tą patį srautą (leidžia grandinį skaitymą)
 *
 * Tikėtinas formato:
 * @code
 * Vardas Pavarde ND1 ND2 ... NDn Egzaminas
 * @endcode
 *
 * Algoritmas:
 * 1. Nuskaito vardą ir pavardę
 * 2. Skaito skaičius, kol nepavyksta konvertuoti
 * 3. Paskutinis skaičius - egzaminas
 * 4. Kiti skaičiai - namų darbų pažymiai
 * 5. Automatiškai apskaičiuoja galutinius įvertinimus
 *
 * @warning Jei sraute nėra skaičių, egz_ ir paz_ lieka tušti/nuliui
 *
 * Pavyzdys:
 * @code
 * istringstream iss("Jonas Jonaitis 8 9 7 10");
 * Studentas s;
 * s.readStudent(iss);
 * // s.var() == "Jonas", s.egz() == 10, s.paz().size() == 3
 * @endcode
 */
std::istream& Studentas::readStudent(std::istream& is) {
    is >> var_ >> pav_;
    paz_.clear();

    string token;
    vector<int> numbers;

    // Skaitome visus skaičius
    while (is >> token) {
        try {
            int x = stoi(token);
            numbers.push_back(x);
        }
        catch (...) {
            break;  // Sutikome ne skaičių - baigti
        }
    }

    // Paskutinis skaičius - egzaminas
    if (!numbers.empty()) {
        egz_ = numbers.back();
        numbers.pop_back();
        paz_ = numbers;
    }

    computeGalutiniai();
    return is;
}

/**
 * @brief Įvesties operatoriaus perkrovimas
 * @param is Įvesties srautas
 * @param s Studentas objektas
 * @return Nuoroda į srautą
 *
 * Leidžia naudoti:
 * @code
 * Studentas s;
 * cin >> s;
 * @endcode
 */
std::istream& operator>>(std::istream& is, Studentas& s) {
    return s.readStudent(is);
}

// Išvesties operatorius jau realizuotas per virtualų print() studentas.h faile

/**
 * @brief Interaktyvi studento duomenų įvedimo funkcija
 * @param budas Įvedimo būdas (1, 2 arba 3)
 * @return Sukurtas Studentas objektas
 *
 * **Būdas 1: Žinomas pažymių skaičius**
 * - Paprašo įvesti vardą, pavardę
 * - Paklaus kiek bus pažymių
 * - Leidžia įvesti visus pažymius
 * - Paprašo egzamino pažymio
 *
 * **Būdas 2: Nežinomas pažymių skaičius**
 * - Paprašo įvesti vardą, pavardę
 * - Leidžia įvesti pažymius po vieną
 * - Tuščia eilutė (ENTER) baigia pažymių įvedimą
 * - Paprašo egzamino pažymio
 *
 * **Būdas 3: Atsitiktinis generavimas**
 * - Paprašo įvesti vardą, pavardę
 * - Paklaus kiek generuoti pažymių
 * - Sugeneruoja atsitiktinius pažymius (1-10)
 * - Sugeneruoja atsitiktinį egzamino pažymį
 *
 * @note Naudoja rand() funkciją (turėtų būti inicializuota su srand())
 * @warning Būdai 1 ir 2 reikalauja rankinės įvesties iš stdin
 *
 * Pavyzdys:
 * @code
 * Studentas s = Stud_iv(3); // Generuoti atsitiktinius duomenis
 * @endcode
 */
Studentas Stud_iv(int budas) {
    Studentas st;

    if (budas == 1) {
        // Žinomas pažymių skaičius
        cout << "Iveskite varda: ";
        string v;
        cin >> v;
        cout << "Iveskite pavarde: ";
        string p;
        cin >> p;
        st.setVar(v);
        st.setPav(p);

        int k;
        cout << "Kiek pazymiu: ";
        cin >> k;
        vector<int> paz(k);
        cout << "Iveskite pazymius: ";
        for (int i = 0; i < k; i++)
            cin >> paz[i];
        st.setPaz(paz);

        int egz;
        cout << "Egzamino pazymys: ";
        cin >> egz;
        st.setEgz(egz);
        st.computeGalutiniai();
    }
    else if (budas == 2) {
        // Nežinomas pažymių skaičius
        cout << "Iveskite varda: ";
        string v;
        cin >> v;
        cout << "Iveskite pavarde: ";
        string p;
        cin >> p;
        st.setVar(v);
        st.setPav(p);

        cout << "Veskite pazymius (ENTER baigia):\n";
        vector<int> paz;
        string line;
        getline(cin, line); // išvalyti buferį

        while (true) {
            getline(cin, line);
            if (line.empty()) break;
            try {
                paz.push_back(stoi(line));
            }
            catch (...) {
                // Neteisingas įvedimas - ignoruoti
            }
        }
        st.setPaz(paz);

        int egz;
        cout << "Egzamino pazymys: ";
        cin >> egz;
        st.setEgz(egz);
        st.computeGalutiniai();
    }
    else if (budas == 3) {
        // Atsitiktinis generavimas
        cout << "Iveskite varda: ";
        string v;
        cin >> v;
        cout << "Iveskite pavarde: ";
        string p;
        cin >> p;
        st.setVar(v);
        st.setPav(p);

        int k;
        cout << "Kiek pazymiu norite sugeneruoti: ";
        cin >> k;
        vector<int> paz(k);
        for (int i = 0; i < k; i++)
            paz[i] = rand() % 10 + 1;
        st.setPaz(paz);

        int egz = rand() % 10 + 1;
        st.setEgz(egz);
        st.computeGalutiniai();
    }

    return st;
}