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
public:
    Markedsforingsinfo() : markedsforingsdato(), varenrUtgaende() {}
    Markedsforingsinfo(const std::string &markedsforingsdato, const std::string &varenrUtgaende) : markedsforingsdato(markedsforingsdato), varenrUtgaende(varenrUtgaende) {}
    [[nodiscard]] std::string GetMarkedsforingsdato() const;
    [[nodiscard]] std::string GetVarenrUtgaende() const;
};


#endif //LEGEMFEST_MARKEDSFORINGSINFO_H
