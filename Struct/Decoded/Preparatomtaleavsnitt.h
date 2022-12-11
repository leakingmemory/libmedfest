//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_PREPARATOMTALEAVSNITT_H
#define LEGEMFEST_PREPARATOMTALEAVSNITT_H

#include "ValueWithDistinguishedName.h"

class Preparatomtaleavsnitt {
private:
    ValueWithDistinguishedName avsnittoverskrift;
    std::string link;
public:
    Preparatomtaleavsnitt() : avsnittoverskrift(), link() {}
    Preparatomtaleavsnitt(const ValueWithDistinguishedName &avsnittoverskrift, const std::string &link) :
            avsnittoverskrift(avsnittoverskrift), link(link) {}
    [[nodiscard]] ValueWithDistinguishedName GetAvsnittoverskrift() const;
    [[nodiscard]] std::string GetLink() const;
};

#endif //LEGEMFEST_PREPARATOMTALEAVSNITT_H
