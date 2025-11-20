#include "studentas.h"
#include <iostream>
#include <algorithm>
#include <limits>
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

    // mediana
    vector<int> tmp = paz_;
    sort(tmp.begin(), tmp.end());
    double med = 0.0;
    size_t n = tmp.size();
    if (n % 2 == 0) med = (tmp[n / 2 - 1] + tmp[n / 2]) / 2.0;
    else med = tmp[n / 2];
    galMed_ = med * 0.4 + egz_ * 0.6;
}


Studentas Stud_iv(int budas) {
    Studentas st;
    st.setVar("Vardas");
    st.setPav("Pavarde");
    st.setEgz(1);
    vector<int> paz = { 1,1,1 };
    st.setPaz(paz);
    st.computeGalutiniai();
    return st;
}
