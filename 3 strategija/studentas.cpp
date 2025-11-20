#include "studentas.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <sstream>

using namespace std;

// ======================
// Galutinio rezultato skaiciavimas
// ======================
void Studentas::computeGalutiniai() {
    if (paz_.empty()) {
        galVid_ = egz_;
        galMed_ = egz_;
        return;
    }

    // --- Vidurkis ---
    double suma = 0.0;
    for (int x : paz_) suma += x;
    double vid = suma / paz_.size();
    galVid_ = vid * 0.4 + egz_ * 0.6;

    // --- Mediana ---
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

// ==========================
// Studentų nuskaitymas (>>)
// Formatas: Vardas Pavarde Paz1 Paz2 ... Egz
// ==========================
std::istream& Studentas::readStudent(std::istream& is) {
    is >> var_ >> pav_;
    paz_.clear();

    string token;
    vector<int> numbers;

    // Skaitome visus likusius skaičius (paz ir egz)
    while (is >> token) {
        try {
            int x = stoi(token);
            numbers.push_back(x);
        }
        catch (...) {
            break;
        }
    }

    if (!numbers.empty()) {
        egz_ = numbers.back();
        numbers.pop_back();
        paz_ = numbers;
    }

    computeGalutiniai();
    return is;
}

std::istream& operator>>(std::istream& is, Studentas& s) {
    return s.readStudent(is);
}

std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << s.var() << " " << s.pav() << " | ND: ";

    for (size_t i = 0; i < s.paz().size(); ++i) {
        os << s.paz()[i];
        if (i < s.paz().size() - 1) os << ", ";
    }

    os << " | Egz: " << s.egz()
        << " | Gal(Vid): " << fixed << setprecision(2) << s.galVid()
        << " | Gal(Med): " << fixed << setprecision(2) << s.galMed();

    return os;
}

// ===============================
// Stud_iv — rankiniam įvedimui / generavimui
// ===============================
Studentas Stud_iv(int budas) {
    Studentas st;

    if (budas == 1) {
        // Žinomas pažymių kiekis
        cout << "Iveskite varda: ";
        string v; cin >> v;
        cout << "Iveskite pavarde: ";
        string p; cin >> p;

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
        // Nezinomas pazymiu kiekis (ENTER x2)
        cout << "Iveskite varda: ";
        string v; cin >> v;
        cout << "Iveskite pavarde: ";
        string p; cin >> p;

        st.setVar(v);
        st.setPav(p);

        cout << "Veskite pazymius (ENTER baigia):\n";

        vector<int> paz;
        string line;
        getline(cin, line); // gaudo \n

        while (true) {
            getline(cin, line);
            if (line.empty()) break;
            try {
                paz.push_back(stoi(line));
            }
            catch (...) {}
        }

        st.setPaz(paz);

        int egz;
        cout << "Egzamino pazymys: ";
        cin >> egz;

        st.setEgz(egz);
        st.computeGalutiniai();
    }
    else if (budas == 3) {
        cout << "Iveskite varda: ";
        string v; cin >> v;
        cout << "Iveskite pavarde: ";
        string p; cin >> p;

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
