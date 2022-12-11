//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_LEGEMIDDELPAKNING_H
#define LEGEMFEST_LEGEMIDDELPAKNING_H

#include "LegemiddelCore.h"
#include "Preparattype.h"


class Legemiddelpakning : public LegemiddelCore {
private:
    Preparattype preparattype;
public:
    Legemiddelpakning() : LegemiddelCore(), preparattype() {}
    Legemiddelpakning(const LegemiddelCore &legemiddelCore, const Preparattype &preparattype) : LegemiddelCore(legemiddelCore), preparattype(preparattype) {}
    [[nodiscard]] Preparattype GetPreparattype();
};

#endif //LEGEMFEST_LEGEMIDDELPAKNING_H
