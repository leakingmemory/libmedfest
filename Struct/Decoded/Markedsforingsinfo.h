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
public:
    Markedsforingsinfo() : markedsforingsdato(), varenrUtgaende(), midlUtgattDato() {}
    Markedsforingsinfo(const std::string &markedsforingsdato, const std::string &varenrUtgaende,
                       const std::string &midlUtgattDato) :
            markedsforingsdato(markedsforingsdato), varenrUtgaende(varenrUtgaende), midlUtgattDato(midlUtgattDato) {}
    [[nodiscard]] std::string GetMarkedsforingsdato() const;
    [[nodiscard]] std::string GetVarenrUtgaende() const;
    [[nodiscard]] std::string GetMidlUtgattDato() const;
};


#endif //LEGEMFEST_MARKEDSFORINGSINFO_H
