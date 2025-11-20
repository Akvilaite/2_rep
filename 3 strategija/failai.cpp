#include "failai.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<Studentas> Stud_from_file(const string& fname) {
    ifstream fd(fname);
    vector<Studentas> grupe;
    if (!fd) {
        cout << "Nepavyko atidaryti failo.\n";
        return grupe;
    }
    string eilute;
    getline(fd, eilute);
    while (getline(fd, eilute)) {
        if (eilute.empty()) continue;
        istringstream iss(eilute);
        Studentas st;
        string vard, pav;
        iss >> vard >> pav;
        if (!iss) continue;
        vector<int> laik;
        int val;
        while (iss >> val) laik.push_back(val);
        if (laik.size() < 2) continue;
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
    srand(static_cast<unsigned int>(time(nullptr)));
    fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    for (int i = 1; i <= 15; i++) fout << left << setw(6) << ("ND" + to_string(i));
    fout << left << setw(6) << "Egz." << endl;
    for (int i = 1; i <= n; i++) {
        fout << left << setw(15) << ("Vardas" + to_string(i))
            << left << setw(15) << ("Pavarde" + to_string(i));
        for (int j = 0; j < 15; j++) fout << left << setw(6) << (rand() % 10 + 1);
        fout << left << setw(6) << (rand() % 10 + 1) << endl;
    }
    cout << "Failas '" << filename << "' sugeneruotas.\n";
}
