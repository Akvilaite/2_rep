#pragma once
#pragma once
#include <string>
#include <vector>
#include <istream>
#include <ostream>

class Zmogus {
protected:
    std::string var_;
    std::string pav_;

public:
    Zmogus() = default;
    Zmogus(const std::string& v, const std::string& p) : var_(v), pav_(p) {}

    virtual ~Zmogus() = default;

    inline std::string var() const { return var_; }
    inline std::string pav() const { return pav_; }

    inline void setVar(const std::string& v) { var_ = v; }
    inline void setPav(const std::string& p) { pav_ = p; }

    virtual void print(std::ostream& os) const = 0;
};
