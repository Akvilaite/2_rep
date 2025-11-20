#include "studentas.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <sstream>
using namespace std;


void Studentas::computeGalutiniai() {
    if (paz_.empty()) {
        galVid_ = 0.0;
        galMed_ = 0.0;
        return;
    }
    double sum = 0.0;
    for (int x : paz_) sum += x;
    double vid = sum / paz_.size();
    galVid_ = vid * 0.4 + egz_ * 0.6;

   
    vector<int> tmp = paz_;
    sort(tmp.begin(), tmp.end());
    double med = 0.0;
    size_t n = tmp.size();
    if (n % 2 == 0) med = (tmp[n / 2 - 1] + tmp[n / 2]) / 2.0;
    else med = tmp[n / 2];
    galMed_ = med * 0.4 + egz_ * 0.6;
}

std::istream& Studentas::readStudent(std::istream& is) {
    is >> var_ >> pav_;
    paz_.clear();
    int pazymys;
    while (is >> pazymys) {
        if (pazymys >= 0 && pazymys <= 10) {
            paz_.push_back(pazymys);
        }
        else {
            break;  
        }
    }

    if (!paz_.empty()) {
        egz_ = paz_.back();
        paz_.pop_back();
    }

    computeGalutiniai();
    return is;
}


std::istream& operator>>(std::istream& is, Studentas& s) {
    return s.readStudent(is);
}

std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << s.var() << " " << s.pav();

    if (!s.paz().empty()) {
        os << " Pazymiai: ";
        for (size_t i = 0; i < s.paz().size(); ++i) {
            os << s.paz()[i];
            if (i < s.paz().size() - 1) os << ", ";
        }
    }

    os << " Egz: " << s.egz();
    os << " | Gal.(Vid.): " << fixed << setprecision(2) << s.galVid();
    os << " | Gal.(Med.): " << fixed << setprecision(2) << s.galMed();

    return os;
}


Studentas Stud_iv(int budas) {
    Studentas st;

    if (budas == 1 || budas == 2) {
        cout << "Iveskite studento duomenis (Vardas Pavarde Paz1 Paz2 ... Egz): ";
        cin >> st;  
    }
    else if (budas == 3) {
        
        st.setVar("Vardas" + to_string(rand() % 100));
        st.setPav("Pavarde" + to_string(rand() % 100));

        vector<int> paz;
        int n = 3 + rand() % 8; 
        for (int i = 0; i < n; ++i) {
            paz.push_back(1 + rand() % 10);
        }
        st.setPaz(paz);
        st.setEgz(1 + rand() % 10);
        st.computeGalutiniai();
    }
    else {
       
        st.setVar("Vardas");
        st.setPav("Pavarde");
        st.setEgz(1);
        vector<int> paz = { 1, 1, 1 };
        st.setPaz(paz);
        st.computeGalutiniai();
    }

    return st;
}