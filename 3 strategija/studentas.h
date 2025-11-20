#pragma once
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <iomanip>
#include <iostream>


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

    // Konstruktorius su istream
    Studentas(std::istream& is) { readStudent(is); }

    // ============= RULE OF THREE =============

    // 1. Destruktorius
   // Destruktorius
    ~Studentas() {
        std::cout << "Naikinamas studentas: " << var_ << " " << pav_ << "\n";
    }

    // Kopijavimo konstruktorius
    Studentas(const Studentas& other)
        : var_(other.var_), pav_(other.pav_), paz_(other.paz_),
        egz_(other.egz_), galVid_(other.galVid_), galMed_(other.galMed_) {
        std::cout << "Kopijavimo konstruktorius: sukurtas naujas studentas iš "
            << other.var_ << " " << other.pav_ << "\n";
    }

    // Kopijavimo priskyrimo operatorius
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            var_ = other.var_;
            pav_ = other.pav_;
            paz_ = other.paz_;
            egz_ = other.egz_;
            galVid_ = other.galVid_;
            galMed_ = other.galMed_;
            std::cout << "Kopijavimo priskyrimas: studentas "
                << var_ << " " << pav_
                << " perrašytas iš " << other.var_ << " " << other.pav_ << "\n";
        }
        return *this;
    }

    // ============= GETTERIAI =============
    inline std::string var() const { return var_; }
    inline std::string pav() const { return pav_; }
    inline const std::vector<int>& paz() const { return paz_; }
    inline int egz() const { return egz_; }
    inline double galVid() const { return galVid_; }
    inline double galMed() const { return galMed_; }

    // ============= SETTERIAI =============
    inline void setVar(const std::string& v) { var_ = v; }
    inline void setPav(const std::string& p) { pav_ = p; }
    inline void setPaz(const std::vector<int>& p) { paz_ = p; }
    inline void setEgz(int e) { egz_ = e; }
    inline void setGalVid(double g) { galVid_ = g; }
    inline void setGalMed(double g) { galMed_ = g; }

    // ============= PAGRINDINĖS FUNKCIJOS =============
    void computeGalutiniai();
    std::istream& readStudent(std::istream& is);

    // ============= ĮVESTIES/IŠVESTIES OPERATORIAI =============
    // Friend funkcijos leidžia pasiekti private narius
    friend std::istream& operator>>(std::istream& is, Studentas& s);
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);

    // ============= PAPILDOMI OPERATORIAI (naudingi rikiavimui) =============
    // Palyginimo operatorius (rikiavimui pagal pavardę, tada vardą)
    bool operator<(const Studentas& other) const {
        if (pav_ != other.pav_) return pav_ < other.pav_;
        return var_ < other.var_;
    }

    // Lygybės operatorius
    bool operator==(const Studentas& other) const {
        return var_ == other.var_ && pav_ == other.pav_;
    }
};

// ============= IŠORINĖS FUNKCIJOS =============
Studentas Stud_iv(int budas);