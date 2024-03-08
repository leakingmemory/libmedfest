//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_PREPARATOMTALEAVSNITT_H
#define LEGEMFEST_PREPARATOMTALEAVSNITT_H

#include "ValueWithDistinguishedName.h"
#include "Lenke.h"

class Preparatomtaleavsnitt {
private:
    ValueWithDistinguishedName avsnittoverskrift;
    Lenke lenke;
public:
    Preparatomtaleavsnitt() : avsnittoverskrift(), lenke() {}
    Preparatomtaleavsnitt(const ValueWithDistinguishedName &avsnittoverskrift, const Lenke &lenke) :
            avsnittoverskrift(avsnittoverskrift), lenke(lenke) {}
    [[nodiscard]] ValueWithDistinguishedName GetAvsnittoverskrift() const;
    [[nodiscard]] Lenke GetLenke() const;
};

#endif //LEGEMFEST_PREPARATOMTALEAVSNITT_H
