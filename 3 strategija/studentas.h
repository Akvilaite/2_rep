#pragma once
#include <string>
#include <vector>
#include <istream>

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
    ~Studentas() { var_.clear(); pav_.clear(); paz_.clear(); egz_ = 0; }

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
};


Studentas Stud_iv(int budas);

