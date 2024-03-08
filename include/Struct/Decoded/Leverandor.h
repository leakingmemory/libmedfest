//
// Created by sigsegv on 12/20/22.
//

#ifndef LEGEMFEST_LEVERANDOR_H
#define LEGEMFEST_LEVERANDOR_H

#include <string>

class Leverandor {
private:
    std::string navn;
    std::string adresse;
    std::string telefon;
public:
    Leverandor() : navn(), adresse(), telefon() {}
    Leverandor(const std::string &navn, const std::string &adresse, const std::string &telefon) :
               navn(navn), adresse(adresse), telefon(telefon) {}
    [[nodiscard]] std::string GetNavn() const;
    [[nodiscard]] std::string GetAdresse() const;
    [[nodiscard]] std::string GetTelefon() const;
};


#endif //LEGEMFEST_LEVERANDOR_H
