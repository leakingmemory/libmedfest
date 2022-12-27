//
// Created by sigsegv on 12/27/22.
//

#ifndef LEGEMFEST_LENKE_H
#define LEGEMFEST_LENKE_H

#include <string>

class Lenke {
private:
    std::string beskrivelse;
    std::string www;
public:
    Lenke() : beskrivelse(), www() {}
    Lenke(const std::string &beskrivelse, const std::string &www) : beskrivelse(beskrivelse), www(www) {}
    [[nodiscard]] std::string GetBeskrivelse() const;
    [[nodiscard]] std::string GetWww() const;
};


#endif //LEGEMFEST_LENKE_H
