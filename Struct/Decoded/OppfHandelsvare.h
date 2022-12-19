//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_OPPFHANDELSVARE_H
#define LEGEMFEST_OPPFHANDELSVARE_H

#include "Status.h"
#include "MedForbrMatr.h"

class OppfHandelsvare {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    MedForbrMatr medForbrMatr;
public:
    OppfHandelsvare() : id(), tidspunkt(), status(), medForbrMatr() {}
    OppfHandelsvare(const std::string &id, const std::string &tidspunkt, const Status &status,
                    const MedForbrMatr &medForbrMatr) :
            id(id), tidspunkt(tidspunkt), status(status), medForbrMatr(medForbrMatr) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] MedForbrMatr GetMedForbrMatr() const;
};


#endif //LEGEMFEST_OPPFHANDELSVARE_H
