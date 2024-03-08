//
// Created by sigsegv on 1/9/23.
//

#ifndef LEGEMFEST_OPPF_H
#define LEGEMFEST_OPPF_H

#include "Status.h"

class Oppf {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
public:
    Oppf() : id(), tidspunkt(), status() {}
    Oppf(const std::string &id, const std::string &tidspunkt, const Status &status) :
            id(id), tidspunkt(tidspunkt), status(status) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
};


#endif //LEGEMFEST_OPPF_H
