#pragma once
#include "zmogus.h"
#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include <iomanip>
#include <iostream>

class Studentas : public Zmogus {
private:
    std::vector<int> paz_;
    int egz_{ 0 };
    double galVid_{ 0.0 };
    double galMed_{ 0.0 };

public:
    Studentas() = default;

    Studentas(std::istream& is) {
        readStudent(is);
    }

    ~Studentas() {}

    Studentas(const Studentas& other)
        : Zmogus(other.var_, other.pav_),
        paz_(other.paz_),
        egz_(other.egz_),
        galVid_(other.galVid_),
        galMed_(other.galMed_) {
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

    inline const std::vector<int>& paz() const { return paz_; }
    inline int egz() const { return egz_; }
    inline double galVid() const { return galVid_; }
    inline double galMed() const { return galMed_; }

    inline void setPaz(const std::vector<int>& p) { paz_ = p; }
    inline void setEgz(int e) { egz_ = e; }
    inline void setGalVid(double g) { galVid_ = g; }
    inline void setGalMed(double g) { galMed_ = g; }

    void computeGalutiniai();
    std::istream& readStudent(std::istream& is);

    void print(std::ostream& os) const override {
        os << var_ << " " << pav_
            << " | ND: ";
        for (size_t i = 0; i < paz_.size(); ++i) {
            os << paz_[i];
            if (i < paz_.size() - 1) os << ", ";
        }
        os << " | Egz: " << egz_
            << " | Gal(Vid): " << std::fixed << std::setprecision(2) << galVid_
            << " | Gal(Med): " << std::fixed << std::setprecision(2) << galMed_;
    }

    friend std::istream& operator>>(std::istream& is, Studentas& s);
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s) {
        s.print(os);
        return os;
    }

    bool operator<(const Studentas& other) const {
        if (pav_ != other.pav_) return pav_ < other.pav_;
        return var_ < other.var_;
    }

    bool operator==(const Studentas& other) const {
        return var_ == other.var_ && pav_ == other.pav_;
    }
};

Studentas Stud_iv(int budas);
