//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_MARKEDSFORINGSINFO_H
#define LEGEMFEST_MARKEDSFORINGSINFO_H

#include <string>

class Markedsforingsinfo {
private:
    std::string markedsforingsdato;
public:
    Markedsforingsinfo() : markedsforingsdato() {}
    Markedsforingsinfo(const std::string &markedsforingsdato) : markedsforingsdato(markedsforingsdato) {}
    [[nodiscard]] std::string GetMarkedsforingsdato() const;
};


#endif //LEGEMFEST_MARKEDSFORINGSINFO_H
