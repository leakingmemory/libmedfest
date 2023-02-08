//
// Created by sigsegv on 12/23/22.
//

#ifndef LEGEMFEST_OPPFREFUSJON_H
#define LEGEMFEST_OPPFREFUSJON_H

#include <string>
#include "Oppf.h"
#include "Refusjonshjemmel.h"

class POppfRefusjon;

class OppfRefusjon : public Oppf {
    friend POppfRefusjon;
private:
    Refusjonshjemmel refusjonshjemmel;
public:
    OppfRefusjon() : Oppf(), refusjonshjemmel() {}
    OppfRefusjon(const Oppf &oppf, const Refusjonshjemmel &refusjonshjemmel) :
            Oppf(oppf), refusjonshjemmel(refusjonshjemmel) {}
    OppfRefusjon(const std::string &id, const std::string &tidspunkt, const Status &status,
                 const Refusjonshjemmel &refusjonshjemmel) :
            Oppf(id, tidspunkt, status), refusjonshjemmel(refusjonshjemmel) {}
    [[nodiscard]] Refusjonshjemmel GetRefusjonshjemmel() const;
};

#endif //LEGEMFEST_OPPFREFUSJON_H
