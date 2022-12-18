//
// Created by sigsegv on 12/17/22.
//

#ifndef LEGEMFEST_OPPFVIRKESTOFFMEDSTYRKE_H
#define LEGEMFEST_OPPFVIRKESTOFFMEDSTYRKE_H

#include "VirkestoffMedStyrke.h"
#include "Status.h"

class OppfVirkestoffMedStyrke {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    VirkestoffMedStyrke virkestoffMedStyrke;
public:
    OppfVirkestoffMedStyrke() : id(), tidspunkt(), status(), virkestoffMedStyrke() {}
    OppfVirkestoffMedStyrke(const std::string &id, const std::string &tidspunkt, const Status &status,
                            const VirkestoffMedStyrke &virkestoffMedStyrke) :
            id(id), tidspunkt(tidspunkt), status(status), virkestoffMedStyrke(virkestoffMedStyrke) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] VirkestoffMedStyrke GetVirkestoffMedStyrke() const;
};


#endif //LEGEMFEST_OPPFVIRKESTOFFMEDSTYRKE_H
