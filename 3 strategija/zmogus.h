/**
 * @file zmogus.h
 * @brief Bazinė abstrakti klasė, reprezentuojanti žmogų
 * @author Jūsų vardas
 * @date 2024
 */

#pragma once
#include <string>
#include <vector>
#include <istream>
#include <ostream>

 /**
  * @class Zmogus
  * @brief Abstrakti bazinė klasė, sauganti bendrus žmogaus duomenis
  *
  * Ši klasė tarnauja kaip pagrindas kitoms klasėms (pvz., Studentas).
  * Saugo vardą ir pavardę, bei apibrėžia gryną virtualią funkciją print().
  */
class Zmogus {
protected:
    std::string var_;  ///< Žmogaus vardas
    std::string pav_;  ///< Žmogaus pavardė

public:
    /**
     * @brief Numatytasis konstruktorius
     */
    Zmogus() = default;

    /**
     * @brief Konstruktorius su parametrais
     * @param v Vardas
     * @param p Pavardė
     */
    Zmogus(const std::string& v, const std::string& p) : var_(v), pav_(p) {}

    /**
     * @brief Virtualus destruktorius
     */
    virtual ~Zmogus() = default;

    /**
     * @brief Grąžina vardą
     * @return Žmogaus vardas
     */
    inline std::string var() const { return var_; }

    /**
     * @brief Grąžina pavardę
     * @return Žmogaus pavardė
     */
    inline std::string pav() const { return pav_; }

    /**
     * @brief Nustato vardą
     * @param v Naujas vardas
     */
    inline void setVar(const std::string& v) { var_ = v; }

    /**
     * @brief Nustato pavardę
     * @param p Nauja pavardė
     */
    inline void setPav(const std::string& p) { pav_ = p; }

    /**
     * @brief Gryna virtuali funkcija spausdinimui
     * @param os Išvesties srautas
     *
     * Turi būti realizuota išvestinėse klasėse.
     */
    virtual void print(std::ostream& os) const = 0;
};