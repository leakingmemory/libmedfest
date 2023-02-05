//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_OPPFKODEVERK_H
#define LEGEMFEST_OPPFKODEVERK_H

#include "Oppf.h"
#include "Info.h"
#include "Element.h"
#include <vector>

class POppfKodeverk;

class OppfKodeverk : public Oppf {
    friend POppfKodeverk;
private:
    Info info;
    std::vector<Element> element;
public:
    OppfKodeverk() : Oppf(), info(), element() {}
    OppfKodeverk(const Oppf &oppf, const Info &info, const std::vector<Element> &element) :
            Oppf(oppf), info(info), element(element) {}
    OppfKodeverk(const std::string &id, const std::string &tidspunkt, const Status &status, const Info &info,
                 const std::vector<Element> &element) :
            Oppf(id, tidspunkt, status), info(info), element(element) {}
    [[nodiscard]] Info GetInfo() const;
    [[nodiscard]] std::vector<Element> GetElement() const;
};


#endif //LEGEMFEST_OPPFKODEVERK_H
