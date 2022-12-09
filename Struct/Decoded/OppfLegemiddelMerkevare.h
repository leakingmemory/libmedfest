//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_OPPFLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_OPPFLEGEMIDDELMERKEVARE_H


#include "Status.h"
#include "LegemiddelMerkevare.h"

class OppfLegemiddelMerkevare {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    LegemiddelMerkevare legemiddelMerkevare;
public:
    OppfLegemiddelMerkevare() :
            id(), tidspunkt(), status(), legemiddelMerkevare() {}
    OppfLegemiddelMerkevare(const std::string &id, const std::string &tidspunkt, const Status &status, const LegemiddelMerkevare &legemiddelMerkevare) :
            id(id), tidspunkt(tidspunkt), status(status), legemiddelMerkevare(legemiddelMerkevare) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] LegemiddelMerkevare GetLegemiddelMerkevare() const;
};


#endif //LEGEMFEST_OPPFLEGEMIDDELMERKEVARE_H
