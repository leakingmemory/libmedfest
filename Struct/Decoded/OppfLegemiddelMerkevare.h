//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_OPPFLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_OPPFLEGEMIDDELMERKEVARE_H


#include "Oppf.h"
#include "LegemiddelMerkevare.h"

class OppfLegemiddelMerkevare : public Oppf {
private:
    LegemiddelMerkevare legemiddelMerkevare;
public:
    OppfLegemiddelMerkevare() :
            Oppf(), legemiddelMerkevare() {}
    OppfLegemiddelMerkevare(const Oppf &oppf, const LegemiddelMerkevare &legemiddelMerkevare) :
            Oppf(oppf), legemiddelMerkevare(legemiddelMerkevare) {}
    OppfLegemiddelMerkevare(const std::string &id, const std::string &tidspunkt, const Status &status, const LegemiddelMerkevare &legemiddelMerkevare) :
            Oppf(id, tidspunkt, status), legemiddelMerkevare(legemiddelMerkevare) {}
    [[nodiscard]] LegemiddelMerkevare GetLegemiddelMerkevare() const;
};


#endif //LEGEMFEST_OPPFLEGEMIDDELMERKEVARE_H
