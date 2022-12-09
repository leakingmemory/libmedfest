//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_OPPFLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_OPPFLEGEMIDDELMERKEVARE_H


#include "Status.h"

class OppfLegemiddelMerkevare {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
public:
    OppfLegemiddelMerkevare() :
            id(), tidspunkt(), status() {}
    OppfLegemiddelMerkevare(const std::string &id, const std::string &tidspunkt, const Status &status) :
            id(id), tidspunkt(tidspunkt), status(status) {}
    std::string GetId();
    std::string GetTidspunkt();
    Status GetStatus();
};


#endif //LEGEMFEST_OPPFLEGEMIDDELMERKEVARE_H
