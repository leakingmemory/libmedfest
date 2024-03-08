//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_OPPFBYTTEGRUPPE_H
#define LEGEMFEST_OPPFBYTTEGRUPPE_H

#include "Oppf.h"
#include "Byttegruppe.h"

class POppfByttegruppe;

class OppfByttegruppe : public Oppf {
    friend POppfByttegruppe;
private:
    Byttegruppe byttegruppe;
public:
    OppfByttegruppe() : Oppf() {}
    OppfByttegruppe(const Oppf &oppf, const Byttegruppe &byttegruppe) :
            Oppf(oppf), byttegruppe(byttegruppe) {}
    OppfByttegruppe(const std::string &id, const std::string &tidspunkt, const Status &status,
                    const Byttegruppe &byttegruppe) :
            Oppf(id, tidspunkt, status), byttegruppe(byttegruppe) {}
    [[nodiscard]] Byttegruppe GetByttegruppe() const;
};


#endif //LEGEMFEST_OPPFBYTTEGRUPPE_H
