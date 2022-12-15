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
#include "PakningByttegruppe.h"
#include "Preparatomtaleavsnitt.h"


class Legemiddelpakning : public LegemiddelCore {
private:
    Preparattype preparattype;
    std::string varenr;
    Oppbevaring oppbevaring;
    std::vector<Pakningsinfo> pakningsinfo;
    Markedsforingsinfo markedsforingsinfo;
    std::string ean;
    std::vector<PrisVare> prisVare;
    Refusjon refusjon;
    PakningByttegruppe pakningByttegruppe;
    Preparatomtaleavsnitt preparatomtaleavsnitt;
    bool ikkeKonservering;
public:
    Legemiddelpakning() : LegemiddelCore(), preparattype(), varenr(), oppbevaring(), pakningsinfo(),
            markedsforingsinfo(), ean(), prisVare(), refusjon(), pakningByttegruppe(), preparatomtaleavsnitt(),
            ikkeKonservering(false) {}
    Legemiddelpakning(const LegemiddelCore &legemiddelCore, const Preparattype &preparattype, const std::string &varenr,
                      const Oppbevaring &oppbevaring, const std::vector<Pakningsinfo> &pakningsinfo,
                      const Markedsforingsinfo &markedsforingsinfo, const std::string &ean,
                      const std::vector<PrisVare> &prisVare, const Refusjon &refusjon,
                      const PakningByttegruppe &pakningByttegruppe, const Preparatomtaleavsnitt &preparatomtaleavsnitt,
                      bool ikkeKonservering) :
            LegemiddelCore(legemiddelCore), preparattype(preparattype), varenr(varenr), oppbevaring(oppbevaring),
            pakningsinfo(pakningsinfo), markedsforingsinfo(markedsforingsinfo), ean(ean), prisVare(prisVare),
            refusjon(refusjon), pakningByttegruppe(pakningByttegruppe), preparatomtaleavsnitt(preparatomtaleavsnitt),
            ikkeKonservering(ikkeKonservering) {}
    [[nodiscard]] Preparattype GetPreparattype() const;
    [[nodiscard]] std::string GetVarenr() const;
    [[nodiscard]] Oppbevaring GetOppbevaring() const;
    [[nodiscard]] std::vector<Pakningsinfo> GetPakningsinfo() const;
    [[nodiscard]] Markedsforingsinfo GetMarkedsforingsinfo() const;
    [[nodiscard]] std::string GetEan() const;
    [[nodiscard]] std::vector<PrisVare> GetPrisVare() const;
    [[nodiscard]] Refusjon GetRefusjon() const;
    [[nodiscard]] PakningByttegruppe GetPakningByttegruppe() const;
    [[nodiscard]] Preparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
    [[nodiscard]] bool GetIkkeKonservering() const;
};

#endif //LEGEMFEST_LEGEMIDDELPAKNING_H
