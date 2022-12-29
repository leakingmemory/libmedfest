//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_OPPFBYTTEGRUPPE_H
#define LEGEMFEST_OPPFBYTTEGRUPPE_H

#include "Status.h"
#include "Byttegruppe.h"

class OppfByttegruppe {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    Byttegruppe byttegruppe;
public:
    OppfByttegruppe() : id(), tidspunkt(), status() {}
    OppfByttegruppe(const std::string &id, const std::string &tidspunkt, const Status &status,
                    const Byttegruppe &byttegruppe) :
            id(id), tidspunkt(tidspunkt), status(status), byttegruppe(byttegruppe) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] Byttegruppe GetByttegruppe() const;
};


#endif //LEGEMFEST_OPPFBYTTEGRUPPE_H
