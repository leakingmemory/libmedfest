//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_OPPFHANDELSVARE_H
#define LEGEMFEST_OPPFHANDELSVARE_H

#include "Status.h"
#include "Handelsvare.h"

class OppfHandelsvare {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
public:
    OppfHandelsvare() : id(), tidspunkt(), status() {}
    OppfHandelsvare(const std::string &id, const std::string &tidspunkt, const Status &status) :
            id(id), tidspunkt(tidspunkt), status(status) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
};

class OppfMedForbrMatr : public OppfHandelsvare {
private:
    MedForbrMatr medForbrMatr;
public:
    OppfMedForbrMatr() : OppfHandelsvare(), medForbrMatr() {}
    OppfMedForbrMatr(const std::string &id, const std::string &tidspunkt, const Status &status,
                     const MedForbrMatr &medForbrMatr) :
            OppfHandelsvare(id, tidspunkt, status), medForbrMatr(medForbrMatr) {}
    [[nodiscard]] MedForbrMatr GetMedForbrMatr() const;
};

class OppfNaringsmiddel : public OppfHandelsvare {
private:
    Naringsmiddel naringsmiddel;
public:
    OppfNaringsmiddel() : OppfHandelsvare(), naringsmiddel() {}
    OppfNaringsmiddel(const std::string &id, const std::string &tidspunkt, const Status &status,
                     const Naringsmiddel &naringsmiddel) :
            OppfHandelsvare(id, tidspunkt, status), naringsmiddel(naringsmiddel) {}
    [[nodiscard]] Naringsmiddel GetNaringsmiddel() const;
};

class OppfBrystprotese : public OppfHandelsvare {
private:
    Brystprotese brystprotese;
public:
    OppfBrystprotese() : OppfHandelsvare(), brystprotese() {}
    OppfBrystprotese(const std::string &id, const std::string &tidspunkt, const Status &status,
                      const Brystprotese &brystprotese) :
            OppfHandelsvare(id, tidspunkt, status), brystprotese(brystprotese) {}
    [[nodiscard]] Brystprotese GetBrystprotese() const;
};

#endif //LEGEMFEST_OPPFHANDELSVARE_H
