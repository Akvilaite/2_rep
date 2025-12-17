/**
 * @file studentas.h
 * @brief Studento klasės deklaracija
 * @author AKVILE BEINORIUTE
 * @date 2025
 */

#pragma once
#include "zmogus.h"
#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include <iomanip>
#include <iostream>

 /**
  * @class Studentas
  * @brief Klasė, reprezentuojanti studentą su pažymiais
  *
  * Paveldi iš Zmogus klasės ir papildomai saugo:
  * - Namų darbų pažymius
  * - Egzamino pažymį
  * - Apskaičiuotus galutinius įvertinimus (vidurkis ir mediana)
  */
class Studentas : public Zmogus {
private:
    std::vector<int> paz_;    ///< Namų darbų pažymių vektorius
    int egz_{ 0 };            ///< Egzamino pažymys
    double galVid_{ 0.0 };    ///< Galutinis įvertinimas (vidurkis)
    double galMed_{ 0.0 };    ///< Galutinis įvertinimas (mediana)

public:
    /**
     * @brief Numatytasis konstruktorius
     */
    Studentas() = default;

    /**
     * @brief Konstruktorius, nuskaitantis duomenis iš srauto
     * @param is Įvesties srautas
     */
    Studentas(std::istream& is) {
        readStudent(is);
    }

    /**
     * @brief Destruktorius
     */
    ~Studentas() {}

    /**
     * @brief Kopijavimo konstruktorius
     * @param other Studentas, kurį reikia nukopijuoti
     */
    Studentas(const Studentas& other)
        : Zmogus(other.var_, other.pav_),
        paz_(other.paz_),
        egz_(other.egz_),
        galVid_(other.galVid_),
        galMed_(other.galMed_) {
    }

    /**
     * @brief Priskyrimo operatorius
     * @param other Studentas, kurį reikia priskirti
     * @return Nuoroda į šį objektą
     */
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

    /**
     * @brief Grąžina namų darbų pažymius
     * @return Const nuoroda į pažymių vektorių
     */
    inline const std::vector<int>& paz() const { return paz_; }

    /**
     * @brief Grąžina egzamino pažymį
     * @return Egzamino pažymys
     */
    inline int egz() const { return egz_; }

    /**
     * @brief Grąžina galutinį įvertinimą (vidurkis)
     * @return Galutinis įvertinimas pagal vidurkį
     */
    inline double galVid() const { return galVid_; }

    /**
     * @brief Grąžina galutinį įvertinimą (mediana)
     * @return Galutinis įvertinimas pagal medianą
     */
    inline double galMed() const { return galMed_; }

    /**
     * @brief Nustato namų darbų pažymius
     * @param p Pažymių vektorius
     */
    inline void setPaz(const std::vector<int>& p) { paz_ = p; }

    /**
     * @brief Nustato egzamino pažymį
     * @param e Egzamino pažymys
     */
    inline void setEgz(int e) { egz_ = e; }

    /**
     * @brief Nustato galutinį įvertinimą (vidurkis)
     * @param g Galutinis įvertinimas
     */
    inline void setGalVid(double g) { galVid_ = g; }

    /**
     * @brief Nustato galutinį įvertinimą (mediana)
     * @param g Galutinis įvertinimas
     */
    inline void setGalMed(double g) { galMed_ = g; }

    /**
     * @brief Apskaičiuoja galutinius įvertinimus
     *
     * Skaičiuoja galutinį įvertinimą pagal formulę:
     * - Vidurkis: 0.4 * ND_vidurkis + 0.6 * Egzaminas
     * - Mediana: 0.4 * ND_mediana + 0.6 * Egzaminas
     */
    void computeGalutiniai();

    /**
     * @brief Nuskaito studento duomenis iš srauto
     * @param is Įvesties srautas
     * @return Nuoroda į srautą
     */
    std::istream& readStudent(std::istream& is);

    /**
     * @brief Atspausdina studento informaciją
     * @param os Išvesties srautas
     *
     * Realizuoja abstrakčią Zmogus::print() funkciją.
     */
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

    /**
     * @brief Įvesties operatorius
     * @param is Įvesties srautas
     * @param s Studentas
     * @return Nuoroda į srautą
     */
    friend std::istream& operator>>(std::istream& is, Studentas& s);

    /**
     * @brief Išvesties operatorius
     * @param os Išvesties srautas
     * @param s Studentas
     * @return Nuoroda į srautą
     */
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s) {
        s.print(os);
        return os;
    }

    /**
     * @brief Palyginimo operatorius (mažiau)
     * @param other Kitas studentas
     * @return true, jei šis studentas yra "mažesnis" (pagal pavardę, vardą)
     */
    bool operator<(const Studentas& other) const {
        if (pav_ != other.pav_) return pav_ < other.pav_;
        return var_ < other.var_;
    }

    /**
     * @brief Lygybės operatorius
     * @param other Kitas studentas
     * @return true, jei studentai vienodi (pagal vardą ir pavardę)
     */
    bool operator==(const Studentas& other) const {
        return var_ == other.var_ && pav_ == other.pav_;
    }
};

/**
 * @brief Funkcija studento įvedimui iš konsolės
 * @param budas Įvedimo būdas (1-3)
 * @return Sukurtas Studentas objektas
 *
 * Būdai:
 * - 1: Žinomas pažymių skaičius
 * - 2: Nežinomas pažymių skaičius (ENTER x2 baigia)
 * - 3: Generuoti pažymius atsitiktinai
 */
Studentas Stud_iv(int budas);