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
#include "PrisVare.h"
#include "Pakningskomponent.h"
#include "Refusjon.h"


class Legemiddelpakning : public LegemiddelCore {
private:
    Preparattype preparattype;
    std::string varenr;
    Oppbevaring oppbevaring;
    Pakningsinfo pakningsinfo;
    Markedsforingsinfo markedsforingsinfo;
    std::string ean;
    std::vector<PrisVare> prisVare;
    Refusjon refusjon;
public:
    Legemiddelpakning() : LegemiddelCore(), preparattype(), varenr(), oppbevaring(), pakningsinfo(),
            markedsforingsinfo(), ean(), prisVare(), refusjon() {}
    Legemiddelpakning(const LegemiddelCore &legemiddelCore, const Preparattype &preparattype, const std::string &varenr,
                      const Oppbevaring &oppbevaring, const Pakningsinfo &pakningsinfo,
                      const Markedsforingsinfo &markedsforingsinfo, const std::string &ean,
                      const std::vector<PrisVare> &prisVare, const Refusjon &refusjon) :
            LegemiddelCore(legemiddelCore), preparattype(preparattype), varenr(varenr), oppbevaring(oppbevaring),
            pakningsinfo(pakningsinfo), markedsforingsinfo(markedsforingsinfo), ean(ean), prisVare(prisVare),
            refusjon(refusjon) {}
    [[nodiscard]] Preparattype GetPreparattype() const;
    [[nodiscard]] std::string GetVarenr() const;
    [[nodiscard]] Oppbevaring GetOppbevaring() const;
    [[nodiscard]] Markedsforingsinfo GetMarkedsforingsinfo() const;
    [[nodiscard]] std::string GetEan() const;
    [[nodiscard]] std::vector<PrisVare> GetPrisVare() const;
    [[nodiscard]] Refusjon GetRefusjon() const;
};

#endif //LEGEMFEST_LEGEMIDDELPAKNING_H
