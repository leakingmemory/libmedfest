//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_OPPFHANDELSVARE_H
#define LEGEMFEST_OPPFHANDELSVARE_H

#include "Status.h"
#include "Handelsvare.h"
#include "Oppf.h"

class POppfMedForbrMatr;
class POppfNaringsmiddel;
class POppfBrystprotese;

class OppfHandelsvare : public Oppf {
public:
    OppfHandelsvare() : Oppf() {}
    OppfHandelsvare(const Oppf &oppf) : Oppf(oppf) {}
    OppfHandelsvare(const std::string &id, const std::string &tidspunkt, const Status &status) :
            Oppf(id, tidspunkt, status) {}
};

class OppfMedForbrMatr : public OppfHandelsvare {
    friend POppfMedForbrMatr;
private:
    MedForbrMatr medForbrMatr;
public:
    OppfMedForbrMatr() : OppfHandelsvare(), medForbrMatr() {}
    OppfMedForbrMatr(const Oppf &oppf, const MedForbrMatr &medForbrMatr) :
            OppfHandelsvare(oppf), medForbrMatr(medForbrMatr) {}
    OppfMedForbrMatr(const std::string &id, const std::string &tidspunkt, const Status &status,
                     const MedForbrMatr &medForbrMatr) :
            OppfHandelsvare(id, tidspunkt, status), medForbrMatr(medForbrMatr) {}
    [[nodiscard]] MedForbrMatr GetMedForbrMatr() const;
};

class OppfNaringsmiddel : public OppfHandelsvare {
    friend POppfNaringsmiddel;
private:
    Naringsmiddel naringsmiddel;
public:
    OppfNaringsmiddel() : OppfHandelsvare(), naringsmiddel() {}
    OppfNaringsmiddel(const Oppf &oppf, const Handelsvare &handelsvare) :
            OppfHandelsvare(oppf), naringsmiddel(handelsvare) {}
    OppfNaringsmiddel(const std::string &id, const std::string &tidspunkt, const Status &status,
                     const Naringsmiddel &naringsmiddel) :
            OppfHandelsvare(id, tidspunkt, status), naringsmiddel(naringsmiddel) {}
    [[nodiscard]] Naringsmiddel GetNaringsmiddel() const;
};

class OppfBrystprotese : public OppfHandelsvare {
    friend POppfBrystprotese;
private:
    Brystprotese brystprotese;
public:
    OppfBrystprotese() : OppfHandelsvare(), brystprotese() {}
    OppfBrystprotese(const Oppf &oppf, const Handelsvare &handelsvare) :
            OppfHandelsvare(oppf), brystprotese(handelsvare) {}
    OppfBrystprotese(const std::string &id, const std::string &tidspunkt, const Status &status,
                      const Brystprotese &brystprotese) :
            OppfHandelsvare(id, tidspunkt, status), brystprotese(brystprotese) {}
    [[nodiscard]] Brystprotese GetBrystprotese() const;
};

#endif //LEGEMFEST_OPPFHANDELSVARE_H
