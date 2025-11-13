#include <iostream>
#include <fstream>
#include <vector>
#include <list>
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

    std::mt19937 rng(12345);   // FIKSUOTA SĖKLA !!!
    std::uniform_int_distribution<int> dist(1, 10);

    for (int i = 1; i <= n; ++i) {
        fout << left << setw(15) << ("Vardas" + to_string(i))
            << left << setw(15) << ("Pavarde" + to_string(i));

        for (int j = 0; j < 15; ++j)
            fout << left << setw(6) << dist(rng);

        fout << left << setw(6) << dist(rng) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testsCount = 0;
    cout << "Kiek testu? ";
    while (!(cin >> testsCount) || testsCount <= 0) {
        cout << "Iveskite teigiama skaiciu: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    vector<int> sizes(testsCount);
    for (int i = 0; i < testsCount; ++i) {
        cout << "Studentu kiekis testui " << i + 1 << ": ";
        while (!(cin >> sizes[i]) || sizes[i] <= 0) {
            cout << "Iveskite teigiama skaiciu: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    const int runs = 3;

    cout << "\nRezultatai (O1/O2/O3 optimizacijoms tinkami):\n";
    cout << left << setw(40) << "Vektoriai:" << "List'ai:\n";

    for (int size : sizes) {
        string filename = "stud" + to_string(size) + ".txt";

    
        GenerateTestFile(filename, size);

        double v_file_sum = 0, v_sort_sum = 0;
        double l_file_sum = 0, l_sort_sum = 0;

        vector<Studentas> last_v, last_v_args;
        list<Studentas> last_l, last_l_args;

        for (int r = 0; r < runs; ++r) {

       
            auto t0 = high_resolution_clock::now();
            vector<Studentas> v = Stud_from_file(filename);
            auto t1 = high_resolution_clock::now();
            v_file_sum += duration<double>(t1 - t0).count();

            auto t2 = high_resolution_clock::now();
            sort(v.begin(), v.end(),
                [](const Studentas& a, const Studentas& b) {
                    return a.galVid() > b.galVid();
                }
            );
            vector<Studentas> v_args;
            Strategija3(v, v_args, 1);
            auto t3 = high_resolution_clock::now();
            v_sort_sum += duration<double>(t3 - t2).count();

            if (r == runs - 1) { 
                last_v = v;
                last_v_args = v_args;
            }

          
            auto u0 = high_resolution_clock::now();
            vector<Studentas> tmp = Stud_from_file(filename);
            auto u1 = high_resolution_clock::now();
            l_file_sum += duration<double>(u1 - u0).count();

            list<Studentas> l(tmp.begin(), tmp.end());

            auto u2 = high_resolution_clock::now();
            l.sort([](const Studentas& a, const Studentas& b) {
                return a.galVid() > b.galVid();
                });
            list<Studentas> l_args;
            Strategija3(l, l_args, 1);
            auto u3 = high_resolution_clock::now();
            l_sort_sum += duration<double>(u3 - u2).count();

            if (r == runs - 1) {
                last_l = l;
                last_l_args = l_args;
            }
        }

      
        double v_file_avg = v_file_sum / runs;
        double v_sort_avg = v_sort_sum / runs;

        double l_file_avg = l_file_sum / runs;
        double l_sort_avg = l_sort_sum / runs;

        cout << "\nSu " << size << " irasų:\n";

        cout << left << setw(25) << "Failo nuskaitymas"
            << right << setw(10) << fixed << setprecision(6) << v_file_avg
            << "     "
            << left << setw(20) << "Failo nuskaitymas"
            << right << setw(10) << fixed << setprecision(6) << l_file_avg << "\n";

        cout << left << setw(25) << "Rusiavimas+skirstymas"
            << right << setw(10) << fixed << setprecision(6) << v_sort_avg
            << "     "
            << left << setw(20) << "Rusiavimas+skirstymas"
            << right << setw(10) << fixed << setprecision(6) << l_sort_avg << "\n";

    
        Spausdinti(last_v_args, "vargsiukai_vec_" + to_string(size) + ".txt");
        Spausdinti(last_v, "kietiakai_vec_" + to_string(size) + ".txt");
        Spausdinti(last_l_args, "vargsiukai_list_" + to_string(size) + ".txt");
        Spausdinti(last_l, "kietiakai_list_" + to_string(size) + ".txt");
    }

    cout << "\nTestavimas baigtas.\n";
    return 0;
}
