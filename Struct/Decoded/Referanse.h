//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_REFERANSE_H
#define LEGEMFEST_REFERANSE_H

#include <string>

class Referanse {
private:
    std::string kilde;
    std::string lenke;
public:
    Referanse() : kilde(), lenke() {}
    Referanse(const std::string &kilde, const std::string &lenke) : kilde(kilde), lenke(lenke) {}
    [[nodiscard]] std::string GetKilde() const;
    [[nodiscard]] std::string GetLenke() const;
};


#endif //LEGEMFEST_REFERANSE_H
