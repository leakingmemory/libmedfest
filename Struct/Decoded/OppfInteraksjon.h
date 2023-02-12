//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_OPPFINTERAKSJON_H
#define LEGEMFEST_OPPFINTERAKSJON_H

#include "OppfInteraksjonBase.h"
#include "Interaksjon.h"

class POppfInteraksjon;

class OppfInteraksjon : public OppfInteraksjonBase {
    friend POppfInteraksjon;
private:
    Interaksjon interaksjon;
public:
    OppfInteraksjon() : OppfInteraksjonBase(), interaksjon() {}
    OppfInteraksjon(const OppfInteraksjonBase &interaksjonBase, const Interaksjon &interaksjon) :
            OppfInteraksjonBase(interaksjonBase), interaksjon(interaksjon) {}
    [[nodiscard]] Interaksjon GetInteraksjon() const;
};


#endif //LEGEMFEST_OPPFINTERAKSJON_H
