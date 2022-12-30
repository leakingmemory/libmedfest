//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_OPPFINTERAKSJONBASE_H
#define LEGEMFEST_OPPFINTERAKSJONBASE_H

#include "Status.h"

class OppfInteraksjonBase {
private:
    std::string id;
    std::string tidstempel;
    Status status;
public:
    OppfInteraksjonBase() : id(), tidstempel(), status() {}
    OppfInteraksjonBase(const std::string &id, const std::string &tidsstempel, const Status &status) :
            id(id), tidstempel(tidsstempel), status(status) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
};


#endif //LEGEMFEST_OPPFINTERAKSJONBASE_H
