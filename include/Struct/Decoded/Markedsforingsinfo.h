//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_MARKEDSFORINGSINFO_H
#define LEGEMFEST_MARKEDSFORINGSINFO_H

#include <string>

class Markedsforingsinfo {
private:
    std::string markedsforingsdato;
    std::string varenrUtgaende;
    std::string midlUtgattDato;
    std::string avregDato;
public:
    Markedsforingsinfo() : markedsforingsdato(), varenrUtgaende(), midlUtgattDato(), avregDato() {}
    Markedsforingsinfo(const std::string &markedsforingsdato, const std::string &varenrUtgaende,
                       const std::string &midlUtgattDato, const std::string &avregDato) :
            markedsforingsdato(markedsforingsdato), varenrUtgaende(varenrUtgaende), midlUtgattDato(midlUtgattDato),
            avregDato(avregDato) {}
    [[nodiscard]] std::string GetMarkedsforingsdato() const;
    [[nodiscard]] std::string GetVarenrUtgaende() const;
    [[nodiscard]] std::string GetMidlUtgattDato() const;
    [[nodiscard]] std::string GetAvregDato() const;
};


#endif //LEGEMFEST_MARKEDSFORINGSINFO_H
