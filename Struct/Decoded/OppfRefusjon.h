//
// Created by sigsegv on 12/23/22.
//

#ifndef LEGEMFEST_OPPFREFUSJON_H
#define LEGEMFEST_OPPFREFUSJON_H

#include <string>
#include "Status.h"

class OppfRefusjon {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
public:
    OppfRefusjon(const std::string &id, const std::string &tidspunkt, const Status &status) :
            id(id), tidspunkt(tidspunkt), status(status) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
};

#endif //LEGEMFEST_OPPFREFUSJON_H
