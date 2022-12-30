//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_OPPFINTERAKSJONIKKEVURDERT_H
#define LEGEMFEST_OPPFINTERAKSJONIKKEVURDERT_H

#include "OppfInteraksjonBase.h"
#include "InteraksjonIkkeVurdert.h"

class OppfInteraksjonIkkeVurdert : public OppfInteraksjonBase {
private:
    InteraksjonIkkeVurdert interaksjonIkkeVurdert;
public:
    OppfInteraksjonIkkeVurdert() : OppfInteraksjonBase(), interaksjonIkkeVurdert() {}
    OppfInteraksjonIkkeVurdert(const OppfInteraksjonBase &interaksjonBase,
                               const InteraksjonIkkeVurdert &interaksjonIkkeVurdert) :
            OppfInteraksjonBase(interaksjonBase), interaksjonIkkeVurdert(interaksjonIkkeVurdert) {}
    [[nodiscard]] InteraksjonIkkeVurdert GetInteraksjonIkkeVurdert() const;
};


#endif //LEGEMFEST_OPPFINTERAKSJONIKKEVURDERT_H
