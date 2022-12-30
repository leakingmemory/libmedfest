//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_INTERAKSJONIKKEVURDERT_H
#define LEGEMFEST_INTERAKSJONIKKEVURDERT_H

#include "Atc.h"

class InteraksjonIkkeVurdert {
private:
    Atc atc;
public:
    InteraksjonIkkeVurdert() : atc() {}
    InteraksjonIkkeVurdert(const Atc &atc) : atc(atc) {}
    [[nodiscard]] Atc GetAtc() const;
};


#endif //LEGEMFEST_INTERAKSJONIKKEVURDERT_H
