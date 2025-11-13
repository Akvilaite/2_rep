#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <iomanip>
#include <algorithm>

#include "studentas.h"
#include "failai.h"
#include "rusiavimas.h"

using namespace std;
using namespace std::chrono;

static void GenerateTestFile(const string& filename, int n) {
    ofstream fout(filename);
    if (!fout) return;
    fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    for (int i = 1; i <= 15; ++i) fout << left << setw(6) << ("ND" + to_string(i));
    fout << left << setw(6) << "Egz." << '\n';
    mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<int> dist(1, 10);
    for (int i = 1; i <= n; ++i) {
        fout << left << setw(15) << ("Vardas" + to_string(i))
            << left << setw(15) << ("Pavarde" + to_string(i));
        for (int j = 0; j < 15; ++j) fout << left << setw(6) << dist(rng);
        fout << left << setw(6) << dist(rng) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testsCount = 0;
    cout << "Kiek skirtingu testu (failu) norite atlikti? ";
    while (!(cin >> testsCount) || testsCount <= 0) {
        cout << "Iveskite teigiama sveika skaiciu: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    vector<int> sizes;
    sizes.reserve(testsCount);
    for (int i = 0; i < testsCount; ++i) {
        int s;
        cout << "Iveskite studentu kieki testui " << (i + 1) << ": ";
        while (!(cin >> s) || s <= 0) {
            cout << "Iveskite teigiama sveika skaiciu: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        sizes.push_back(s);
    }

    const int runs = 3;

    cout << '\n';
    cout << left << setw(30) << "Vektoriai:" << '\n';

    for (int size : sizes) {
        string filename = "stud" + to_string(size) + ".txt";
        GenerateTestFile(filename, size);

        double file_sum = 0.0, sort_sum = 0.0, out_sum = 0.0;

        for (int r = 0; r < runs; ++r) {
            vector<Studentas> v;
            auto t0 = high_resolution_clock::now();
            v = Stud_from_file(filename);
            auto t1 = high_resolution_clock::now();
            double t_file = duration_cast<duration<double>>(t1 - t0).count();

            vector<Studentas> vcopy = v;

            auto t2 = high_resolution_clock::now();
            sort(vcopy.begin(), vcopy.end(), [](const Studentas& a, const Studentas& b) {
                return a.galVid() > b.galVid();
                });
            vector<Studentas> v_vargsiukai;
            Strategija3(vcopy, v_vargsiukai, 1);
            auto t3 = high_resolution_clock::now();
            double t_sort = duration_cast<duration<double>>(t3 - t2).count();

            auto t4 = high_resolution_clock::now();
            Spausdinti(v_vargsiukai, "vargsiukai_temp.txt");
            Spausdinti(vcopy, "kietiakai_temp.txt");
            auto t5 = high_resolution_clock::now();
            double t_out = duration_cast<duration<double>>(t5 - t4).count();

            file_sum += t_file;
            sort_sum += t_sort;
            out_sum += t_out;
        }

        double file_avg = file_sum / runs;
        double sort_avg = sort_sum / runs;
        double out_avg = out_sum / runs;
        double total = file_avg + sort_avg + out_avg;

        cout << "\nSu " << size << ":\n";
        cout << left << setw(25) << "Failo nuskaitymas"
            << right << setw(10) << fixed << setprecision(5) << file_avg << '\n';
        cout << left << setw(25) << "Rūšiavimas ir skirstymas"
            << right << setw(10) << fixed << setprecision(5) << sort_avg << '\n';
        cout << left << setw(25) << "Rezultatų išvedimas"
            << right << setw(10) << fixed << setprecision(5) << out_avg << '\n';
        cout << left << setw(25) << "Bendras laikas"
            << right << setw(10) << fixed << setprecision(5) << total << '\n';
    }

    cout << "\nTestavimas baigtas. Laikų vidurkiai apskaiciuoti ir atspausdinti.\n";
    return 0;
}
