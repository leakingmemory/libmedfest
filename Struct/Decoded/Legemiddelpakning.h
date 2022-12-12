//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_LEGEMIDDELPAKNING_H
#define LEGEMFEST_LEGEMIDDELPAKNING_H

#include "LegemiddelCore.h"
#include "Preparattype.h"
#include "Oppbevaring.h"
#include "Pakningsinfo.h"


class Legemiddelpakning : public LegemiddelCore {
private:
    Preparattype preparattype;
    std::string varenr;
    Oppbevaring oppbevaring;
    Pakningsinfo pakningsinfo;
public:
    Legemiddelpakning() : LegemiddelCore(), preparattype(), varenr(), oppbevaring(), pakningsinfo() {}
    Legemiddelpakning(const LegemiddelCore &legemiddelCore, const Preparattype &preparattype, const std::string &varenr,
                      const Oppbevaring &oppbevaring, const Pakningsinfo &pakningsinfo) :
            LegemiddelCore(legemiddelCore), preparattype(preparattype), varenr(varenr), oppbevaring(oppbevaring),
            pakningsinfo(pakningsinfo) {}
    [[nodiscard]] Preparattype GetPreparattype() const;
    [[nodiscard]] std::string GetVarenr() const;
    [[nodiscard]] Oppbevaring GetOppbevaring() const;
};

#endif //LEGEMFEST_LEGEMIDDELPAKNING_H
