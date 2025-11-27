#pragma once
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <iomanip>
#include <iostream>
#include "zmogus.h"



class Studentas {
private:
    std::string var_;
    std::string pav_;
    std::vector<int> paz_;
    int egz_{ 0 };
    double galVid_{ 0.0 };
    double galMed_{ 0.0 };

public:
    Studentas() = default;

    Studentas(std::istream& is) { readStudent(is); }


    ~Studentas() {
    }

    Studentas(const Studentas& other)
        : var_(other.var_), pav_(other.pav_), paz_(other.paz_),
        egz_(other.egz_), galVid_(other.galVid_), galMed_(other.galMed_) {
    }

    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            var_ = other.var_;
            pav_ = other.pav_;
            paz_ = other.paz_;
            egz_ = other.egz_;
            galVid_ = other.galVid_;
            galMed_ = other.galMed_;
        }
        return *this;
    }
        
    inline std::string var() const { return var_; }
    inline std::string pav() const { return pav_; }
    inline const std::vector<int>& paz() const { return paz_; }
    inline int egz() const { return egz_; }
    inline double galVid() const { return galVid_; }
    inline double galMed() const { return galMed_; }

    inline void setVar(const std::string& v) { var_ = v; }
    inline void setPav(const std::string& p) { pav_ = p; }
    inline void setPaz(const std::vector<int>& p) { paz_ = p; }
    inline void setEgz(int e) { egz_ = e; }
    inline void setGalVid(double g) { galVid_ = g; }
    inline void setGalMed(double g) { galMed_ = g; }

    void computeGalutiniai();
    std::istream& readStudent(std::istream& is);

    friend std::istream& operator>>(std::istream& is, Studentas& s);
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);

    bool operator<(const Studentas& other) const {
        if (pav_ != other.pav_) return pav_ < other.pav_;
        return var_ < other.var_;
    }

    bool operator==(const Studentas& other) const {
        return var_ == other.var_ && pav_ == other.pav_;
    }
};

Studentas Stud_iv(int budas);