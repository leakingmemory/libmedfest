//
// Created by sigsegv on 12/18/22.
//

#ifndef LEGEMFEST_OPPFLEGEMIDDELVIRKESTOFF_H
#define LEGEMFEST_OPPFLEGEMIDDELVIRKESTOFF_H

#include "Status.h"
#include "LegemiddelVirkestoff.h"

class OppfLegemiddelVirkestoff {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    LegemiddelVirkestoff legemiddelVirkestoff;
public:
    OppfLegemiddelVirkestoff() : id(), tidspunkt(), status(), legemiddelVirkestoff() {}
    OppfLegemiddelVirkestoff(const std::string &id, const std::string &tidspunkt, const Status &status,
                             const LegemiddelVirkestoff &legemiddelVirkestoff) :
            id(id), tidspunkt(tidspunkt), status(status), legemiddelVirkestoff(legemiddelVirkestoff) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] LegemiddelVirkestoff GetLegemiddelVirkestoff() const;
};


#endif //LEGEMFEST_OPPFLEGEMIDDELVIRKESTOFF_H
