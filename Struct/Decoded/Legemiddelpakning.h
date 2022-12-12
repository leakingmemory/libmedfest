//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_LEGEMIDDELPAKNING_H
#define LEGEMFEST_LEGEMIDDELPAKNING_H

#include "LegemiddelCore.h"
#include "Preparattype.h"
#include "Oppbevaring.h"
#include "Pakningsinfo.h"
#include "Markedsforingsinfo.h"


class Legemiddelpakning : public LegemiddelCore {
private:
    Preparattype preparattype;
    std::string varenr;
    Oppbevaring oppbevaring;
    Pakningsinfo pakningsinfo;
    Markedsforingsinfo markedsforingsinfo;
    std::string ean;
public:
    Legemiddelpakning() : LegemiddelCore(), preparattype(), varenr(), oppbevaring(), pakningsinfo(),
            markedsforingsinfo(), ean() {}
    Legemiddelpakning(const LegemiddelCore &legemiddelCore, const Preparattype &preparattype, const std::string &varenr,
                      const Oppbevaring &oppbevaring, const Pakningsinfo &pakningsinfo,
                      const Markedsforingsinfo &markedsforingsinfo, const std::string &ean) :
            LegemiddelCore(legemiddelCore), preparattype(preparattype), varenr(varenr), oppbevaring(oppbevaring),
            pakningsinfo(pakningsinfo), markedsforingsinfo(markedsforingsinfo), ean(ean) {}
    [[nodiscard]] Preparattype GetPreparattype() const;
    [[nodiscard]] std::string GetVarenr() const;
    [[nodiscard]] Oppbevaring GetOppbevaring() const;
    [[nodiscard]] Markedsforingsinfo GetMarkedsforingsinfo() const;
    [[nodiscard]] std::string GetEan() const;
};

#endif //LEGEMFEST_LEGEMIDDELPAKNING_H