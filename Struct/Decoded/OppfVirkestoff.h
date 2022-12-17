//
// Created by sigsegv on 12/16/22.
//

#ifndef LEGEMFEST_OPPFVIRKESTOFF_H
#define LEGEMFEST_OPPFVIRKESTOFF_H

#include "Status.h"
#include "Virkestoff.h"

class OppfVirkestoff {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    Virkestoff virkestoff;
public:
    OppfVirkestoff() : id(), tidspunkt(), status(), virkestoff() {}
    OppfVirkestoff(const std::string &id, const std::string &tidspunkt, const Status &status, const Virkestoff &virkestoff) :
            id(id), tidspunkt(tidspunkt), status(status), virkestoff(virkestoff) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] Virkestoff GetVirkestoff() const;
};


#endif //LEGEMFEST_OPPFVIRKESTOFF_H
